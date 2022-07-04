#pragma once

#include "MarketPair.h"
#include <string>
#include <vector>
#include <any>
#include <optional>

namespace Robot::Common::Models
{
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Serializable][StructLayout(LayoutKind.Sequential)] public class MarketData
	class MarketData
	{
	private:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [NonSerialized] private static MemoryMappedFile dataFileMap;
		//static MemoryMappedFile *dataFileMap;
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [NonSerialized] private BinaryFormatter binaryFormatter;
		//BinaryFormatter *binaryFormatter;
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [NonSerialized] private MemoryMappedViewStream stream;
		//MemoryMappedViewStream *stream;

	public:
		long long FileSize = 0;
		std::vector<MarketPair*> MarketPairArray;

		virtual ~MarketData()
		{
			// delete binaryFormatter;
			// delete stream;
		}

		MarketData();

		MarketData(std::vector<MarketPair*> &marketPairArray);

		void ConfigureMarketRateStorage();//const std::wstring &fileName, std::optional<MemoryMappedFileAccess> &fileAccess = std::nullopt, bool initialSetup = false);

		void SaveMarketDataToMap();

		void LoadMarketDataToMap();

	};
}
