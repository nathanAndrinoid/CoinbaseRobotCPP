#pragma once

#include "Coin.h"
#include "MarketPair.h"

//using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	class PathStep
	{
	public:
		void *coin;
		void *pair;
		void *fromCoin;
		int Side = 0;
		double Price = 0;
		double value = 0;
		virtual ~PathStep()
		{
			// delete coin;
			// delete pair;
			// delete fromCoin;
		}

	};
}
