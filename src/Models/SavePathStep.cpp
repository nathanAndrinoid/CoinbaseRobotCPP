export module SavePathStep;

//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

import PathStep;
import <any>;
import <mutex>;

namespace Robot::Common::Models
{
	export class SavePathStep final
	{
	private:
		static MemoryMappedFile *dataFileMap;
		static MemoryMappedViewAccessor *accessor;
		static std::mutex accessControl;
		static long long ObjectSize;
		static long long FileSize;
//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static double zero = 0.0;
//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static int noMarket = 9099;
//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static long long offset = 0;

	public:
		static void Init(std::any ac)
		{
			accessControl = ac;
			ObjectSize = 20;
			FileSize = 128;
			dataFileMap = MemoryMappedFile::CreateNew(L"PathSteps", FileSize, MemoryMappedFileAccess::ReadWrite, MemoryMappedFileOptions::None, HandleInheritability::None);
			accessor = dataFileMap->CreateViewAccessor(0, FileSize, MemoryMappedFileAccess::ReadWrite);
		}

		static void ClearPath()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				offset = 0;
				accessor->Write<double>(offset, zero);
				offset += 8;
				accessor->Write<int>(offset, noMarket);
			}
		}

		static void GetPathStep(int index, double &value, int &market, int &orderSide, int &amountType, int &percision, int &toCoinId)
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

		static int GetIndex1()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				long long offset = 8 + ObjectSize;
				int market = 0;
				accessor->Read<int>(offset, market);

				return market;
			}
		}

		static int GetIndex2()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				long long offset = 8 + 2 * ObjectSize;
				int market = 0;
				accessor->Read<int>(offset, market);

				return market;
			}
		}

		static int GetIndex3()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				long long offset = 8 + 3 * ObjectSize;
				int market = 0;
				accessor->Read<int>(offset, market);

				return market;
			}
		}

		static int GetIndex4()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				long long offset = 8 + 4 * ObjectSize;
				int market = 0;
				accessor->Read<int>(offset, market);

				return market;
			}
		}

		static bool IsGreaterValue(double newValue)
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

		static void SetPathStep(int index, int market, int orderSide, int amountType, int percision, int toCoinId)
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

		static void SetPathStepEnd1()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				long long offset = (1 * ObjectSize) + 8;
				accessor->Write<int>(offset, noMarket);
			}
		}

		static void SetPathStepEnd2()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				long long offset = (2 * ObjectSize) + 8;
				accessor->Write<int>(offset, noMarket);
			}
		}

		static void SetPathStepEnd3()
		{
			{
				std::scoped_lock<std::mutex> lock(accessControl);
				long long offset = (3 * ObjectSize) + 8;
				accessor->Write<int>(offset, noMarket);
			}
		}

		static void SetPathStepEnd4()
		{
			{

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
