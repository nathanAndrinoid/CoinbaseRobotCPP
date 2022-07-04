#pragma once

#include "Coin.h"
#include "MarketRate.h"
#include "PathStep.h"
#include <unordered_map>
#include <vector>

using namespace Robot::Common::Models;


namespace Robot::Common::Models
{
	class CoinPathTest3
	{

	public:
		void BuildBestPathToCoinMarket3(Coin *cEnd, double fee, std::vector<MarketRate*> &marketRates, std::unordered_map<int, PathStep*> &stepBestDict0, std::unordered_map<int, PathStep*> &stepBestDict1, std::unordered_map<int, PathStep*> &stepBestDict2, std::unordered_map<int, PathStep*> &stepBestDict3);

	};
}
