#pragma once

#include "CoinPathTest0.h"
#include "CoinPathTest1.h"
#include "CoinPathTest2.h"
#include "CoinPathTest3.h"
#include "CoinPathTest4.h"
#include "AuditLevelPath.h"
#include "Coin.h"
#include "MarketData.h"
#include "PathStep.h"
#include "MarketPair.h"
#include "MarketRate.h"
#include "MapValue.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <any>

using namespace App1::Models;
using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	class CoinTest
	{
	private:
		CoinPathTest0 *cpt0;
		CoinPathTest1 *cpt1;
		CoinPathTest2 *cpt2;
		CoinPathTest3 *cpt3;
		CoinPathTest4 *cpt4;
		AuditLevelPath *alp;
	public:
		Task *pathWorker;
	private:
		double fee = 0.0005;
	public:
		Coin *indexCoin;
		Coin *indexUSD;
	private:
		MarketData *marketData;
		std::unordered_map<int, Coin*> coinDict;
		std::unordered_map<int, PathStep*> stepBestDict0;
		std::unordered_map<int, PathStep*> stepBestDict1;
		std::unordered_map<int, PathStep*> stepBestDict2;
		std::unordered_map<int, PathStep*> stepBestDict3;
		std::unordered_map<int, PathStep*> stepBestDict4;
		std::unordered_map<std::wstring, MarketPair*> marketPairDict;
		std::vector<MarketPair*> marketPairArray;
		std::vector<Coin*> coinArray;
		std::vector<MarketRate*> marketRates;
		int marketCount = 0;
		std::vector<std::vector<Coin*>> dolarBestLinks;
		std::vector<double> dollarBestValues;
		MapValue *dValueMap;
		MapValue *dvChangeMap;
	public:
		bool lastTradeAccomplished = false;
	private:
		int iBestIndex = 0;
		Coin *cBest = nullptr;
		int bestLength = 0;
		std::any coinLock = std::any();

	public:
		virtual ~CoinTest()
		{
			delete cpt0;
			delete cpt1;
			delete cpt2;
			delete cpt3;
			delete cpt4;
			delete alp;
			delete pathWorker;
			delete indexCoin;
			delete indexUSD;
			delete marketData;
			delete dValueMap;
			delete dvChangeMap;
			delete cBest;
		}

		CoinTest(Coin *lc, bool independant = false);

	};
}
