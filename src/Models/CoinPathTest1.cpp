export module CoinPathTest1;

import Coin;
import MarketRate;
import PathStep;
import SavePathStep;
import <unordered_map>;
import <vector>;

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	export class CoinPathTest1
	{

	public:
		void BuildBestPathToCoinMarket1(Coin *cEnd, double fee, std::vector<MarketRate*> &marketRates, std::unordered_map<int, PathStep*> &stepBestDict0, std::unordered_map<int, PathStep*> &stepBestDict1)
		{
			for (auto sv : stepBestDict1)
			{
				sv->Value->value = 0.0;
				sv->Value->coin = nullptr;
			}

			for (auto step : stepBestDict0)
			{
				if (step->Value->coin == nullptr)
				{
					continue;
				}

				if (step->Value->coin.nativeValue1 <= 0.0)
				{
					continue;
				}

				Coin *cStart = step->Value->coin;

				for (auto item : *cStart->BaseMarkets)
				{
					if (marketRates[item->Index]->bidPrice == 0.0)
					{
						continue;
					}

					if (item->QuoteCurrency->Id == cEnd->Id)
					{
						double value = cStart->nativeValue1 * marketRates[item->Index]->bidPrice;
						value = value - (value * fee);

						if (value > item->QuoteCurrency->nativeValue2)
						{
							PathStep *eStep = stepBestDict1[item->QuoteCurrency->Id];
							eStep->coin = item->QuoteCurrency;
							eStep->Side = 1;
							eStep->pair = item;
							eStep->fromCoin = cStart;
							eStep->value = value;
							item->QuoteCurrency->nativeValue2 = value;
							cEnd->nativeValue2 = value;

							double dollarValue = value * cEnd->dollarValue;

							if (SavePathStep::IsGreaterValue(dollarValue))
							{
								SavePathStep::SaveLinks0(stepBestDict0[eStep->fromCoin->Id]);
								SavePathStep::SaveLinks1(eStep);
								SavePathStep::SetPathStepEnd2();
							}
						}

						continue;
					}

					double worth = cStart->nativeValue1 * marketRates[item->Index]->bidPrice;
					worth = worth - (worth * fee);

					if (item->QuoteCurrency->nativeValue2 > worth)
					{
						continue;
					}

					PathStep *coinStep = stepBestDict1[item->QuoteCurrency->Id];
					coinStep->coin = item->QuoteCurrency;
					coinStep->Side = 1;
					coinStep->pair = item;
					coinStep->fromCoin = cStart;
					coinStep->value = worth;
					item->QuoteCurrency->nativeValue2 = worth;
				}

				for (auto item : *cStart->QuoteMarkets)
				{
					if (marketRates[item->Index]->askPrice == 0.0)
					{
						continue;
					}

					if (item->BaseCurrency->Id == cEnd->Id)
					{
						double value = cStart->nativeValue1 / marketRates[item->Index]->askPrice;
						value = value - (value * fee);

						if (value > item->BaseCurrency->nativeValue2)
						{
							PathStep *eStep = stepBestDict1[item->BaseCurrency->Id];
							eStep->coin = item->BaseCurrency;
							eStep->Side = 0;
							eStep->pair = item;
							eStep->fromCoin = cStart;
							eStep->value = value;
							item->BaseCurrency->nativeValue2 = value;
							cEnd->nativeValue2 = value;

							double dollarValue = value * cEnd->dollarValue;

							if (SavePathStep::IsGreaterValue(dollarValue))
							{
								SavePathStep::SaveLinks0(stepBestDict0[eStep->fromCoin->Id]);
								SavePathStep::SaveLinks1(eStep);
								SavePathStep::SetPathStepEnd2();
							}
						}

						continue;
					}

					double worth = cStart->nativeValue1 / marketRates[item->Index]->askPrice;
					worth = worth - (worth * fee);

					if (item->BaseCurrency->nativeValue2 > worth)
					{
						continue;
					}

					PathStep *coinStep = stepBestDict1[item->BaseCurrency->Id];
					coinStep->coin = item->BaseCurrency;
					coinStep->Side = 0;
					coinStep->pair = item;
					coinStep->fromCoin = cStart;
					coinStep->value = worth;
					item->BaseCurrency->nativeValue2 = worth;
				}
			}
		}

	};
}
