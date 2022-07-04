export module PathFinder;

import MarketData;
import CoinTest;
import Coin;
import MarketPair;
import MarketRate;
import SavePathStep;
import CoinBalances;
import <string>;
import <unordered_map>;
import <vector>;
import <algorithm>;
import <any>;

using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::PathFinder
{
	export class PathFinder
	{
	private:
		MemoryMappedViewAccessor *startAccessor;
		MarketData *marketData;
		DateTime lastTime;
		std::vector<CoinTest*> coinTests;
		std::unordered_map<int, Coin*> coinDict;
		std::vector<Coin*> coinArray;
		Coin *indexUSD;
		std::unordered_map<std::wstring, MarketPair*> marketPairDict;
		std::vector<MarketPair*> marketPairArray;
		int marketCount = 0;
		CoinTest *rateChangeTest;
		std::vector<double> dollarChangeRates;
	public:
		DateTime appStartTime;
	private:
		bool Running = false;
	public:
		int CoinCount = 0;
	private:
		std::unordered_map<int, int> indexMap;
		std::any pathControl;

	public:
		virtual ~PathFinder()
		{
			delete startAccessor;
			delete marketData;
			delete indexUSD;
			delete rateChangeTest;
		}

		PathFinder()
		{
			coinDict = std::unordered_map<int, Coin*>();
			marketPairDict = std::unordered_map<std::wstring, MarketPair*>();
			lastTime = DateTime::Now;
			marketData = new MarketData();
			marketData->ConfigureMarketRateStorage(L"marketData", MemoryMappedFileAccess::ReadWrite);
			marketData->LoadMarketDataToMap();
			marketCount = marketData->MarketPairArray.size();
			marketPairArray = std::vector<MarketPair*>(marketCount);
			LoadCoinAndMarketLists();
			double dollar = 1.0;
			CoinCount = coinArray.size();

			startAccessor = MarketRate::ConfigureMarketRateStorage(L"marketRates", marketCount, MemoryMappedFileAccess::ReadWrite);

			coinTests = std::vector<CoinTest*>(coinArray.size());
			delay(2000);
			//rateChangeTest.FindDollarValues();

			indexMap = std::unordered_map<int, int>();

			pathControl = std::any();
			SavePathStep::Init(pathControl);

			for (int i = 0; i < coinArray.size(); i++)
			{
				indexMap.emplace(coinArray[i]->Id, i);
				coinTests[i] = new CoinTest(coinArray[i], false);
			}
			//OrderHelper.OrderHelperInit(marketPairArray, coinArray, coinBalances);

			CoinBalances::InitCoinBalances(L"coinBalances", coinArray.size(), indexMap, coinArray);
		}

	private:
		void LoadCoinAndMarketLists()
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
					coinDict.emplace(mp->BaseCurrency->Id, mp->BaseCurrency);
				}

				if (!std::find(mp->BaseCurrency->BaseMarkets.begin(), mp->BaseCurrency->BaseMarkets.end(), mp) != mp->BaseCurrency->BaseMarkets.end())
				{
					mp->BaseCurrency->BaseMarkets.push_back(mp);
				}

				if (coinDict.find(mp->QuoteCurrency->Id) == coinDict.end())
				{
					coinDict.emplace(mp->QuoteCurrency->Id, mp->QuoteCurrency);
				}

				if (!std::find(mp->QuoteCurrency->QuoteMarkets.begin(), mp->QuoteCurrency->QuoteMarkets.end(), mp) != mp->QuoteCurrency->QuoteMarkets.end())
				{
					mp->QuoteCurrency->QuoteMarkets.push_back(mp);
				}
			}

			int index = 0;
			coinArray = std::vector<Coin*>(coinDict.size());
			for (auto coin : coinDict)
			{
				if (coin->second->Symbol == L"USD")
				{
					indexUSD = new Coin(coin->second);
				}
				coinArray[index] = coin->second;
				++index;
			}
		}
	};
}
