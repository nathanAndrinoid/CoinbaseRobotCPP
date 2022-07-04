export module LoadCoinsAndMarketsHelper;

import Coin;
import MarketData;
import MarketPair;
import PathStep;
import <string>;
import <unordered_map>;
import <vector>;
import <algorithm>;

using namespace Robot::Common::Models;

namespace Robot::Common::Helpers
{
	export class LoadCoinsAndMarketsHelper final
	{

	public:
		static Coin *LoadCoinAndMarketLists(MarketData *marketData, std::unordered_map<std::wstring, MarketPair*> &marketPairDict, std::vector<MarketPair*> &marketPairArray, std::unordered_map<int, Coin*> &coinDict, std::vector<Coin*> &coinArray)
		{
			for (auto mp : *marketData->MarketPairArray)
			{
				marketPairDict.emplace(mp->Symbol, mp);
				marketPairArray[mp->Index] = mp;

				if (mp->BaseCurrency->BaseMarkets.empty())
				{
					mp->BaseCurrency->BaseMarkets = std::vector<MarketPair*>();
				}

				if (mp->BaseCurrency->QuoteMarkets.empty())
				{
					mp->BaseCurrency->QuoteMarkets = std::vector<MarketPair*>();
				}

				if (mp->QuoteCurrency->BaseMarkets.empty())
				{
					mp->QuoteCurrency->BaseMarkets = std::vector<MarketPair*>();
				}

				if (mp->QuoteCurrency->QuoteMarkets.empty())
				{
					mp->QuoteCurrency->QuoteMarkets = std::vector<MarketPair*>();
				}

				if (coinDict.find(mp->BaseCurrency->Id) == coinDict.end())
				{
					mp->BaseCurrency->pathStep = new PathStep();
					mp->BaseCurrency->pathStep->coin = mp->BaseCurrency;
					coinDict.emplace(mp->BaseCurrency->Id, mp->BaseCurrency);
				}

				if (!std::find(mp->BaseCurrency->BaseMarkets.begin(), mp->BaseCurrency->BaseMarkets.end(), mp) != mp->BaseCurrency->BaseMarkets.end())
				{
					mp->BaseCurrency->BaseMarkets.push_back(mp);
				}

				if (coinDict.find(mp->QuoteCurrency->Id) == coinDict.end())
				{
					mp->QuoteCurrency->pathStep = new PathStep();
					mp->QuoteCurrency->pathStep->coin = mp->QuoteCurrency;
					coinDict.emplace(mp->QuoteCurrency->Id, mp->QuoteCurrency);
				}

				if (!std::find(mp->QuoteCurrency->QuoteMarkets.begin(), mp->QuoteCurrency->QuoteMarkets.end(), mp) != mp->QuoteCurrency->QuoteMarkets.end())
				{
					mp->QuoteCurrency->QuoteMarkets.push_back(mp);
				}
			}

			int index = 0;
			coinArray = std::vector<Coin*>(coinDict.size());
			Coin *indexUSD = nullptr;

			for (auto coin : coinDict)
			{
				coin->second->bestLinks = std::vector<std::vector<PathStep*>>(5);
				coin->second.bestLinks[0] = std::vector<PathStep*>(2);
				coin->second.bestLinks[0][0] = new PathStep();
				coin->second.bestLinks[0][1] = coin->second.pathStep;
				coin->second.bestLinks[1] = std::vector<PathStep*>(3);
				coin->second.bestLinks[1][0] = new PathStep();
				coin->second.bestLinks[1][1] = new PathStep();
				coin->second.bestLinks[1][2] = coin->second.pathStep;
				coin->second.bestLinks[2] = std::vector<PathStep*>(4);
				coin->second.bestLinks[2][0] = new PathStep();
				coin->second.bestLinks[2][1] = new PathStep();
				coin->second.bestLinks[2][2] = new PathStep();
				coin->second.bestLinks[2][3] = coin->second.pathStep;
				coin->second.bestLinks[3] = std::vector<PathStep*>(5);
				coin->second.bestLinks[3][0] = new PathStep();
				coin->second.bestLinks[3][1] = new PathStep();
				coin->second.bestLinks[3][2] = new PathStep();
				coin->second.bestLinks[3][3] = new PathStep();
				coin->second.bestLinks[3][4] = coin->second.pathStep;
				coin->second.bestLinks[4] = std::vector<PathStep*>(6);
				coin->second.bestLinks[4][0] = new PathStep();
				coin->second.bestLinks[4][1] = new PathStep();
				coin->second.bestLinks[4][2] = new PathStep();
				coin->second.bestLinks[4][3] = new PathStep();
				coin->second.bestLinks[4][4] = new PathStep();
				coin->second.bestLinks[4][5] = coin->second.pathStep;
				coin->second->bestValues = std::vector<double>(5);

				if (coin->second->Symbol == L"USD")
				{
					indexUSD = new Coin(coin->second);
				}

				coinArray[index] = coin->second;
				++index;
			}

//C# TO C++ CONVERTER TODO TASK: A 'delete indexUSD' statement was not added since indexUSD was used in a 'return' or 'throw' statement.
			return indexUSD;
		}
	};
}
