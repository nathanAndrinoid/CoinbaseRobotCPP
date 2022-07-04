export module CoinTest;

//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

import CoinPathTest0;
import CoinPathTest1;
import CoinPathTest2;
import CoinPathTest3;
import CoinPathTest4;
import AuditLevelPath;
import Coin;
import MarketData;
import PathStep;
import MarketPair;
import MarketRate;
import MapValue;
import LoadCoinsAndMarketsHelper;
import <string>;
import <unordered_map>;
import <vector>;
import <any>;

using namespace App1::Models;
using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	export class CoinTest
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

		CoinTest(Coin *lc, bool independant = false)
		{
			cpt0 = new CoinPathTest0();
			cpt1 = new CoinPathTest1();
			cpt2 = new CoinPathTest2();
			cpt3 = new CoinPathTest3();
			cpt4 = new CoinPathTest4();
			dolarBestLinks = std::vector<std::vector<Coin*>>(2);
			dolarBestLinks[0] = std::vector<Coin*>(1);
			dolarBestLinks[1] = std::vector<Coin*>(2);
			dollarBestValues = std::vector<double>(2);

			coinDict = std::unordered_map<int, Coin*>();
			stepBestDict0 = std::unordered_map<int, PathStep*>();
			stepBestDict1 = std::unordered_map<int, PathStep*>();
			stepBestDict2 = std::unordered_map<int, PathStep*>();
			stepBestDict3 = std::unordered_map<int, PathStep*>();
			stepBestDict4 = std::unordered_map<int, PathStep*>();
			marketPairDict = std::unordered_map<std::wstring, MarketPair*>();

			marketData = new MarketData();
			marketData->ConfigureMarketRateStorage(L"marketData", MemoryMappedFileAccess::ReadWrite);
			marketData->LoadMarketDataToMap();
			marketCount = marketData->MarketPairArray.size();
			marketPairArray = std::vector<MarketPair*>(marketCount);
			indexUSD = LoadCoinsAndMarketsHelper::LoadCoinAndMarketLists(marketData, marketPairDict, marketPairArray, coinDict, coinArray);

			if (independant)
			{
				dValueMap = new MapValue(L"dollarValue", coinArray.size(), 16);

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
