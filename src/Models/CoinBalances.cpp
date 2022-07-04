#include "CoinBalances.h"
#include "../Helpers/LoadCoinBalanceHelper.h"
#include "../Helpers/CoinBalanceHelper.h"

namespace Robot::Common::Models
{

MemoryMappedFile *CoinBalances::controlFileMap;
MemoryMappedViewAccessor *CoinBalances::controlAccessor;
std::vector<MemoryMappedFile*> CoinBalances::dataFileMap;
std::vector<MemoryMappedViewAccessor*> CoinBalances::dataAccessor;
int CoinBalances::FileSize = 0;
int CoinBalances::ObjectSize = 0;
int CoinBalances::CoinCount = 0;
std::vector<double> CoinBalances::liveCoinBalances;
std::vector<double> CoinBalances::switchCoinBalances;
std::unordered_map<int, int> CoinBalances::coinIndexDict;
double CoinBalances::zero = 0.0;
int CoinBalances::onOne = 0;

	void CoinBalances::InitCoinBalances(const std::wstring &fileName, int coinCount, std::unordered_map<int, int> &cid, std::vector<Coin*> &ca)
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

	void CoinBalances::LoadSwitchBalances()
	{
		LoadCoinBalanceHelper::LoadSwitchBalances(CoinCount, zero, liveCoinBalances, onOne, dataAccessor, controlAccessor);
	}

	int CoinBalances::LoadLedgerBalances()
	{
		return LoadCoinBalanceHelper::LoadLedgerBalances(FileSize, ObjectSize, CoinCount, zero, liveCoinBalances, onOne, dataAccessor, controlAccessor);
	}

	void CoinBalances::ErraseMapStorrage()
	{
		CoinBalanceHelper::ErraseMapStorrage(dataAccessor, CoinCount, zero);
	}
}
