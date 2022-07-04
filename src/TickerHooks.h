#pragma once

#include "Models/MarketData.h"
#include "Models/MarketRate.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::TickerHooks
{
	class TickerHooks
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

		static ManualResetEvent *const ExitEvent;

	public:
		virtual ~TickerHooks()
		{
			delete _marketData;
		}

		TickerHooks();

	};
}
