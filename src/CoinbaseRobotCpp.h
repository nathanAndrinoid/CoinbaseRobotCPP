#pragma once

// #include "Models/MarketRate.h"
// #include "Models/MarketRateState.h"
// #include "Models/Coin.h"
// #include "Models/MarketPair.h"
// #include "Models/MapValue.h"
// #include "Models/MarketData.h"
#include <string>
#include <unordered_map>
#include <vector>

// using namespace Robot::Common::Helpers;
// using namespace Robot::Common::Models;

namespace Robot::CoinbaseCpp
{
	class CoinbaseRobotCpp
	{
	private:
		int marketCount = 0;
		bool Running = false;
		time_t appStartTime;
		//CancellationTokenSource *tokenSource;
		//CancellationToken ct;
		//std::unordered_map<std::wstring, MarketRate*> marketRateDict;
		//MarketRateState *marketRateState;
		//std::vector<Coin*> coins;
		//std::unordered_map<int, Coin*> coinDict;
		//std::unordered_map<int, MarketPair*> marketDict;
		//std::vector<MarketPair*> marketPairArray;
		//BinaryFormatter *binaryFormatter;
		//MapValue *dValueMap;
		//std::vector<MarketRate*> marketRates;
		//MarketData *marketData;
		//std::vector<Coin*> coinArray;

		const std::wstring API_KEY = L"2e506aa3ec83fb4164e50b79ff0a7fd4";
		const std::wstring API_SECRET = L"YN3Zf9zH+zdi53MiKBmjWq267/j+BZQkVt/RXUNyTW+jj2TzT5m58XgTuH1LAvzApvQeaOPkZ7aOhu5WkS828A==";
		const std::wstring API_PASSPHRASE = L"tzi4cbvjyt";

	public:
		virtual ~CoinbaseRobotCpp()
		{
			// delete tokenSource;
			// delete marketRateState;
			// delete binaryFormatter;
			// delete dValueMap;
			// delete marketData;
		}

		CoinbaseRobotCpp();

	private:
		// void InitMarketRates();
		//
		// std::vector<Coin*> LoadCoinAndMarketLists(MarketData* marketData, std::vector<MarketPair*>& marketPairArray);
		//
		// void CreateLinkedCoinsAndMarketPair(const std::wstring& marketSymbol, int marketIndex, Product* item); //, int precision)
		//
		// int CountDecimalDigits(Decimal n);
		//
		// Coin* FindOrCreateCoin(const std::wstring& coinSymbol, std::unordered_map<int, Coin*>& coinDict, std::vector<Coin*>& coins);

	};
}
