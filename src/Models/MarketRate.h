// ﻿#pragma once
//
// #include "MarketRateState.h"
// #include <string>
// #include <vector>
// #include <optional>
//
// namespace Robot::Common::Models
// {
// 	class MarketRate : public MarketRateState
// 	{
// 	private:
// 		//static MemoryMappedFile *dataFileMap;
// 	public:
// 		static int MarketCount;
// 		static long long ObjectSize;
// 		//public static long LastIndex;
// 		//public static long ObjectOffset;
// 		static long long FileSize;
// 		long long Position = 0;
// 		//public bool Updated;
//
// 		//private static Type type = typeof(MarketRateState);
// 		//private static FieldInfo[]? properties;
//
// 		MarketRate();
//
// 		MarketRate(const MarketRate &mr);
//
// 		//MemoryMappedViewAccessor *ConfigureMarketRateStorage(const std::wstring &fileName, int marketCount, std::optional<MemoryMappedFileAccess> &fileAccess = std::nullopt, bool initialSetup = false);
//
// 		void LoadMarketArrayFromFile();//MemoryMappedViewAccessor *startAccessor, std::vector<MarketRate*> &marketRates);
//
// 		//MemoryMappedViewAccessor *GetAddtionalAccessor(std::optional<MemoryMappedFileAccess> &fileAccess = std::nullopt, std::optional<long long> &index = std::nullopt);
//
// 		bool ReadMarketRate();//MemoryMappedViewAccessor *accessor, long long index); //, long? second = null)
//
// 		void SaveMarketRate();//MemoryMappedViewAccessor *accessor, long long index); //, long? second = null)
//
// 	};
// }
