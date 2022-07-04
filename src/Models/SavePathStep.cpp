//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

#include "SavePathStep.h"

namespace Robot::Common::Models
{

MemoryMappedFile *SavePathStep::dataFileMap;
MemoryMappedViewAccessor *SavePathStep::accessor;
long long SavePathStep::ObjectSize = 0;
long long SavePathStep::FileSize = 0;
double SavePathStep::zero = 0.0;
int SavePathStep::noMarket = 9099;
long long SavePathStep::offset = 0;

	void SavePathStep::Init(std::any ac)
	{
		accessControl = ac;
		ObjectSize = 20;
		FileSize = 128;
		dataFileMap = MemoryMappedFile::CreateNew(L"PathSteps", FileSize, MemoryMappedFileAccess::ReadWrite, MemoryMappedFileOptions::None, HandleInheritability::None);
		accessor = dataFileMap->CreateViewAccessor(0, FileSize, MemoryMappedFileAccess::ReadWrite);
	}

	void SavePathStep::ClearPath()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			offset = 0;
			accessor->Write<double>(offset, zero);
			offset += 8;
			accessor->Write<int>(offset, noMarket);
		}
	}

	void SavePathStep::GetPathStep(int index, double &value, int &market, int &orderSide, int &amountType, int &percision, int &toCoinId)
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = 0;
			accessor->Read<double>(offset, value);
			offset = 8 + index * ObjectSize;

			accessor->Read<int>(offset, market);
			offset += 4;
			accessor->Read<int>(offset, orderSide);
			offset += 4;
			accessor->Read<int>(offset, amountType);
			offset += 4;
			accessor->Read<int>(offset, percision);
			offset += 4;
			accessor->Read<int>(offset, toCoinId);
		}
	}

	int SavePathStep::GetIndex1()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = 8 + ObjectSize;
			int market = 0;
			accessor->Read<int>(offset, market);

			return market;
		}
	}

	int SavePathStep::GetIndex2()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = 8 + 2 * ObjectSize;
			int market = 0;
			accessor->Read<int>(offset, market);

			return market;
		}
	}

	int SavePathStep::GetIndex3()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = 8 + 3 * ObjectSize;
			int market = 0;
			accessor->Read<int>(offset, market);

			return market;
		}
	}

	int SavePathStep::GetIndex4()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = 8 + 4 * ObjectSize;
			int market = 0;
			accessor->Read<int>(offset, market);

			return market;
		}
	}

	bool SavePathStep::IsGreaterValue(double newValue)
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			offset = 0;
			double oldValue = 0.0;
			accessor->Read<double>(offset, oldValue);

			if (newValue > oldValue)
			{
				accessor->Write<double>(offset, newValue);
				return true;
			}

			return false;
		}
	}

	void SavePathStep::SetPathStep(int index, int market, int orderSide, int amountType, int percision, int toCoinId)
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = 0;
			offset = (index * ObjectSize) + 8;
			accessor->Write<int>(offset, market);
			offset += 4;
			accessor->Write<int>(offset, orderSide);
			offset += 4;
			accessor->Write<int>(offset, amountType);
			offset += 4;
			accessor->Write<int>(offset, percision);
			offset += 4;
			accessor->Write<int>(offset, toCoinId);
		}
	}

	void SavePathStep::SetPathStepEnd1()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = (1 * ObjectSize) + 8;
			accessor->Write<int>(offset, noMarket);
		}
	}

	void SavePathStep::SetPathStepEnd2()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = (2 * ObjectSize) + 8;
			accessor->Write<int>(offset, noMarket);
		}
	}

	void SavePathStep::SetPathStepEnd3()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = (3 * ObjectSize) + 8;
			accessor->Write<int>(offset, noMarket);
		}
	}

	void SavePathStep::SetPathStepEnd4()
	{
		{
			std::scoped_lock<std::mutex> lock(accessControl);
			long long offset = (4 * ObjectSize) + 8;
			accessor->Write<int>(offset, noMarket);
		}
	}

	void SavePathStep::SaveLinks0(PathStep *pathStep)
	{
	}

	void SavePathStep::SaveLinks1(PathStep *pathStep1)
	{
	}

	void SavePathStep::SaveLinks2(PathStep *pathStep)
	{
	}

	void SavePathStep::SaveLinks3(PathStep *pathStep)
	{
	}


//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
