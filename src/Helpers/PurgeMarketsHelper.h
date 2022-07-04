#pragma once

#include "../Models/Coin.h"
#include "../Models/MarketPair.h"
#include "../Models/MarketRate.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace Robot::Common::Models;

namespace Robot::Common::Helpers
{
	class PurgeMarketsHelper final
	{
	public:
		static std::vector<MarketPair*> Purge(std::vector<Coin*> &coins, int marketCount, std::unordered_map<int, MarketPair*> &marketDict, std::unordered_map<std::wstring, MarketRate*> &marketRateDict, std::unordered_map<int, Coin*> &coinDict);
	};
}
