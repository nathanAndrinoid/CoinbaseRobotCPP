#pragma once

#include "Coin.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

namespace Robot::Common::Models
{
	class CoinBalances final
	{
	private:
		// static MemoryMappedFile *controlFileMap;
		// static MemoryMappedViewAccessor *controlAccessor;
		// static std::vector<MemoryMappedFile*> dataFileMap;
		// static std::vector<MemoryMappedViewAccessor*> dataAccessor;
		static int FileSize;
		static int ObjectSize;
		static int CoinCount;
	public:
		static std::vector<double> liveCoinBalances;
	private:
		static std::vector<double> switchCoinBalances;
	public:
		static std::unordered_map<int, int> coinIndexDict;
	private:
		static double zero;
		static int onOne;

	public:
		static void InitCoinBalances();//const std::wstring &fileName, int coinCount, std::unordered_map<int, int> &cid, std::vector<Coin*> &ca = std::vector<Coin*>());

		static void LoadSwitchBalances();

		static int LoadLedgerBalances();

		static void ErraseMapStorrage();
	};
}
