#include "TickerHooks.h"

using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::TickerHooks
{

MemoryMappedViewAccessor *TickerHooks::_startAccessor;
ManualResetEvent *const TickerHooks::ExitEvent = new ManualResetEvent(false);

	TickerHooks::TickerHooks()
	{

		appStartTime = DateTime::Now;
		_marketIndexDict = std::unordered_map<std::wstring, long long>();
		_marketData = new MarketData();
		_marketData->ConfigureMarketRateStorage(L"marketData", MemoryMappedFileAccess::ReadWrite);
		_marketData->LoadMarketDataToMap();
		marketCount = _marketData->MarketPairArray.size();

		//_startAccessor = MarketRate.ConfigureMarketRateStorage("marketRates", marketCount, MemoryMappedFileAccess.ReadWrite);
		_marketRates = std::vector<MarketRate*>(marketCount);

		for (long long i = 0; i < marketCount; ++i)
		{
			_marketRates[i] = new MarketRate();
			_marketRates[i]->ReadMarketRate(_startAccessor, i);
			_marketRates[i]->lastMarketUpdate = DateTime::MinValue;
		}

		_marketRateUpdates = std::vector<DateTime>(_marketRates.size());

		for (int i = 0; i < _marketRates.size(); i++)
		{
			_marketRateUpdates[i] = DateTime::MinValue;
		}

		auto random = new Random();
		//_accessors = new MemoryMappedViewAccessor[_marketData.MarketPairArray.Length];
		marketStrArray = std::vector<std::wstring>();

		for (auto mp : *_marketData->MarketPairArray)
		{
			marketStrArray.push_back(mp->Symbol);
			_marketIndexDict.emplace(mp->Symbol, mp->Index);

		}

		delete random;
	}
}
