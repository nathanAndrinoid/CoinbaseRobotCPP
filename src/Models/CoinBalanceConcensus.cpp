//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

#include "CoinBalanceConcensus.h"
#include "CoinBalances.h"

using namespace Robot::Common::Models;

namespace CoinbaseRobotTranlator::Models
{

MemoryMappedFile *CoinBalanceConcensus::consensusFileMap;
MemoryMappedViewAccessor *CoinBalanceConcensus::consensusAccessorRead;
MemoryMappedViewAccessor *CoinBalanceConcensus::consensusAccessorWrite;
std::unordered_map<int, int> CoinBalanceConcensus::coinIndexDict;
int CoinBalanceConcensus::CoinCount = 0;

	void CoinBalanceConcensus::InitCoinBalanceConcensus(const std::wstring &fileName, int cc, std::unordered_map<int, int> &cid, std::vector<Coin*> &ca)
	{
		CoinCount = cc;
		coinIndexDict = std::unordered_map<int, int>();

		for (auto c : cid)
		{
			coinIndexDict.emplace(c.Key, c.Value);
		}

		consensusFileMap = MemoryMappedFile::CreateOrOpen(fileName + L"Consensus", 48, MemoryMappedFileAccess::ReadWrite, MemoryMappedFileOptions::None, HandleInheritability::Inheritable);
		consensusAccessorRead = consensusFileMap->CreateViewAccessor(0, 48, MemoryMappedFileAccess::Read);
		consensusAccessorWrite = consensusFileMap->CreateViewAccessor(0, 48, MemoryMappedFileAccess::Write);

	}

	bool CoinBalanceConcensus::ValidateConsensusRequest()
	{
		int fIndex = 16;
		int requestFlag = 0;
		double amount = 0.0;
		consensusAccessorRead->Read<double>(fIndex, amount);

		fIndex = 0;
		consensusAccessorRead->Read<int>(fIndex, requestFlag);

		if (requestFlag == 0)
		{
			return false;
		}

		if (requestFlag < 0)
		{
			return false;
		}

		int iIndex = CoinCount;

		fIndex = 8;
		consensusAccessorRead->Read<int>(fIndex, iIndex);


		int lastIndex = CoinBalances::LoadLedgerBalances();

		if (lastIndex < 0)
		{
			requestFlag = -2;
			consensusAccessorWrite->Write<int>(fIndex, requestFlag);
			return false;
		}

		if (CoinBalances::liveCoinBalances[iIndex] == amount)
		{
			requestFlag = 0;
			consensusAccessorWrite->Write<int>(0, requestFlag);
			return false;
		}

		return true;
	}

	void CoinBalanceConcensus::SendActualValue()
	{
		int fIndex = 8;
		int requestFlag = 0;
		int coinIndex = CoinCount;

		consensusAccessorRead->Read<int>(fIndex, coinIndex);

		if (coinIndex == CoinCount)
		{
			delay(5000);
			return;
		}

		fIndex = 16;
		consensusAccessorWrite->Write<double>(fIndex, CoinBalances::liveCoinBalances[coinIndex]);
		fIndex = 0;
		consensusAccessorWrite->Write<int>(fIndex, requestFlag);
	}

	double CoinBalanceConcensus::GetValidatedValueById(int id)
	{
		int fIndex = 8;
		int requestFlag = 1;
		int coinIndex = coinIndexDict[id];

		consensusAccessorWrite->Write<int>(fIndex, coinIndex);
		fIndex = 0;
		consensusAccessorWrite->Write<int>(fIndex, requestFlag);

		do
		{
			consensusAccessorRead->Read<int>(fIndex, requestFlag);
		} while (requestFlag == 1);

		fIndex = 16;
		double value = 0.0;

		consensusAccessorRead->Read<double>(fIndex, value);

		return value;
	}

	void CoinBalanceConcensus::RespondToValueRequest()
	{
		int fIndex = 0;
		int requestFlag = 0;

		consensusAccessorRead->Read<int>(fIndex, requestFlag);

		if (requestFlag == 0)
		{
			return;
		}

		fIndex = 8;
		int coinIndex = CoinCount;

		consensusAccessorRead->Read<int>(fIndex, coinIndex);

		if (coinIndex == CoinCount)
		{
			return;
		}

		CoinBalances::LoadLedgerBalances();

		fIndex = 16;
		consensusAccessorWrite->Write<double>(fIndex, CoinBalances::liveCoinBalances[coinIndex]);

		fIndex = 0;
		requestFlag = 0;

		consensusAccessorWrite->Write<int>(fIndex, requestFlag);

	}

	double CoinBalanceConcensus::GetValidatedValueByIndex(int coinIndex)
	{
		int fIndex = 8;
		int requestFlag = 1;

		consensusAccessorWrite->Write<int>(fIndex, coinIndex);
		fIndex = 0;
		consensusAccessorWrite->Write<int>(fIndex, requestFlag);

		do
		{
			consensusAccessorRead->Read<int>(fIndex, requestFlag);
		} while (requestFlag == 1);

		fIndex = 16;
		double value = 0.0;

		consensusAccessorRead->Read<double>(fIndex, value);

		return value;
	}

	void CoinBalanceConcensus::SetConsensusFlag(int requestFlag)
	{
		int fIndex = 0;
		consensusAccessorWrite->Write<int>(fIndex, requestFlag);
	}

	void CoinBalanceConcensus::SetConsensusById(int id, double amount)
	{
		int fIndex = 8;

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
