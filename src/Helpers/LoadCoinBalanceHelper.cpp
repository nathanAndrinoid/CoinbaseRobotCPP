#include "LoadCoinBalanceHelper.h"
#include "CoinBalanceHelper.h"

namespace Robot::Common::Models
{

	void LoadCoinBalanceHelper::LoadSwitchBalances()//int CoinCount, double zero, std::vector<double> &liveCoinBalances, int &onOne, std::vector<MemoryMappedViewAccessor*> &dataAccessor, MemoryMappedViewAccessor *controlAccessor)
	{
		// for (int i = 0; i < CoinCount; ++i)
		// {
		// 	liveCoinBalances[i] = zero;
		// }
		//
		// controlAccessor->Read<int>(0, onOne);
		//
		// int index = 0;
		// bool readFirst = false;
		// bool readLast = false;
		//
		// for (int loop = 0; loop < 1000; ++loop)
		// {
		// 	int iFromId = 0;
		// 	double iFromAmount = 0.0;
		// 	int iToId = 0;
		// 	double iToAmount = 0.0;
		// 	index = CoinBalanceHelper::ObjectRead(dataAccessor[onOne], index, iFromId, iFromAmount, iToId, iToAmount);
		//
		// 	if (iFromId != CoinCount && iToId != CoinCount)
		// 	{
		// 		readFirst = true;
		// 		liveCoinBalances[iFromId] -= iFromAmount;
		// 		liveCoinBalances[iToId] += iToAmount;
		// 	}
		// 	else if (iFromId != CoinCount && iToId == CoinCount)
		// 	{
		// 		readFirst = true;
		// 		liveCoinBalances[iFromId] -= iFromAmount;
		// 	}
		// 	else if (iFromId == CoinCount && iToId != CoinCount)
		// 	{
		// 		readFirst = true;
		// 		liveCoinBalances[iToId] += iToAmount;
		// 	}
		// 	else
		// 	{
		// 		if (readFirst)
		// 		{
		// 			readLast = true;
		// 		}
		// 	}
		//
		// 	if (readFirst && readLast)
		// 	{
		// 		break;
		// 	}
		// }
		//
		// index = 0;
		// int onOnetemp = onOne == 0 ? 1 : 0;
		//
		// for (int loop = 0; loop < 1000; ++loop)
		// {
		// 	index = CoinBalanceHelper::ObjectWrite(dataAccessor[onOnetemp], index, CoinCount, zero, CoinCount, zero);
		//
		// }
		//
		// index = 0;
		// double value = 0.0;
		//
		// for (int i = 0; i < CoinCount; ++i)
		// {
		// 	value = liveCoinBalances[i];
		//
		// 	if (value > zero)
		// 	{
		// 		index = CoinBalanceHelper::ObjectWrite(index);//, dataAccessor[onOnetemp], CoinCount, zero, i, value);
		// 	}
		// }
		//
		// int switchFlag = 0;
		// controlAccessor->Write<int>(0, onOnetemp);
		// controlAccessor->Write<int>(4, switchFlag);
	}

	int LoadCoinBalanceHelper::LoadLedgerBalances()//int FileSize, int ObjectSize, int CoinCount, double zero, std::vector<double> &liveCoinBalances, int &onOne, std::vector<MemoryMappedViewAccessor*> &dataAccessor, MemoryMappedViewAccessor *controlAccessor)
	{
		// for (int i = 0; i < CoinCount; ++i)
		// {
		// 	liveCoinBalances[i] = zero;
		// }
		//
		// bool readFirst = false;
		// bool readLast = false;
		// int lastIndex = -1;
		// controlAccessor->Read<int>(0, onOne);
		// int index = 0;
		//
		// for (int loop = 0; loop < 1000; ++loop)
		// {
		// 	int iFromId = 0;
		// 	double iFromAmount = 0.0;
		// 	int iToId = 0;
		// 	double iToAmount = 0.0;
		// 	index = CoinBalanceHelper::ObjectRead(dataAccessor[onOne], index, iFromId, iFromAmount, iToId, iToAmount);
		//
		// 	if (iFromId != CoinCount && iToId != CoinCount)
		// 	{
		// 		readFirst = true;
		// 		liveCoinBalances[iFromId] -= iFromAmount;
		// 		liveCoinBalances[iToId] += iToAmount;
		// 	}
		// 	else if (iFromId != CoinCount && iToId == CoinCount)
		// 	{
		// 		readFirst = true;
		// 		liveCoinBalances[iFromId] -= iFromAmount;
		// 	}
		// 	else if (iFromId == CoinCount && iToId != CoinCount)
		// 	{
		// 		readFirst = true;
		// 		liveCoinBalances[iToId] += iToAmount;
		// 	}
		// 	else
		// 	{
		// 		if (readFirst)
		// 		{
		// 			readLast = true;
		// 		}
		// 	}
		//
		// 	if (readFirst && readLast)
		// 	{
		// 		if (index == FileSize)
		// 		{
		// 			index = 0;
		// 		}
		//
		// 		index -= ObjectSize;
		//
		// 		if (index < 0)
		// 		{
		// 			index = FileSize - ObjectSize;
		// 		}
		//
		// 		lastIndex = index;
		// 		return lastIndex;
		// 	}
		// }
		//
		// if (readFirst)
		// {
		// 	return -2;
		// }
		// else
		// {
		// 	return -1;
		// }
	}
}
