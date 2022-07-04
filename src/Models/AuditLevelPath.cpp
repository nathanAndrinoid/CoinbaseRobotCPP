export module AuditLevelPath;

import MarketPair;
import Coin;
import SavePathStep;
import <vector>;
import stringbuilder;

namespace Robot::Common::Models
{
	export class AuditLevelPath
	{
	private:
		std::vector<MarketPair*> marketPairArray;
		std::vector<Coin*> coinArray;

	public:
		AuditLevelPath(std::vector<MarketPair*> &marketPairArray, std::vector<Coin*> &coinArray)
		{
			this->marketPairArray = marketPairArray;
			this->coinArray = coinArray;
		}

		void AuditLoadedGoodOrder0(StringBuilder *sb)
		{
			double value = 0.0;
			int market = 9909;
			int orderSide = 2;
			int amountType = 2;
			int percision = 10;
			int toCoinId = coinArray.size();


			SavePathStep::GetPathStep(0, value, market, orderSide, amountType, percision, toCoinId);

			//Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " percision " + percision);

			if (market < 999)
			{
				sb->appendLine(L"placing order " + std::to_wstring(orderSide) + L" " + std::to_wstring(amountType) + L" " + marketPairArray[market]->Symbol + L" percision " + std::to_wstring(percision));
			}
			else
			{
				return;
			}

			AuditLoadedGoodOrder1(sb);

		}

		void AuditLoadedGoodOrder1(StringBuilder *sb)
		{
			double value = 0.0;
			int market = 9909;
			int orderSide = 2;
			int amountType = 2;
			int percision = 10;
			int toCoinId = coinArray.size();

			SavePathStep::GetPathStep(1, value, market, orderSide, amountType, percision, toCoinId);

			//Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " percision " + percision);
			if (market < 999)
			{
				sb->appendLine(L"placing order " + std::to_wstring(orderSide) + L" " + std::to_wstring(amountType) + L" " + marketPairArray[market]->Symbol + L" percision " + std::to_wstring(percision));
			}

			AuditLoadedGoodOrder2(sb);
		}

		void AuditLoadedGoodOrder2(StringBuilder *sb)
		{
			double value = 0.0;
			int market = 9909;
			int orderSide = 2;
			int amountType = 2;
			int percision = 10;
			int toCoinId = coinArray.size();

			SavePathStep::GetPathStep(2, value, market, orderSide, amountType, percision, toCoinId);

			//Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " percision " + percision);
			if (market < 999)
			{
				sb->appendLine(L"placing order " + std::to_wstring(orderSide) + L" " + std::to_wstring(amountType) + L" " + marketPairArray[market]->Symbol + L" percision " + std::to_wstring(percision));
			}

			AuditLoadedGoodOrder3(sb);
		}

		void AuditLoadedGoodOrder3(StringBuilder *sb)
		{
			double value = 0.0;
			int market = 9909;
			int orderSide = 2;
			int amountType = 2;
			int percision = 10;
			int toCoinId = coinArray.size();

			SavePathStep::GetPathStep(3, value, market, orderSide, amountType, percision, toCoinId);

			//Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " percision " + percision);
			if (market < 999)
			{
				sb->appendLine(L"placing order " + std::to_wstring(orderSide) + L" " + std::to_wstring(amountType) + L" " + marketPairArray[market]->Symbol + L" percision " + std::to_wstring(percision));
			}

			AuditLoadedGoodOrder4(sb);
		}

		void AuditLoadedGoodOrder4(StringBuilder *sb)
		{
			double value = 0.0;
			int market = 9909;
			int orderSide = 2;
			int amountType = 2;
			int percision = 10;
			int toCoinId = coinArray.size();

			SavePathStep::GetPathStep(4, value, market, orderSide, amountType, percision, toCoinId);

			//Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " percision " + percision);
			if (market < 999)
			{
				sb->appendLine(L"placing order " + std::to_wstring(orderSide) + L" " + std::to_wstring(amountType) + L" " + marketPairArray[market]->Symbol + L" percision " + std::to_wstring(percision));
			}
		}

		int AuditLoadedGoodOrder(int index = 0)
		{
			double value = 0.0;
			int market = 9909;
			int orderSide = 2;
			int amountType = 2;
			int percision = 10;
			int toCoinId = coinArray.size();


			SavePathStep::GetPathStep(index, value, market, orderSide, amountType, percision, toCoinId);

			if (market > 900)
			{
				return 0;
			}

			//Log.Information("placing order " + orderSide + " " + amountType + " " + marketPairArray[market].Symbol + " percision " + percision);

			++index;
			AuditLoadedGoodOrder(index);

			return index;
		}


	};
}
