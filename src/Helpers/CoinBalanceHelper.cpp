export module CoinBalanceHelper;

namespace Robot::Common::Models
{
	export class CoinBalanceHelper final
	{

		//public static double GetCoinBalanceByIndex(long index)
		//{
		//    for (int i = 0; i < CoinCount; ++i)
		//        liveCoinBalances[i] = zero;

		//    int lastIndex = CoinBalances.LoadLedgerBalances();

		//    if (CoinBalances.liveCoinBalances[index] > 0.0 && lastIndex >= 0)
		//        return CoinBalances.liveCoinBalances[index];
		//    else
		//        return 0.0;
		//}

		//public static double GetCoinBalanceById(int id)
		//{
		//    ZeroLiveBalances();
		//    int lastIndex = CoinBalances.LoadLedgerBalances();

		//    if (CoinBalances.liveCoinBalances[CoinBalances.coinIndexDict[id]] > 0.0 && lastIndex >= 0)
		//        return CoinBalances.liveCoinBalances[CoinBalances.coinIndexDict[id]];
		//    else
		//        return 0.0;
		//}

		//public static void GetAllBalances(double[] cBal)
		//{
		//    ZeroLiveBalances();
		//    int lastIndex = CoinBalances.LoadLedgerBalances();

		//    if (lastIndex >= 4)
		//    {
		//        for (int i = 0; i < CoinCount; ++i)
		//        {
		//            cBal[i] = CoinBalances.liveCoinBalances[i];
		//        }
		//    }
		//    else
		//    {
		//        for (int i = 0; i < CoinCount; ++i)
		//            cBal[i] = zero;
		//    }
		//}

		//public static bool SetCoinBalanceById(int fromId, double fromAmount, int toId, double toAmount)
		//{
		//    ZeroLiveBalances();
		//    int lastIndex = CoinBalances.LoadLedgerBalances();
		//    int iFromIndex = CoinBalances.coinIndexDict[fromId];

		//    if (CoinBalances.liveCoinBalances[iFromIndex] >= fromAmount && lastIndex >= 4)
		//    {
		//        dataAccessor[onOne].Write<int>(lastIndex, ref iFromIndex);
		//        lastIndex += 4;
		//        dataAccessor[onOne].Write<double>(lastIndex, ref fromAmount);
		//        lastIndex += 8;
		//        int iToIndex = coinIndexDict[toId];
		//        dataAccessor[onOne].Write<int>(lastIndex, ref iToIndex);
		//        lastIndex += 4;
		//        dataAccessor[onOne].Write<double>(lastIndex, ref toAmount);
		//        return true;
		//    }
		//    return false;
		//}

		//public static bool SetCoinBalanceByIndex(int fromIndex, double fromAmount, int toIndex, double toAmount)
		//{
		//    ZeroLiveBalances();
		//    int lastIndex = LoadLedgerBalances();

		//    if ((!(fromAmount > 0.0) || liveCoinBalances[fromIndex] >= fromAmount) && lastIndex != -2)
		//    {
		//        if (lastIndex == -1)
		//            lastIndex = 0;

		//        dataAccessor[onOne].Write<int>(lastIndex, ref fromIndex);
		//        lastIndex += 4;
		//        dataAccessor[onOne].Write<double>(lastIndex, ref fromAmount);
		//        lastIndex += 8;
		//        dataAccessor[onOne].Write<int>(lastIndex, ref toIndex);
		//        lastIndex += 4;
		//        dataAccessor[onOne].Write<double>(lastIndex, ref toAmount);
		//        return true;
		//    }
		//    return false;
		//}

		//private static void ZeroLiveBalances()
		//{
		//    for (int i = 0; i < CoinCount; ++i)
		//        liveCoinBalances[i] = zero;
		//}

		//public static void ErraseMapStorrage()
		//{
		//    int index = 0;

		//    for (int loop = 0; loop < 1000; ++loop)
		//    {
		//        dataAccessor[0].Write<int>(index, ref CoinCount);
		//        dataAccessor[1].Write<int>(index, ref CoinCount);
		//        index += 4;
		//        dataAccessor[0].Write<double>(index, ref zero);
		//        dataAccessor[1].Write<double>(index, ref zero);
		//        index += 8;
		//        dataAccessor[0].Write<int>(index, ref CoinCount);
		//        dataAccessor[1].Write<int>(index, ref CoinCount);
		//        index += 4;
		//        dataAccessor[0].Write<double>(index, ref zero);
		//        dataAccessor[1].Write<double>(index, ref zero);
		//        index += 8;

		//    }

		//}

		//public static bool WaitingForSwitch()
		//{
		//    int switchFlag = 0;
		//    controlAccessor.Read<int>(4, out switchFlag);

		//    if (switchFlag > 0)
		//    {
		//        return true;
		//    }

		//    return false;
		//}

		//public static int SwitchRequested()
		//{
		//    int switchFlag = 0;
		//    controlAccessor.Read<int>(4, out switchFlag);

		//    return switchFlag;
		//}

		//public static void RequestSwitch(int switchFlag)
		//{
		//    controlAccessor.Write<int>(4, ref switchFlag);
		//}

	public:
		static int ObjectWrite(MemoryMappedViewAccessor *dataAccessor, int index, int coinId1, double value1, int coinId2, double value2)
		{
			dataAccessor->Write<int>(index, coinId1);
			index += 4;
			dataAccessor->Write<double>(index, value1);
			index += 8;
			dataAccessor->Write<int>(index, coinId2);
			index += 4;
			dataAccessor->Write<double>(index, value2);
			index += 8;

			return index;
		}

		static int ObjectRead(MemoryMappedViewAccessor *dataAccessor, int index, int &coinId1, double &value1, int &coinId2, double &value2)
		{
			dataAccessor->Read<int>(index, coinId1);
			index += 4;
			dataAccessor->Read<double>(index, value1);
			index += 8;
			dataAccessor->Read<int>(index, coinId2);
			index += 4;
			dataAccessor->Read<double>(index, value2);
			index += 8;

			return index;
		}

	};
}
