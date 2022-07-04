#include "PurgeMarketsHelper.h"

using namespace Robot::Common::Models;

namespace Robot::Common::Helpers
{

	std::vector<MarketPair*> PurgeMarketsHelper::Purge(std::vector<Coin*> &coins, int marketCount, std::unordered_map<int, MarketPair*> &marketDict, std::unordered_map<std::wstring, MarketRate*> &marketRateDict, std::unordered_map<int, Coin*> &coinDict)
	{

		std::unordered_map<int, MarketPair*> newMarketDictionary;
		std::vector<Coin*> newCoins;

		for (auto coin : coins)
		{
			int count = 0;
			MarketPair *market = new MarketPair();
			bool wasQuote = false;

			for (auto mp : *coin->QuoteMarkets)
			{
				++count;
				market = mp;
				wasQuote = true;
			}

			for (auto mp : *coin->BaseMarkets)
			{
				++count;
				market = mp;
			}

			if (count == 1)
			{
				if (wasQuote)
				{
					market->BaseCurrency->BaseMarkets.Remove(market);
				}
				else
				{
					market->QuoteCurrency->QuoteMarkets.Remove(market);
				}
				--marketCount;
				marketDict.erase(market->Index);
				marketRateDict.erase(market->Symbol);
				coinDict.erase(coin->Id);

			}
			else
			{
				newCoins.push_back(coin);
			}

//C# TO C++ CONVERTER TODO TASK: A 'delete market' statement was not added since market was passed to a method or constructor. Handle memory management manually.
		}

		coins = newCoins;

		int newMarketIndex = 0;

		for (auto mp : marketDict.OrderBy([&] (std::any md)
		{
			md::Key;
		}))
		{
			MarketPair *changedMP = mp->Value;
			changedMP->Index = newMarketIndex;
			newMarketDictionary.emplace(newMarketIndex, changedMP);

			++newMarketIndex;
		}

		marketDict = newMarketDictionary; //.OrderBy(md => md.Key).ToDictionary<int,MarketPair>();

		return std::vector<MarketPair*>(marketDict.size());

	}
}
