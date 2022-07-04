#pragma once

#include "Models/MarketRate.h"
#include "Models/MarketRateState.h"
#include "Models/Coin.h"
#include "Models/MarketPair.h"
#include "Models/MapValue.h"
#include "Models/MarketData.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace Robot::Common::Models;

namespace CoinbaseRobotTranlator
{
	class CoinbaseRobotCpp
	{
	private:
		int marketCount = 0;
		bool Running = false;
		DateTime appStartTime;
		CancellationTokenSource *tokenSource;
		CancellationToken ct;
		std::unordered_map<std::wstring, MarketRate*> marketRateDict;
		MarketRateState *marketRateState;
		std::vector<Coin*> coins;
		std::unordered_map<int, Coin*> coinDict;
		std::unordered_map<int, Coin*> tempCoinDict;
		std::unordered_map<int, MarketPair*> marketDict;
		std::vector<MarketPair*> marketPairArray;
		BinaryFormatter *binaryFormatter;
		MapValue *dValueMap;
		std::vector<MarketRate*> marketRates;
		MarketData *marketData;
		std::vector<Coin*> coinArray;
		static ManualResetEvent *const ExitEvent;

		static const std::wstring API_KEY;
		static const std::wstring API_SECRET;
		static const std::wstring API_PASSPHRASE;

	public:
		virtual ~CoinbaseRobotCpp()
		{
			delete tokenSource;
			delete marketRateState;
			delete binaryFormatter;
			delete dValueMap;
			delete marketData;
		}

		CoinbaseRobotCpp();
	};
}
