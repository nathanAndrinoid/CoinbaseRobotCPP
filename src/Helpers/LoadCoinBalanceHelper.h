#pragma once

#include <vector>

namespace Robot::Common::Models
{
	class LoadCoinBalanceHelper final
	{
	public:
		static void LoadSwitchBalances();//int CoinCount, double zero, std::vector<double> &liveCoinBalances, int &onOne, std::vector<MemoryMappedViewAccessor*> &dataAccessor, MemoryMappedViewAccessor *controlAccessor);

		static int LoadLedgerBalances();//int FileSize, int ObjectSize, int CoinCount, double zero, std::vector<double> &liveCoinBalances, int &onOne, std::vector<MemoryMappedViewAccessor*> &dataAccessor, MemoryMappedViewAccessor *controlAccessor);
	};
}
