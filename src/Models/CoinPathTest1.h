#pragma once

#include "Coin.h"
#include "MarketRate.h"
#include "PathStep.h"
#include <unordered_map>
#include <vector>

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	class CoinPathTest1
	{

	public:
		void BuildBestPathToCoinMarket1(Coin *cEnd, double fee, std::vector<MarketRate*> &marketRates, std::unordered_map<int, PathStep*> &stepBestDict0, std::unordered_map<int, PathStep*> &stepBestDict1);

	};
}
