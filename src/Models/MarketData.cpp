#include "MarketData.h"

namespace Robot::Common::Models
{

MemoryMappedFile *MarketData::dataFileMap;

	MarketData::MarketData()
	{

	}

	MarketData::MarketData(std::vector<MarketPair*> &marketPairArray)
	{
		this->MarketPairArray = marketPairArray;
	}

	void MarketData::ConfigureMarketRateStorage(const std::wstring &fileName, std::optional<MemoryMappedFileAccess> &fileAccess, bool initialSetup)
	{
		binaryFormatter = new BinaryFormatter();

		if (dataFileMap == nullptr)
		{
			if (initialSetup)
			{

				Stream *fs = new MemoryStream();

				binaryFormatter->Serialize(fs, this);

				FileSize = fs->Length;

//C# TO C++ CONVERTER TODO TASK: A 'delete fs' statement was not added since fs was passed to a method or constructor. Handle memory management manually.
			}
			else
			{
				auto tempFile = MemoryMappedFile::OpenExisting(fileName);
				auto tempAccess = tempFile->CreateViewAccessor();

				FileSize = tempAccess->Capacity;

				tempAccess->Dispose();
				tempFile->Dispose();

			}
			if (!fileAccess)
			{
				dataFileMap = MemoryMappedFile::CreateNew(fileName, FileSize, MemoryMappedFileAccess::Read, MemoryMappedFileOptions::None, HandleInheritability::None);
			}
			else if (fileAccess == MemoryMappedFileAccess::ReadWrite || fileAccess == MemoryMappedFileAccess::Write)
			{
				dataFileMap = MemoryMappedFile::CreateOrOpen(fileName, FileSize, fileAccess.value(), MemoryMappedFileOptions::None, HandleInheritability::Inheritable);
			}
			else
			{
				dataFileMap = MemoryMappedFile::OpenExisting(fileName, MemoryMappedFileRights::Read, HandleInheritability::Inheritable);
			}
		}

		stream = dataFileMap->CreateViewStream();
	}

	void MarketData::SaveMarketDataToMap()
	{
		binaryFormatter->Serialize(stream, this);
	}

	void MarketData::LoadMarketDataToMap()
	{
		MarketData *md = std::any_cast<MarketData*>(binaryFormatter->Deserialize(stream));

		this->FileSize = md->FileSize;
		this->MarketPairArray = md->MarketPairArray;
	}
}
