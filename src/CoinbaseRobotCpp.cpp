#include "CoinbaseRobotCpp.h"
#include "Helpers/PurgeMarketsHelper.h"
#include "Helpers/MarketModelSetupHelper.h"
#include "Models/CoinBalances.h"
#include "Helpers/Base26.h"

using namespace Robot::Common::Helpers;
using namespace Robot::Common::Models;

namespace Robot::CoinbaseCpp
{

	CoinbaseRobotCpp::CoinbaseRobotCpp()
	{
		appStartTime = DateTime::UtcNow;
		tokenSource = new CancellationTokenSource();
		ct = tokenSource->Token;
		marketRateDict = std::unordered_map<std::wstring, MarketRate*>();
		marketRateState = new MarketRateState();
		coins = std::vector<Coin*>();
		coinDict = std::unordered_map<int, Coin*>();
		marketDict = std::unordered_map<int, MarketPair*>();
		binaryFormatter = new BinaryFormatter();

		std::unordered_map<int, MarketPair*> newMarketDictionary;
		std::vector<Coin*> newCoins;
		
		marketCount = 0;
		std::wstring adaUSD = L"ADA-USD";

		CreateLinkedCoinsAndMarketPair(adaUSD, marketCount, nullptr);

		marketPairArray = PurgeMarketsHelper::Purge(coins, marketCount, marketDict, marketRateDict, coinDict);

		for (auto mp : marketDict)
		{
			marketPairArray[mp->Key] = mp->Value;
			marketRateDict[mp->Value->Symbol]->marketPairIndex = mp->Value->Index;
		}

		marketData = new MarketData(marketPairArray);
		marketData->ConfigureMarketRateStorage(L"marketData", MemoryMappedFileAccess::ReadWrite, true);
		marketData->SaveMarketDataToMap();
		//marketRates = new MarketRate[marketCount];

		InitMarketRates();
		coinArray = MarketModelSetupHelper::LoadCoinAndMarketLists(marketData, marketPairArray);

		dValueMap = new MapValue(L"dollarValue", coinArray.size(), 16);

		std::unordered_map<int, int> coinIdDict;

		for (int i = 0; i < coinArray.size(); i++)
		{
			coinIdDict.emplace(coinArray[i]->Id, i);
		}

		CoinBalances::InitCoinBalances(L"coinBalances", coinArray.size(), coinIdDict, coinArray);
		std::unordered_map<int, int> indexMap;
		;
		for (int i = 0; i < coinArray.size(); i++)
		{
			indexMap.emplace(coinArray[i]->Id, i);
		}

		CoinBalances::ErraseMapStorrage();

		//access = MarketRate.ConfigureMarketRateStorage("marketRates", marketCount, MemoryMappedFileAccess.ReadWrite, true);
		//access.Dispose();

		//for (int i = 0; i < marketCount; ++i)
		//{
		//    marketRates[i].SaveMarketRate(access, i);
		//}
	}

	void CoinbaseRobotCpp::InitMarketRates()
	{
		for (int i = 0; i < marketCount; i++)
		{
			MarketRate *tempVar = new MarketRate();
			tempVar->askPrice = 0.0;
			tempVar->bidPrice = 0.0;
			tempVar->lastMarketUpdate = DateTime::MinValue;
			tempVar->marketPairIndex = i;
			marketRates[i] = tempVar;

			delete tempVar;
		}
	}

