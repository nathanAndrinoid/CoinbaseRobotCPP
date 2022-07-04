#pragma once

#include "MarketPair.h"
#include "PathStep.h"
#include <string>
#include <vector>
#include <stdexcept>

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	class Coin
	{
	public:
		int Id = 0;
		std::wstring Symbol;
		double minSize = 0;
		std::vector<void*> QuoteMarkets;
		std::vector<void*> BaseMarkets;

		void *pathStep;
		double dollarValue = 0.0;
		double nativeValue0 = 0.0;
		double nativeValue1 = 0.0;
		double nativeValue2 = 0.0;
		double nativeValue3 = 0.0;
		double nativeValue4 = 0.0;
		double nativeValue5 = 0.0;
		//std::vector<std::vector<PathStep*>> bestLinks;
		std::vector<double> bestValues;
		double Balance = 0;
		double rateChange = 0;
		double BalanceInDollars = 0;

		virtual ~Coin()
		{
			//delete (PathStep*)pathStep;
		}

		Coin();
		Coin(Coin *sourceCoin, bool deepClone = false);//, std::vector<MarketPair*> &marketPairs = std::vector<MarketPair*>());

		void CopyIn(Coin *sourceCoin);
	};
}
