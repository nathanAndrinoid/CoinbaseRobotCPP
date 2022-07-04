#include "PurgeMarketsHelper.h"
#include<bits/stdc++.h>

using namespace Robot::Common::Models;

namespace Robot::Common::Helpers
{

	void PurgeMarketsHelper::Purge(std::vector<Coin*> &coins, int marketCount, std::unordered_map<int, void*> &marketDict, std::unordered_map<std::wstring, void*> &marketRateDict, std::unordered_map<int, void*> &coinDict)
	{

// 		std::unordered_map<int, void*> newMarketDictionary;
// 		std::vector<Coin*> newCoins;
//
// 		for (auto coin : coins)
// 		{
// 			int count = 0;
// 			MarketPair *market = new MarketPair();
// 			bool wasQuote = false;
//
// 			for (auto mp : ((Coin*)coin)->QuoteMarkets)
// 			{
// 				++count;
// 				//market = mp;
// 				wasQuote = true;
// 			}
//
// 			for (auto mp : ((Coin*)coin)->BaseMarkets)
// 			{
// 				++count;
// 				//market = mp;
// 			}
//
// 			if (count == 1)
// 			{
// 				// if (wasQuote)
// 				// {
// 				// 	auto bml = ((Coin*)((MarketPair*)market)->BaseCurrency)->BaseMarkets;
// 				// 	std::remove(&market);
// 				// }
// 				// else
// 				// {
// 				// 	auto qml = ((Coin*)((MarketPair*)market)->QuoteCurrency)->QuoteMarkets;
// 				// 	std::remove(&market);
// 				// }
// 				--marketCount;
// 				// marketDict.erase(market->Index);
// 				// marketRateDict.erase(market->Symbol);
// 				// coinDict.erase(coin->Id);
//
// 			}
// 			else
// 			{
// 				newCoins.push_back(coin);
// 			}
//
// //C# TO C++ CONVERTER TODO TASK: A 'delete market' statement was not added since market was passed to a method or constructor. Handle memory management manually.
// 		}
//
// 		coins = newCoins;
//
// 		int newMarketIndex = 0;
//
// 				// for (auto mp : marketDict.OrderBy([&] (std::any md)
// 				// {
// 				// 	md::Key;
// 				// }))
// 		for (auto mp : marketDict)
// 		{
// 			MarketPair *changedMP = mp.second;
// 			changedMP->Index = newMarketIndex;
// 			newMarketDictionary.emplace(newMarketIndex, changedMP);
//
// 			++newMarketIndex;
// 		}
//
// 		marketDict = newMarketDictionary; //.OrderBy(md => md.Key).ToDictionary<int,MarketPair>();
//
// 		return std::vector<void*>(marketDict.size());

	}
}
