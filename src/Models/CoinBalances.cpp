export module CoinBalances;

//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

import Coin;
import CoinBalanceHelper;
import <string>;
import <unordered_map>;
import <vector>;
import <stdexcept>;

namespace Robot::Common::Models
{
	export class CoinBalances final
	{
	private:
		static MemoryMappedFile *controlFileMap;
		static MemoryMappedViewAccessor *controlAccessor;
		static std::vector<MemoryMappedFile*> dataFileMap;
		static std::vector<MemoryMappedViewAccessor*> dataAccessor;
		static int FileSize;
		static int ObjectSize;
		static int CoinCount;
		static double zero = 0.0;
		static int onOne = 0;
		static std::vector<double> switchCoinBalances;
	public:
		static std::vector<double> liveCoinBalances;
		static std::unordered_map<int, int> coinIndexDict;
		
	public:
		static void InitCoinBalances(const std::wstring &fileName, int coinCount, std::unordered_map<int, int> &cid, std::vector<Coin*> &ca = std::vector<Coin*>())
		{
			coinIndexDict = std::unordered_map<int, int>();

			for (auto c : cid)
			{
				coinIndexDict.emplace(c.Key, c.Value);
			}

			CoinCount = coinCount;
			liveCoinBalances = std::vector<double>(coinCount);

			ObjectSize = 4 + 8 + 4 + 8;
			FileSize = (1000 * ObjectSize);
			bool noExistingFile = true;

			try
			{
				controlFileMap = MemoryMappedFile::OpenExisting(fileName + L"Cofntrol");
				noExistingFile = false;
				controlFileMap = nullptr;
			}
			catch (const std::runtime_error &e)
			{
			}

			controlFileMap = MemoryMappedFile::CreateOrOpen(fileName + L"Control", 8, MemoryMappedFileAccess::ReadWrite, MemoryMappedFileOptions::None, HandleInheritability::Inheritable);
			controlAccessor = controlFileMap->CreateViewAccessor(0, 8, MemoryMappedFileAccess::ReadWrite);
			dataFileMap = std::vector<MemoryMappedFile*>(2);
			dataAccessor = std::vector<MemoryMappedViewAccessor*>(2);
			dataFileMap[0] = MemoryMappedFile::CreateOrOpen(fileName + L"0", FileSize, MemoryMappedFileAccess::ReadWrite, MemoryMappedFileOptions::None, HandleInheritability::Inheritable);
			dataAccessor[0] = dataFileMap[0]->CreateViewAccessor(0, FileSize, MemoryMappedFileAccess::ReadWrite);
			dataFileMap[1] = MemoryMappedFile::CreateOrOpen(fileName + L"1", FileSize, MemoryMappedFileAccess::ReadWrite, MemoryMappedFileOptions::None, HandleInheritability::Inheritable);
			dataAccessor[1] = dataFileMap[1]->CreateViewAccessor(0, FileSize, MemoryMappedFileAccess::ReadWrite);
		}

		static void LoadSwitchBalances()
		{
			for (int i = 0; i < CoinCount; ++i)
			{
				liveCoinBalances[i] = zero;
			}

			controlAccessor->Read<int>(0, onOne);

			int index = 0;
			bool readFirst = false;
			bool readLast = false;

			for (int loop = 0; loop < 1000; ++loop)
			{
				int iFromId = 0;
				double iFromAmount = 0.0;
				int iToId = 0;
				double iToAmount = 0.0;
				index = CoinBalanceHelper::ObjectRead(dataAccessor[onOne], index, iFromId, iFromAmount, iToId, iToAmount);

				if (iFromId != CoinCount && iToId != CoinCount)
				{
					readFirst = true;
					liveCoinBalances[iFromId] -= iFromAmount;
					liveCoinBalances[iToId] += iToAmount;
				}
				else if (iFromId != CoinCount && iToId == CoinCount)
				{
					readFirst = true;
					liveCoinBalances[iFromId] -= iFromAmount;
				}
				else if (iFromId == CoinCount && iToId != CoinCount)
				{
					readFirst = true;
					liveCoinBalances[iToId] += iToAmount;
				}
				else
				{
					if (readFirst)
					{
						readLast = true;
					}
				}

				if (readFirst && readLast)
				{
					break;
				}
			}

			index = 0;
			int onOnetemp = onOne == 0 ? 1 : 0;

			for (int loop = 0; loop < 1000; ++loop)
			{
				index = CoinBalanceHelper::ObjectWrite(dataAccessor[onOnetemp], index, CoinCount, zero, CoinCount, zero);

			}

			index = 0;
			double value = 0.0;

			for (int i = 0; i < CoinCount; ++i)
			{
				value = liveCoinBalances[i];

				if (value > zero)
				{
					index = CoinBalanceHelper::ObjectWrite(dataAccessor[onOnetemp], index, CoinCount, zero, i, value);
				}
			}

			int switchFlag = 0;
			controlAccessor->Write<int>(0, onOnetemp);
			controlAccessor->Write<int>(4, switchFlag);
		}

		static int LoadLedgerBalances()
		{
			for (int i = 0; i < CoinCount; ++i)
			{
				liveCoinBalances[i] = zero;
			}

			bool readFirst = false;
			bool readLast = false;
			int lastIndex = -1;
			controlAccessor->Read<int>(0, onOne);
			int index = 0;

			for (int loop = 0; loop < 1000; ++loop)
			{
				int iFromId = 0;
				double iFromAmount = 0.0;

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
