export module CoinTradeHelper;

//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

import Coin;
import MarketRate;
import MarketLevel;
import PathStep;
import <string>;
import <unordered_map>;
import <vector>;
import <deque>;
import stringbuilder;

using namespace Robot::Common::Models;

namespace Robot::Common::Helpers
{
	export class CoinTradeHelper
	{

	public:
		double TradeSingle(MemoryMappedViewAccessor *accessor, int id, double toDollarValue, double balance, StringBuilder *sb, Coin *indexCoin, std::unordered_map<int, Coin*> &coinDict, std::vector<MarketRate*> &marketRates)
		{
			indexCoin->nativeValue0 = balance;
			Coin *to = coinDict[id];
			to->dollarValue = toDollarValue;

			SetSingleTradeFirst(accessor, indexCoin, to, sb,marketRates);
			double newVal = to->nativeValue0;

			double totalVal = newVal * to->dollarValue;

			if (totalVal > 0.0)
			{
				return newVal;
			}
			else
			{
				return 0.0;
			}
		}

		void FindDollarValues(std::vector<Coin*> &coinArray, Coin *indexUSD, std::vector<MarketRate*> &marketRates, std::vector<double> &dollarBestValues, std::vector<std::vector<Coin*>> &dolarBestLinks, std::unordered_map<int, Coin*> &coinDict)
		{
			for (auto lc : coinArray)
			{
				if (lc->Id == indexUSD->Id)
				{
					lc->dollarValue = 1.0;
					//lc.rateChange = 1.0;
					continue;
				}

				ZeroOutCoins(coinDict);

				lc->nativeValue0 = 1;
				indexUSD->nativeValue0 = 0;
				indexUSD->pathStep->fromCoin = nullptr;

				//dollarBestValues[0] = 0.0;
				//dollarBestValues[1] = 0.0;

				BuildBestPathToDollar0(lc, indexUSD, marketRates, dollarBestValues, dolarBestLinks);

				std::wstring name = lc->Symbol;
				double newVal = dollarBestValues[0];

				//if (dollarBestValues[1] > newVal)
				//    newVal = dollarBestValues[1];

				//if (lc.dollarValue > 0.0)
				//{
				//    double rolling = 1.0;
				//    dvChangeMap.GetValueById(lc.Id, out rolling);
				//    //dvChangeMap.SetValueById(lc.Id, (rolling + (newVal / lc.dollarValue)) / 2);
				//    dvChangeMap.SetValueById(lc.Id, ((rolling * 2) + (newVal / lc.dollarValue)) / 3);
				//}
				//else
				//    dvChangeMap.SetValueById(lc.Id, 1.0);

				if (newVal > 0.0)
				{
					lc->dollarValue = newVal;
					//dValueMap.SetValueById(lc.Id, newVal);
				}
			}
		}

	private:
		void BuildBestPathToDollar0(Coin *cStart, Coin *cEnd, std::vector<MarketRate*> &marketRates, std::vector<double> &dollarBestValues, std::vector<std::vector<Coin*>> &dolarBestLinks)
		{
			//Queue<MarketLevel> nextQueue = new Queue<MarketLevel>();

			//foreach (MarketLevel ml in queue)
			//{
			for (auto item : *cStart->BaseMarkets)
			{
				if (marketRates[item->Index]->bidPrice == 0.0)
				{
					continue; // throw new Exception("No price for assest!");
				}

				if (item->QuoteCurrency->Id == cEnd->Id)
				{
					double value = cStart->nativeValue0 * marketRates[item->Index]->bidPrice;

					cEnd->pathStep->fromCoin = cStart;
					cEnd->nativeValue1 = value;

					if (cEnd->nativeValue1 != dollarBestValues[0])
					{
						dollarBestValues[0] = cEnd->nativeValue1;
						dolarBestLinks[0][0] = cEnd;
					}

					return;
				}

				double worth = cStart->nativeValue0 * marketRates[item->Index]->bidPrice;
				//worth = worth - (worth * fee);

				item->QuoteCurrency->nativeValue1 = worth;
				item->QuoteCurrency->pathStep->fromCoin = cStart;

				//MarketLevel nextMarketLevel = new MarketLevel();
				//nextMarketLevel.cStart = item.QuoteCurrency;
				//nextMarketLevel.cEnd = ml.cEnd;
				//nextQueue.Enqueue(nextMarketLevel);
			}

			for (auto item : *cStart->QuoteMarkets)
			{
				if (marketRates[item->Index]->askPrice == 0.0)
				{
					continue; // throw new Exception("No price for assest!");
				}

				if (item->BaseCurrency->Id == cEnd->Id)
				{
					double value = cStart->nativeValue0 / marketRates[item->Index]->askPrice;

					cEnd->pathStep->fromCoin = cStart;
					cEnd->nativeValue1 = value;

					if (cEnd->nativeValue1 != dollarBestValues[0])
					{
						dollarBestValues[0] = cEnd->nativeValue1;
						dolarBestLinks[0][0] = cEnd;
					}

					return;
				}

				//double worth = ml.cStart.nativeValue0 / marketRates[item.Index].askPrice;
				////worth = worth - (worth * fee);

				//item.BaseCurrency.nativeValue1 = worth;
				//item.BaseCurrency.pathStep.fromCoin = ml.cStart;

				//MarketLevel nextMarketLevel = new MarketLevel();
				//nextMarketLevel.cStart = item.BaseCurrency;
				//nextMarketLevel.cEnd = ml.cEnd;
				//nextQueue.Enqueue(nextMarketLevel);
			}
			// }

			//if (nextQueue.Count > 0)
			//{
			//    BuildBestPathToDollar1(nextQueue);
			//}
		}

