export module TickerHooks;

import MarketData;
import MarketRate;
import <string>;
import <unordered_map>;
import <vector>;

using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::TickerHooks
{
	export class TickerHooks
	{
		//private static MemoryMappedViewAccessor?[] _accessors;
	private:
		static MemoryMappedViewAccessor *_startAccessor;
		MarketData *_marketData;
		std::unordered_map<std::wstring, long long> _marketIndexDict;
		std::vector<MarketRate*> _marketRates;
		std::vector<DateTime> _marketRateUpdates;
		bool Running = false;
		bool firstTickerCheckRound = false;
		bool tickerCheckRunning = false;
		int iTickerSub = 0;
		DateTime appStartTime;
		int marketCount = 0;
		std::vector<std::wstring> marketStrArray;

//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static ManualResetEvent *const ExitEvent = new ManualResetEvent(false);

	public:
		virtual ~TickerHooks()
		{
			delete _marketData;
		}

		TickerHooks()
		{

			appStartTime = DateTime::Now;
			_marketIndexDict = std::unordered_map<std::wstring, long long>();
			_marketData = new MarketData();
			_marketData->ConfigureMarketRateStorage(L"marketData", MemoryMappedFileAccess::ReadWrite);
			_marketData->LoadMarketDataToMap();
			marketCount = _marketData->MarketPairArray.size();

			_startAccessor = MarketRate::ConfigureMarketRateStorage(L"marketRates", marketCount, MemoryMappedFileAccess::ReadWrite);
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

	};
}
