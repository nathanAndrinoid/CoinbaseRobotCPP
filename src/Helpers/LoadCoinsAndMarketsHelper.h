#pragma once

#include "../Models/Coin.h"
#include "../Models/MarketData.h"
#include "../Models/MarketPair.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace Robot::Common::Models;

namespace Robot::Common::Helpers
{
	class LoadCoinsAndMarketsHelper final
	{

	public:
		static Coin *LoadCoinAndMarketLists(MarketData *marketData, std::unordered_map<std::wstring, MarketPair*> &marketPairDict, std::vector<MarketPair*> &marketPairArray, std::unordered_map<int, Coin*> &coinDict, std::vector<Coin*> &coinArray);
	};
}