		void BuildBestPathToDollar1(std::deque<MarketLevel*> &queue)
		{
			//foreach (MarketLevel ml in queue)
			//{
			//    List<int> existingIds = new List<int>();
			//    GetIdList(ml.cStart, existingIds);

			//    foreach (var item in ml.cStart.BaseMarkets)
			//    {
			//        if (marketRates[item.Index].bidPrice == 0.0)
			//            throw new Exception("No price for assest!");

			//        if (item.QuoteCurrency.Id == ml.cEnd.Id)
			//        {
			//            double value = ml.cStart.nativeValue1 * marketRates[item.Index].bidPrice;
			//            //value = value - (value * fee);

			//            if (value > ml.cEnd.nativeValue2)
			//            {
			//                ml.cEnd.pathStep.fromCoin = ml.cStart;
			//                ml.cEnd.nativeValue2 = value;

			//                if (ml.cEnd.nativeValue2 != dollarBestValues[1])
			//                {
			//                    dollarBestValues[1] = ml.cEnd.nativeValue2;
			//                    SetBestDollarPathStore(ml.cEnd);
			//                }
			//            }

			//            continue;
			//        }

			//        if (depth == 1)
			//            continue;

			//        if (existingIds.Contains(item.QuoteCurrency.Id))
			//            continue;

			//        double worth = ml.cStart.nativeValue1 * marketRates[item.Index].bidPrice;
			//        //worth = worth - (worth * fee);

			//        if (item.QuoteCurrency.nativeValue2 > worth)
			//            continue;

			//        item.QuoteCurrency.nativeValue2 = worth;
			//        item.QuoteCurrency.pathStep.fromCoin = ml.cStart;

			//        MarketLevel nextMarketLevel = new MarketLevel();
			//        nextMarketLevel.cStart = item.QuoteCurrency;
			//        nextMarketLevel.cEnd = ml.cEnd;
			//        nextQueue.Enqueue(nextMarketLevel);
			//    }

			//    foreach (var item in ml.cStart.QuoteMarkets)
			//    {
			//        if (marketRates[item.Index].askPrice == 0.0)
			//            continue;

			//        if (item.BaseCurrency.Id == ml.cEnd.Id)
			//        {
			//            double value = ml.cStart.nativeValue1 / marketRates[item.Index].askPrice;
			//            //value = value - (value * fee);

			//            if (value > ml.cEnd.nativeValue2)
			//            {
			//                ml.cEnd.pathStep.fromCoin = ml.cStart;
			//                ml.cEnd.nativeValue2 = value;

			//                if (ml.cEnd.nativeValue2 > dollarBestValues[length])
			//                {
			//                    dollarBestValues[length] = ml.cEnd.nativeValue2;
			//                    SetBestDollarPathStore(ml.cEnd, length, length);
			//                }
			//            }

			//            continue;
			//        }

			//        if (depth == 1)
			//            continue;

			//        if (existingIds.Contains(item.BaseCurrency.Id))
			//            continue;

			//        double worth = ml.cStart.nativeValue1 / marketRates[item.Index].askPrice;
			//        //worth = worth - (worth * fee);

			//        if (item.BaseCurrency.nativeValue2 > worth)
			//            continue;

			//        item.BaseCurrency.nativeValue2 = worth;
			//        item.BaseCurrency.pathStep.fromCoin = ml.cStart;

			//        MarketLevel nextMarketLevel = new MarketLevel();
			//        nextMarketLevel.cStart = item.BaseCurrency;
			//        nextMarketLevel.cEnd = ml.cEnd;
			//        nextQueue.Enqueue(nextMarketLevel);
			//    }
			//}

		}

		void SetBestPathStore(std::vector<PathStep*> &stepArray, Coin *lc, int startLength, int index)
		{
			stepArray[index]->coin = lc->pathStep->coin;
			stepArray[index]->pair = lc->pathStep->pair;
			stepArray[index]->fromCoin = lc->pathStep->fromCoin;
			stepArray[index]->Side = lc->pathStep->Side;
			stepArray[index]->Price = lc->pathStep->Price;

			if (index == 0)
			{
				return;
			}

			SetBestPathStore(stepArray, lc->pathStep->fromCoin, startLength, index - 1);
		}

		void SetSingleTradeFirst(MemoryMappedViewAccessor *accessor, Coin *indexCoin, Coin *nextCoin, StringBuilder *sb, std::vector<MarketRate*> &marketRates)
		{
			double realFee = 0.0005; //fee;//

			for (auto item : *indexCoin->BaseMarkets)
			{
				if (item->QuoteCurrency->Id == nextCoin->Id)
				{
					double value = 0.0;
					MarketRate *mr = marketRates[item->Index];
					mr->ReadMarketRate(accessor, item->Index);

					sb->append(item->Symbol + L" " + std::to_wstring(indexCoin->nativeValue0) + L" " + std::to_wstring(mr->bidPrice));
					value = indexCoin->nativeValue0 * mr->bidPrice;
					value = value - (value * realFee);

					sb->appendLine(std::to_wstring(value * nextCoin->dollarValue));
					nextCoin->nativeValue0 = value;

					return;
				}
			}

			for (auto item : *indexCoin->QuoteMarkets)
			{
				if (item->BaseCurrency->Id == nextCoin->Id)
				{
					double value = 0.0;
					MarketRate *mr = marketRates[item->Index];
					mr->ReadMarketRate(accessor, item->Index);

					value = indexCoin->nativeValue0 / mr->askPrice;
					value = value - (value * realFee);

					nextCoin->nativeValue0 = value;

					return;
				}
			}
		}

		void ZeroOutCoins(std::unordered_map<int, Coin*> &coinDict)
		{
			for (auto coin : coinDict)
			{
				coin->Value->pathStep->fromCoin = nullptr;

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
