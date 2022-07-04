#pragma once

#include "Models/MarketData.h"
#include "Models/CoinTest.h"
#include "Models/Coin.h"
#include "Models/MarketPair.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <any>

using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::PathFinder
{
	class PathFinder
	{
	private:
		MemoryMappedViewAccessor *startAccessor;
		MarketData *marketData;
		DateTime lastTime;
		std::vector<CoinTest*> coinTests;
		std::unordered_map<int, Coin*> coinDict;
		std::vector<Coin*> coinArray;
		Coin *indexUSD;
		std::unordered_map<std::wstring, MarketPair*> marketPairDict;
		std::vector<MarketPair*> marketPairArray;
		int marketCount = 0;
		CoinTest *rateChangeTest;
		std::vector<double> dollarChangeRates;
	public:
		DateTime appStartTime;
	private:
		bool Running = false;
	public:
		int CoinCount = 0;
	private:
		std::unordered_map<int, int> indexMap;
		std::any pathControl;

	public:
		virtual ~PathFinder()
		{
			delete startAccessor;
			delete marketData;
			delete indexUSD;
			delete rateChangeTest;
		}

		PathFinder();

	private:
		void LoadCoinAndMarketLists();
	};
}
