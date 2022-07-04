// ﻿#include "CoinTest.h"
// #include "../Helpers/LoadCoinsAndMarketsHelper.h"
//
// using namespace Robot::Common::Helpers;
// using namespace Robot::Common::Models;
//
// namespace Robot::Common::Models
// {
//
// 	CoinTest::CoinTest(Coin *lc, bool independant)
// 	{
// 		// cpt0 = new CoinPathTest0();
// 		// cpt1 = new CoinPathTest1();
// 		// cpt2 = new CoinPathTest2();
// 		// cpt3 = new CoinPathTest3();
// 		// cpt4 = new CoinPathTest4();
// 		// dolarBestLinks = std::vector<std::vector<Coin*>>(2);
// 		// dolarBestLinks[0] = std::vector<Coin*>(1);
// 		// dolarBestLinks[1] = std::vector<Coin*>(2);
// 		// dollarBestValues = std::vector<double>(2);
// 		//
// 		// coinDict = std::unordered_map<int, Coin*>();
// 		// stepBestDict0 = std::unordered_map<int, PathStep*>();
// 		// stepBestDict1 = std::unordered_map<int, PathStep*>();
// 		// stepBestDict2 = std::unordered_map<int, PathStep*>();
// 		// stepBestDict3 = std::unordered_map<int, PathStep*>();
// 		// stepBestDict4 = std::unordered_map<int, PathStep*>();
// 		// marketPairDict = std::unordered_map<std::wstring, MarketPair*>();
// 		//
// 		// marketData = new MarketData();
// 		// marketData->ConfigureMarketRateStorage(L"marketData", MemoryMappedFileAccess::ReadWrite);
// 		// marketData->LoadMarketDataToMap();
// 		// marketCount = marketData->MarketPairArray.size();
// 		// marketPairArray = std::vector<MarketPair*>(marketCount);
// 		// indexUSD = LoadCoinsAndMarketsHelper::LoadCoinAndMarketLists(marketData, marketPairDict, marketPairArray, coinDict, coinArray);
// 		//
// 		// if (independant)
// 		// {
// 		// 	dValueMap = new MapValue(L"dollarValue", coinArray.size(), 16);
// 		// 	dValueMap->SetIdToIndexMap(coinArray, 16);
// 		// 	dvChangeMap = new MapValue(L"dollarValueChangeRate", coinArray.size(), 16);
// 		// 	dvChangeMap->SetIdToIndexMap(coinArray, 16);
// 		// }
// 		//
// 		// indexCoin = coinDict[lc->Id];
// 		//
// 		// for (auto coin : coinArray)
// 		// {
// 		// 	// PathStep tempVar();
// 		// 	// stepBestDict0.emplace(coin->Id, &tempVar);
// 		// 	// PathStep tempVar2();
// 		// 	// stepBestDict1.emplace(coin->Id, &tempVar2);
// 		// 	// PathStep tempVar3();
// 		// 	// stepBestDict2.emplace(coin->Id, &tempVar3);
// 		// 	// PathStep tempVar4();
// 		// 	// stepBestDict3.emplace(coin->Id, &tempVar4);
// 		// 	// PathStep tempVar5();
// 		// 	// stepBestDict4.emplace(coin->Id, &tempVar5);
// 		// }
// 		//
// 		// marketRates = std::vector<MarketRate*>(marketCount);
// 		//
// 		// for (long long i = 0; i < marketCount; ++i)
// 		// {
// 		// 	marketRates[i] = new MarketRate();
// 		// }
// 		// alp = new AuditLevelPath(marketPairArray, coinArray);
// 	}
// }