	std::vector<Coin*> CoinbaseRobotCpp::LoadCoinAndMarketLists(MarketData* marketData, std::vector<MarketPair*>& marketPairArray)
	{
		std::unordered_map<int, Coin*> tempCoinDict;

		for (auto mp : *marketData->MarketPairArray)
		{
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

			if (tempCoinDict.find(mp->BaseCurrency->Id) == tempCoinDict.end())
			{
				tempCoinDict.emplace(mp->BaseCurrency->Id, mp->BaseCurrency);
			}

			if (!std::find(mp->BaseCurrency->BaseMarkets.begin(), mp->BaseCurrency->BaseMarkets.end(), mp) != mp->BaseCurrency->BaseMarkets.end())
			{
				mp->BaseCurrency->BaseMarkets.push_back(mp);
			}

			if (tempCoinDict.find(mp->QuoteCurrency->Id) == tempCoinDict.end())
			{
				tempCoinDict.emplace(mp->QuoteCurrency->Id, mp->QuoteCurrency);
			}

			if (!std::find(mp->QuoteCurrency->QuoteMarkets.begin(), mp->QuoteCurrency->QuoteMarkets.end(), mp) != mp->QuoteCurrency->QuoteMarkets.end())
			{
				mp->QuoteCurrency->QuoteMarkets.push_back(mp);
			}
		}

		int index = 0;
		std::vector<Coin*> coinArray(tempCoinDict.size());
		for (auto coin : tempCoinDict)
		{
			coinArray[index] = coin->second;
			++index;
		}

		return coinArray;
	}

	void CoinbaseRobotCpp::CreateLinkedCoinsAndMarketPair(const std::wstring& marketSymbol, int marketIndex, Product* item)
	{
		std::vector<std::wstring> assets = marketSymbol.Split(std::vector<wchar_t> {L'/', L'-'});

		Coin* baseCoin = FindOrCreateCoin(assets[0], coinDict, coins);
		Coin* quoteCoin = FindOrCreateCoin(assets[1], coinDict, coins);

		MarketPair* marketPair = new MarketPair();
		marketPair->Index = marketIndex;
		marketPair->Symbol = marketSymbol;
		marketPair->BaseCurrency = baseCoin;
		marketPair->BaseCurrencySymbol = baseCoin->Symbol;
		marketPair->BasePrecision = CountDecimalDigits(item->BaseIncrement);
		//baseCoin.minSize = CountDecimalDigits(item.BaseMinSize);
		marketPair->QuoteCurrency = quoteCoin;
		marketPair->QuoteCurrencySymbol = quoteCoin->Symbol;
		marketPair->QuotePrecision = CountDecimalDigits(item->QuoteIncrement);

		baseCoin->BaseMarkets.push_back(marketPair);
		quoteCoin->QuoteMarkets.push_back(marketPair);

		marketDict.emplace(marketIndex, marketPair);

		MarketRate* mr = new MarketRate();
		mr->lastMarketUpdate = DateTime::MinValue;
		mr->marketPairIndex = marketIndex;

		marketRateDict.emplace(marketSymbol, mr);

		//C# TO C++ CONVERTER TODO TASK: A 'delete mr' statement was not added since mr was passed to a method or constructor. Handle memory management manually.
		//C# TO C++ CONVERTER TODO TASK: A 'delete marketPair' statement was not added since marketPair was passed to a method or constructor. Handle memory management manually.
	}

	int CoinbaseRobotCpp::CountDecimalDigits(Decimal n)
	{
		//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
		return n.ToString(System::Globalization::CultureInfo::InvariantCulture).SkipWhile([&](std::any c)
			{
				return c != L'.';
			})->Skip(1)->Count();
	}

	Coin* CoinbaseRobotCpp::FindOrCreateCoin(const std::wstring& coinSymbol, std::unordered_map<int, Coin*>& coinDict, std::vector<Coin*>& coins)
	{
		int coinId = Base26::GetIdFromStr(coinSymbol);

		if (coinDict.find(coinId) != coinDict.end())
		{
			return coinDict[coinId];
		}

		Coin* coin = new Coin();
		coin->Id = coinId;
		coin->Symbol = coinSymbol.length() > 5 ? coinSymbol.substr(0, 5) : coinSymbol;
		coin->BaseMarkets = std::vector<MarketPair*>();
		coin->QuoteMarkets = std::vector<MarketPair*>();

		coins.push_back(coin);
		coinDict.emplace(coinId, coin);

		//C# TO C++ CONVERTER TODO TASK: A 'delete coin' statement was not added since coin was passed to a method or constructor. Handle memory management manually.
		return coin;
	}
}
