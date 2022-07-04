#include "Coin.h"

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{

	Coin::Coin()
	{

		// pathStep = (void*)new PathStep();
		// pathStep->coin = this;
		// pathStep->fromCoin = nullptr;
		//
		// this->bestLinks = std::vector<std::vector<PathStep*>>(5);
		// this->bestLinks[0] = std::vector<PathStep*>(2);
		// this->bestLinks[0][0] = new PathStep();
		// this->bestLinks[0][1] = this->pathStep;
		// this->bestLinks[1] = std::vector<PathStep*>(3);
		// this->bestLinks[1][0] = new PathStep();
		// this->bestLinks[1][1] = new PathStep();
		// this->bestLinks[1][2] = this->pathStep;
		// this->bestLinks[2] = std::vector<PathStep*>(4);
		// this->bestLinks[2][0] = new PathStep();
		// this->bestLinks[2][1] = new PathStep();
		// this->bestLinks[2][2] = new PathStep();
		// this->bestLinks[2][3] = this->pathStep;
		// this->bestLinks[3] = std::vector<PathStep*>(5);
		// this->bestLinks[3][0] = new PathStep();
		// this->bestLinks[3][1] = new PathStep();
		// this->bestLinks[3][2] = new PathStep();
		// this->bestLinks[3][3] = new PathStep();
		// this->bestLinks[3][4] = this->pathStep;
		// this->bestLinks[4] = std::vector<PathStep*>(6);
		// this->bestLinks[4][0] = new PathStep();
		// this->bestLinks[4][1] = new PathStep();
		// this->bestLinks[4][2] = new PathStep();
		// this->bestLinks[4][3] = new PathStep();
		// this->bestLinks[4][4] = new PathStep();
		// this->bestLinks[4][5] = this->pathStep;
		// this->bestValues = std::vector<double>(5);

	}

	Coin::Coin(Coin *sourceCoin, bool deepClone)//, std::vector<MarketPair*> *marketPairs)
	{
		// Id = sourceCoin->Id;
		// Symbol = sourceCoin->Symbol;
		// pathStep = new PathStep();
		// pathStep->coin = this;
		// pathStep->fromCoin = nullptr;
		// dollarValue = sourceCoin->dollarValue;
		// nativeValue0 = 0.0;
		// nativeValue1 = 0.0;
		// nativeValue2 = 0.0;
		// nativeValue3 = 0.0;
		// nativeValue4 = 0.0;
		// nativeValue5 = 0.0;
		//
		// this->bestLinks = std::vector<std::vector<PathStep*>>(5);
		// this->bestLinks[0] = std::vector<PathStep*>(2);
		// this->bestLinks[0][0] = new PathStep();
		// this->bestLinks[0][1] = this->pathStep;
		// this->bestLinks[1] = std::vector<PathStep*>(3);
		// this->bestLinks[1][0] = new PathStep();
		// this->bestLinks[1][1] = new PathStep();
		// this->bestLinks[1][2] = this->pathStep;
		// this->bestLinks[2] = std::vector<PathStep*>(4);
		// this->bestLinks[2][0] = new PathStep();
		// this->bestLinks[2][1] = new PathStep();
		// this->bestLinks[2][2] = new PathStep();
		// this->bestLinks[2][3] = this->pathStep;
		// this->bestLinks[3] = std::vector<PathStep*>(5);
		// this->bestLinks[3][0] = new PathStep();
		// this->bestLinks[3][1] = new PathStep();
		// this->bestLinks[3][2] = new PathStep();
		// this->bestLinks[3][3] = new PathStep();
		// this->bestLinks[3][4] = this->pathStep;
		// this->bestLinks[4] = std::vector<PathStep*>(6);
		// this->bestLinks[4][0] = new PathStep();
		// this->bestLinks[4][1] = new PathStep();
		// this->bestLinks[4][2] = new PathStep();
		// this->bestLinks[4][3] = new PathStep();
		// this->bestLinks[4][4] = new PathStep();
		// this->bestLinks[4][5] = this->pathStep;
		// this->bestValues = std::vector<double>(5);
		//
		// if (deepClone && marketPairs.empty())
		// {
		// 	throw std::runtime_error("cloning tree without market pair dictionary");
		// }
		//
		// if (deepClone)
		// {
		// 	QuoteMarkets = std::vector<MarketPair*>();
		// 	BaseMarkets = std::vector<MarketPair*>();
		//
		// 	for (auto mp : *sourceCoin->QuoteMarkets)
		// 	{
		// 		QuoteMarkets.push_back(marketPairs[mp->Index]);
		// 	}
		//
		// 	for (auto mp : *sourceCoin->BaseMarkets)
		// 	{
		// 		BaseMarkets.push_back(marketPairs[mp->Index]);
		// 	}
		// }
		// else
		// {
		// 	QuoteMarkets = sourceCoin->QuoteMarkets;
		// 	BaseMarkets = sourceCoin->BaseMarkets;
		// }
	}

	void Coin::CopyIn(Coin *sourceCoin)
	{
		// Id = sourceCoin->Id;
		// Symbol = sourceCoin->Symbol;
		// pathStep->coin = this;
		// pathStep->fromCoin = nullptr;
		// dollarValue = sourceCoin->dollarValue;
		// nativeValue0 = 0.0;
		// nativeValue1 = 0.0;
		// nativeValue2 = 0.0;
		// nativeValue3 = 0.0;
		// nativeValue4 = 0.0;
		// nativeValue5 = 0.0;
		// QuoteMarkets = sourceCoin->QuoteMarkets;
		// BaseMarkets = sourceCoin->BaseMarkets;
	}
}
