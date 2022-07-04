#include "CoinPathTest0.h"
#include "SavePathStep.h"

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{

	void CoinPathTest0::BuildBestPathToCoinMarket0(Coin *cStart, Coin *cEnd, double fee, std::vector<MarketRate*> &marketRates, std::unordered_map<int, PathStep*> &stepBestDict0)
	{
		for (auto sv : stepBestDict0)
		{
			sv->Value->value = 0.0;
			sv->Value->coin = nullptr;
		}

		for (auto item : *cStart->BaseMarkets)
		{
			if (marketRates[item->Index]->bidPrice == 0.0)
			{
				continue;
			}

			if (item->QuoteCurrency->Id == cEnd->Id)
			{
				double value = cStart->nativeValue0 * marketRates[item->Index]->bidPrice;
				value = value - (value * fee);

				PathStep *eStep = stepBestDict0[item->QuoteCurrency->Id];
				eStep->coin = item->QuoteCurrency;
				eStep->Side = 1;
				eStep->pair = item;
				eStep->fromCoin = cStart;
				eStep->value = value;
				item->QuoteCurrency->nativeValue1 = value;
				cEnd->nativeValue1 = value;

				double dollarValue = value * cEnd->dollarValue;
				if (SavePathStep::IsGreaterValue(dollarValue))
				{
					SavePathStep::SaveLinks0(eStep);
					SavePathStep::SetPathStepEnd1();
				}

				continue;
			}

			double worth = cStart->nativeValue0 * marketRates[item->Index]->bidPrice;
			worth = worth - (worth * fee);

			PathStep *coinStep = stepBestDict0[item->QuoteCurrency->Id];
			coinStep->coin = item->QuoteCurrency;
			coinStep->Side = 1;
			coinStep->pair = item;
			coinStep->fromCoin = cStart;
			coinStep->value = worth;
			item->QuoteCurrency->nativeValue1 = worth;
		}

		for (auto item : *cStart->QuoteMarkets)
		{
			if (marketRates[item->Index]->askPrice == 0.0)
			{
				continue;
			}

			if (item->BaseCurrency->Id == cEnd->Id)
			{
				double value = cStart->nativeValue0 / marketRates[item->Index]->askPrice;
				value = value - (value * fee);

				PathStep *eStep = stepBestDict0[item->BaseCurrency->Id];
				eStep->coin = item->BaseCurrency;
				eStep->Side = 0;
				eStep->pair = item;
				eStep->fromCoin = cStart;
				eStep->value = value;
				item->BaseCurrency->nativeValue1 = value;
				cEnd->nativeValue1 = value;

				double dollarValue = value * cEnd->dollarValue;

				if (SavePathStep::IsGreaterValue(dollarValue))
				{
					SavePathStep::SaveLinks0(eStep);
					SavePathStep::SetPathStepEnd1();
				}

				continue;
			}

			double worth = cStart->nativeValue0 / marketRates[item->Index]->askPrice;
			worth = worth - (worth * fee);

			PathStep *coinStep = stepBestDict0[item->BaseCurrency->Id];
			coinStep->coin = item->BaseCurrency;
			coinStep->Side = 0;
			coinStep->pair = item;
			coinStep->fromCoin = cStart;
			coinStep->value = worth;
			item->BaseCurrency->nativeValue1 = worth;
		}
	}
}
