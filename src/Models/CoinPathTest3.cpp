#include "CoinPathTest3.h"
#include "SavePathStep.h"

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{

	void CoinPathTest3::BuildBestPathToCoinMarket3()//Coin *cEnd, double fee, std::vector<MarketRate*> &marketRates, std::unordered_map<int, PathStep*> &stepBestDict0, std::unordered_map<int, PathStep*> &stepBestDict1, std::unordered_map<int, PathStep*> &stepBestDict2, std::unordered_map<int, PathStep*> &stepBestDict3)
	{
		// for (auto sv : stepBestDict3)
		// {
		// 	sv->Value->value = 0.0;
		// 	sv->Value->coin = nullptr;
		// }
		//
		// for (auto step : stepBestDict2)
		// {
		// 	if (step->Value->coin == nullptr)
		// 	{
		// 		continue;
		// 	}
		//
		// 	if (step->Value->coin.nativeValue3 <= 0.0)
		// 	{
		// 		continue;
		// 	}
		//
		// 	Coin *cStart = step->Value->coin;
		//
		// 	for (auto item : *cStart->BaseMarkets)
		// 	{
		// 		if (marketRates[item->Index]->bidPrice == 0.0)
		// 		{
		// 			continue;
		// 		}
		//
		// 		if (item->QuoteCurrency->Id == cEnd->Id)
		// 		{
		// 			double value = cStart->nativeValue3 * marketRates[item->Index]->bidPrice;
		// 			value = value - (value * fee);
		//
		// 			if (value > item->QuoteCurrency->nativeValue4)
		// 			{
		// 				PathStep *eStep = stepBestDict3[item->QuoteCurrency->Id];
		// 				eStep->coin = item->QuoteCurrency;
		// 				eStep->Side = 1;
		// 				eStep->pair = item;
		// 				eStep->fromCoin = cStart;
		// 				eStep->value = value;
		// 				item->QuoteCurrency->nativeValue4 = value;
		// 				cEnd->nativeValue4 = value;
		//
		// 				double dollarValue = value * cEnd->dollarValue;
		//
		// 				if (SavePathStep::IsGreaterValue(dollarValue))
		// 				{
		// 					SavePathStep::SaveLinks0(stepBestDict0[stepBestDict1[stepBestDict2[eStep->fromCoin->Id]->fromCoin.Id]->fromCoin.Id]);
		// 					SavePathStep::SaveLinks1(stepBestDict1[stepBestDict2[eStep->fromCoin->Id]->fromCoin.Id]);
		// 					SavePathStep::SaveLinks2(stepBestDict2[eStep->fromCoin->Id]);
		// 					SavePathStep::SaveLinks3(eStep);
		// 					SavePathStep::SetPathStepEnd4();
		// 				}
		// 			}
		//
		// 			continue;
		// 		}
		//
		// 		double worth = cStart->nativeValue3 * marketRates[item->Index]->bidPrice;
		// 		worth = worth - (worth * fee);
		//
		// 		if (item->QuoteCurrency->nativeValue4 > worth)
		// 		{
		// 			continue;
		// 		}
		//
		// 		PathStep *coinStep = stepBestDict3[item->QuoteCurrency->Id];
		// 		coinStep->coin = item->QuoteCurrency;
		// 		coinStep->Side = 1;
		// 		coinStep->pair = item;
		// 		coinStep->fromCoin = cStart;
		// 		coinStep->value = worth;
		// 		item->QuoteCurrency->nativeValue4 = worth;
		// 	}
		//
		// 	for (auto item : *cStart->QuoteMarkets)
		// 	{
		// 		if (marketRates[item->Index]->askPrice == 0.0)
		// 		{
		// 			continue;
		// 		}
		//
		// 		if (item->BaseCurrency->Id == cEnd->Id)
		// 		{
		// 			double value = cStart->nativeValue3 / marketRates[item->Index]->askPrice;
		// 			value = value - (value * fee);
		//
		// 			if (value > item->BaseCurrency->nativeValue4)
		// 			{
		// 				PathStep *eStep = stepBestDict3[item->BaseCurrency->Id];
		// 				eStep->coin = item->BaseCurrency;
		// 				eStep->Side = 0;
		// 				eStep->pair = item;
		// 				eStep->fromCoin = cStart;
		// 				eStep->value = value;
		// 				item->BaseCurrency->nativeValue4 = value;
		// 				cEnd->nativeValue4 = value;
		//
		// 				double dollarValue = value * cEnd->dollarValue;
		//
		// 				if (SavePathStep::IsGreaterValue(dollarValue))
		// 				{
		// 					SavePathStep::SaveLinks0(stepBestDict0[stepBestDict1[stepBestDict2[eStep->fromCoin->Id]->fromCoin.Id]->fromCoin.Id]);
		// 					SavePathStep::SaveLinks1(stepBestDict1[stepBestDict2[eStep->fromCoin->Id]->fromCoin.Id]);
		// 					SavePathStep::SaveLinks2(stepBestDict2[eStep->fromCoin->Id]);
		// 					SavePathStep::SaveLinks3(eStep);
		// 					SavePathStep::SetPathStepEnd4();
		// 				}
		// 			}
		//
		// 			continue;
		// 		}
		//
		// 		double worth = cStart->nativeValue3 / marketRates[item->Index]->askPrice;
		// 		worth = worth - (worth * fee);
		//
		// 		if (item->BaseCurrency->nativeValue4 > worth)
		// 		{
		// 			continue;
		// 		}
		//
		// 		PathStep *coinStep = stepBestDict3[item->BaseCurrency->Id];
		// 		coinStep->coin = item->BaseCurrency;
		// 		coinStep->Side = 0;
		// 		coinStep->pair = item;
		// 		coinStep->fromCoin = cStart;
		// 		coinStep->value = worth;
		// 		item->BaseCurrency->nativeValue4 = worth;
		// 	}
		// }
	}
}
