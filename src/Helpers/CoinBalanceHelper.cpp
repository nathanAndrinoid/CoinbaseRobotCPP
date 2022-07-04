#include "CoinBalanceHelper.h"

namespace Robot::Common::Models
{

	void CoinBalanceHelper::ErraseMapStorrage(std::vector<MemoryMappedViewAccessor*> &dataAccessor, int CoinCount, double zero)
	{
		int index = 0;

		for (int loop = 0; loop < 1000; ++loop)
		{
			dataAccessor[0]->Write<int>(index, CoinCount);
			dataAccessor[1]->Write<int>(index, CoinCount);
			index += 4;
			dataAccessor[0]->Write<double>(index, zero);
			dataAccessor[1]->Write<double>(index, zero);
			index += 8;
			dataAccessor[0]->Write<int>(index, CoinCount);
			dataAccessor[1]->Write<int>(index, CoinCount);
			index += 4;
			dataAccessor[0]->Write<double>(index, zero);
			dataAccessor[1]->Write<double>(index, zero);
			index += 8;

		}

	}

	int CoinBalanceHelper::ObjectWrite(MemoryMappedViewAccessor *dataAccessor, int index, int coinId1, double value1, int coinId2, double value2)
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

	int CoinBalanceHelper::ObjectRead(MemoryMappedViewAccessor *dataAccessor, int index, int &coinId1, double &value1, int &coinId2, double &value2)
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
}
