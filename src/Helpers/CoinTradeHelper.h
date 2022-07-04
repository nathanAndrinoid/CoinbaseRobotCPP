#pragma once

#include "../Models/Coin.h"
#include "../Models/MarketRate.h"
#include "../Models/MarketLevel.h"
#include "../Models/PathStep.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include "../stringbuilder.h"

using namespace Robot::Common::Models;

namespace Robot::Common::Helpers
{
	class CoinTradeHelper
	{

	public:
		double TradeSingle();//MemoryMappedViewAccessor *accessor, int id, double toDollarValue, double balance, StringBuilder *sb, Coin *indexCoin, std::unordered_map<int, Coin*> &coinDict, std::vector<MarketRate*> &marketRates);

		void FindDollarValues(std::vector<Coin*> &coinArray, Coin *indexUSD, std::vector<MarketRate*> &marketRates, std::vector<double> &dollarBestValues, std::vector<std::vector<Coin*>> &dolarBestLinks, std::unordered_map<int, Coin*> &coinDict);

	private:
		void BuildBestPathToDollar0(Coin *cStart, Coin *cEnd, std::vector<MarketRate*> &marketRates, std::vector<double> &dollarBestValues, std::vector<std::vector<Coin*>> &dolarBestLinks);

		void BuildBestPathToDollar1(std::deque<MarketLevel*> &queue);

		void SetBestPathStore(std::vector<PathStep*> &stepArray, Coin *lc, int startLength, int index);

		void SetSingleTradeFirst();//MemoryMappedViewAccessor *accessor, Coin *indexCoin, Coin *nextCoin, StringBuilder *sb, std::vector<MarketRate*> &marketRates);

		void ZeroOutCoins(std::unordered_map<int, Coin*> &coinDict);

		std::wstring CoinChain(Coin *lc);

		void GetIdList(Coin *cStart, std::vector<int> &eIds);

		int GetLength(Coin *cStart);

	};
}
