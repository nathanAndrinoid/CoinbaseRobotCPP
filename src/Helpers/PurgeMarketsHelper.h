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
		static void Purge(std::vector<Coin*> &coins, int marketCount, std::unordered_map<int, void*> &marketDict, std::unordered_map<std::wstring, void*> &marketRateDict, std::unordered_map<int, void*> &coinDict);
	};
}
