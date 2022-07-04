// ﻿#include "MarketRate.h"
//
// namespace Robot::Common::Models
// {
//
// //MemoryMappedFile *MarketRate::dataFileMap;
// int MarketRate::MarketCount = 0;
// long long MarketRate::ObjectSize = 0;
// long long MarketRate::FileSize = 0;
//
// 	MarketRate::MarketRate()
// 	{
// 		//if (properties == null)
// 		//{
// 		//    MarketRate.properties = MarketRate.type.GetRuntimeFields().ToArray();
// 		//}
// 	}
//
// 	MarketRate::MarketRate(const MarketRate &mr)
// 	{
// 		marketPairIndex = mr.marketPairIndex;
// 		askPrice = mr.askPrice;
// 		bidPrice = mr.bidPrice;
// 		lastMarketUpdate = mr.lastMarketUpdate;
// 	}
// 	//
// 	// MemoryMappedViewAccessor *MarketRate::ConfigureMarketRateStorage(const std::wstring &fileName, int marketCount, std::optional<MemoryMappedFileAccess> &fileAccess, bool initialSetup)
// 	// {
// 	// 	if (initialSetup)
// 	// 	{
// 	// 		int doubleSize = sizeof(double());
// 	// 		MarketCount = marketCount;
// 	// 		MarketRateState tempVar();
// 	// 		ObjectSize = System::Runtime::InteropServices::Marshal::SizeOf(&tempVar);
// 	// 		//ObjectOffset = ObjectSize * 61;
// 	// 		// LastIndex = ObjectSize * 60;
// 	// 		FileSize = marketCount * ObjectSize;
// 	//
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		auto tempFile = MemoryMappedFile::OpenExisting(fileName);
// 	// 		auto tempAccess = tempFile->CreateViewAccessor();
// 	//
// 	// 		MarketCount = marketCount;
// 	// 		MarketRateState tempVar2();
// 	// 		ObjectSize = System::Runtime::InteropServices::Marshal::SizeOf(&tempVar2);
// 	// 		//ObjectOffset = ObjectSize * 61;
// 	// 		// LastIndex = ObjectSize * 60;
// 	// 		FileSize = tempAccess->Capacity;
// 	// 		tempFile->Dispose();
// 	// 		tempAccess->Dispose();
// 	//
// 	// 	}
// 	//
// 	// 	if (dataFileMap == nullptr)
// 	// 	{
// 	// 		if (!fileAccess)
// 	// 		{
// 	// 			dataFileMap = MemoryMappedFile::CreateNew(fileName, FileSize, MemoryMappedFileAccess::Read, MemoryMappedFileOptions::None, HandleInheritability::None);
// 	//
// 	// 			return nullptr;
// 	// 		}
// 	// 		else if (fileAccess == MemoryMappedFileAccess::ReadWrite || fileAccess == MemoryMappedFileAccess::Write)
// 	// 		{
// 	// 			dataFileMap = MemoryMappedFile::CreateOrOpen(fileName, FileSize, fileAccess.value(), MemoryMappedFileOptions::None, HandleInheritability::Inheritable);
// 	// 		}
// 	// 		else
// 	// 		{
// 	// 			dataFileMap = MemoryMappedFile::OpenExisting(fileName, MemoryMappedFileRights::Read, HandleInheritability::Inheritable);
// 	// 		}
// 	// 	}
// 	//
// 	// 	return dataFileMap->CreateViewAccessor(0,FileSize,fileAccess.value());
// 	// }
//
// 	void MarketRate::LoadMarketArrayFromFile()//MemoryMappedViewAccessor *startAccessor, std::vector<MarketRate*> &marketRates)
// 	{
// 		// for (long long i = 0; i < MarketCount; ++i)
// 		// {
// 		// 	marketRates[i]->ReadMarketRate(startAccessor, i);
// 		// }
// 	}
// 	//
// 	// MemoryMappedViewAccessor *MarketRate::GetAddtionalAccessor(std::optional<MemoryMappedFileAccess> &fileAccess, std::optional<long long> &index)
// 	// {
// 	// 	if (!index)
// 	// 	{
// 	// 		return dataFileMap->CreateViewAccessor(0, FileSize, fileAccess.value());
// 	// 	}
// 	//
// 	// 	index = index * ObjectSize;
// 	//
// 	// 	return dataFileMap->CreateViewAccessor(index.value(), ObjectSize, fileAccess.value());
// 	// }
//
// 	void MarketRate::ReadMarketRate()//MemoryMappedViewAccessor *accessor, long long index)
// 	{
// 		// //long offset = second == null ? index * ObjectSize + LastIndex : index * ObjectOffset + second.Value * ObjectSize;
// 		// long long offset = index * ObjectSize;
// 		//
// 		// time_t newTime;
// 		// accessor->Read<DateTime>(offset, newTime);
// 		//
// 		// if (newTime != DateTime::MinValue && this->lastMarketUpdate >= newTime)
// 		// {
// 		// 	return false;
// 		// }
// 		//
// 		// //Console.WriteLine(newTime);
// 		// lastMarketUpdate = newTime;
// 		// offset += 8;
// 		// accessor->Read<int>(offset, this->marketPairIndex);
// 		// offset += 4;
// 		// accessor->Read<double>(offset, this->askPrice);
// 		// offset += 8;
// 		// accessor->Read<double>(offset, this->bidPrice);
// 		//
// 		// return true;
// 	}
//
//
// 	void MarketRate::SaveMarketRate()//MemoryMappedViewAccessor *accessor, long long index)
// 	{
// 		//long offset = second == null ? index * ObjectOffset + LastIndex : index * ObjectOffset + second.Value * ObjectSize;
// 		// long long offset = index * ObjectSize;
// 		//
// 		// accessor->Write<DateTime>(offset, this->lastMarketUpdate);
// 		// offset += 8;
// 		// accessor->Write<int>(offset, this->marketPairIndex);
// 		// offset += 4;
// 		// accessor->Write<double>(offset, this->askPrice);
// 		// offset += 8;
// 		// accessor->Write<double>(offset, this->bidPrice);
// 	}
// }
