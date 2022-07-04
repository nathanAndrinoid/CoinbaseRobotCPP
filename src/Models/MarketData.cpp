export module MarketData;

import MarketPair;
import <string>;
import <vector>;
import <any>;
import <optional>;

namespace Robot::Common::Models
{
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Serializable][StructLayout(LayoutKind.Sequential)] public class MarketData
	export class MarketData
	{
	private:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [NonSerialized] private static MemoryMappedFile dataFileMap;
		static MemoryMappedFile *dataFileMap;
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [NonSerialized] private BinaryFormatter binaryFormatter;
		BinaryFormatter *binaryFormatter;
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [NonSerialized] private MemoryMappedViewStream stream;
		MemoryMappedViewStream *stream;

	public:
		long long FileSize = 0;
		std::vector<MarketPair*> MarketPairArray;

		virtual ~MarketData()
		{
			delete binaryFormatter;
			delete stream;
		}

		MarketData()
		{

		}

		MarketData(std::vector<MarketPair*> &marketPairArray)
		{
			this->MarketPairArray = marketPairArray;
		}

		void ConfigureMarketRateStorage(const std::wstring &fileName, std::optional<MemoryMappedFileAccess> &fileAccess = std::nullopt, bool initialSetup = false)
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

		void SaveMarketDataToMap()
		{
			binaryFormatter->Serialize(stream, this);
		}

		void LoadMarketDataToMap()
		{
			MarketData *md = std::any_cast<MarketData*>(binaryFormatter->Deserialize(stream));

			this->FileSize = md->FileSize;
			this->MarketPairArray = md->MarketPairArray;
		}

	};
}
