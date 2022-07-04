export module Coin;

//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

import MarketPair;
import PathStep;
import <string>;
import <vector>;
import <stdexcept>;

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	export class Coin
	{
	public:
		int Id = 0;
		std::wstring Symbol;
		double minSize = 0;
		std::vector<MarketPair*> QuoteMarkets;
		std::vector<MarketPair*> BaseMarkets;

		PathStep *pathStep;
		double dollarValue = 0.0;
		double nativeValue0 = 0.0;
		double nativeValue1 = 0.0;
		double nativeValue2 = 0.0;
		double nativeValue3 = 0.0;
		double nativeValue4 = 0.0;
		double nativeValue5 = 0.0;
		std::vector<std::vector<PathStep*>> bestLinks;
		std::vector<double> bestValues;
		double Balance = 0;
		double rateChange = 0;
		double BalanceInDollars = 0;

		virtual ~Coin()
		{
			delete pathStep;
		}

		Coin()
		{

			pathStep = new PathStep();
			pathStep->coin = this;
			pathStep->fromCoin = nullptr;

			this->bestLinks = std::vector<std::vector<PathStep*>>(5);
			this->bestLinks[0] = std::vector<PathStep*>(2);
			this->bestLinks[0][0] = new PathStep();
			this->bestLinks[0][1] = this->pathStep;
			this->bestLinks[1] = std::vector<PathStep*>(3);
			this->bestLinks[1][0] = new PathStep();
			this->bestLinks[1][1] = new PathStep();
			this->bestLinks[1][2] = this->pathStep;
			this->bestLinks[2] = std::vector<PathStep*>(4);
			this->bestLinks[2][0] = new PathStep();
			this->bestLinks[2][1] = new PathStep();
			this->bestLinks[2][2] = new PathStep();
			this->bestLinks[2][3] = this->pathStep;
			this->bestLinks[3] = std::vector<PathStep*>(5);
			this->bestLinks[3][0] = new PathStep();
			this->bestLinks[3][1] = new PathStep();
			this->bestLinks[3][2] = new PathStep();
			this->bestLinks[3][3] = new PathStep();
			this->bestLinks[3][4] = this->pathStep;
			this->bestLinks[4] = std::vector<PathStep*>(6);
			this->bestLinks[4][0] = new PathStep();
			this->bestLinks[4][1] = new PathStep();
			this->bestLinks[4][2] = new PathStep();
			this->bestLinks[4][3] = new PathStep();
			this->bestLinks[4][4] = new PathStep();
			this->bestLinks[4][5] = this->pathStep;
			this->bestValues = std::vector<double>(5);

		}
		Coin(Coin *sourceCoin, bool deepClone = false, std::vector<MarketPair*> &marketPairs = std::vector<MarketPair*>())
		{
			Id = sourceCoin->Id;
			Symbol = sourceCoin->Symbol;
			pathStep = new PathStep();
			pathStep->coin = this;
			pathStep->fromCoin = nullptr;
			dollarValue = sourceCoin->dollarValue;
			nativeValue0 = 0.0;
			nativeValue1 = 0.0;
			nativeValue2 = 0.0;
			nativeValue3 = 0.0;
			nativeValue4 = 0.0;
			nativeValue5 = 0.0;

			this->bestLinks = std::vector<std::vector<PathStep*>>(5);
			this->bestLinks[0] = std::vector<PathStep*>(2);
			this->bestLinks[0][0] = new PathStep();
			this->bestLinks[0][1] = this->pathStep;
			this->bestLinks[1] = std::vector<PathStep*>(3);
			this->bestLinks[1][0] = new PathStep();
			this->bestLinks[1][1] = new PathStep();
			this->bestLinks[1][2] = this->pathStep;
			this->bestLinks[2] = std::vector<PathStep*>(4);
			this->bestLinks[2][0] = new PathStep();
			this->bestLinks[2][1] = new PathStep();
			this->bestLinks[2][2] = new PathStep();
			this->bestLinks[2][3] = this->pathStep;
			this->bestLinks[3] = std::vector<PathStep*>(5);
			this->bestLinks[3][0] = new PathStep();
			this->bestLinks[3][1] = new PathStep();
			this->bestLinks[3][2] = new PathStep();
			this->bestLinks[3][3] = new PathStep();
			this->bestLinks[3][4] = this->pathStep;
			this->bestLinks[4] = std::vector<PathStep*>(6);
			this->bestLinks[4][0] = new PathStep();
			this->bestLinks[4][1] = new PathStep();
			this->bestLinks[4][2] = new PathStep();
			this->bestLinks[4][3] = new PathStep();
			this->bestLinks[4][4] = new PathStep();
			this->bestLinks[4][5] = this->pathStep;
			this->bestValues = std::vector<double>(5);


//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
