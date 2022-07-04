export module MapValue;

import Coin;
import <string>;
import <unordered_map>;
import <vector>;

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	export class MapValue
	{
	private:
		long long FileSize = 0;
		MemoryMappedFile *dataFileMap;
		MemoryMappedViewAccessor *accessor;
	public:
		std::unordered_map<int, long long> coinIndexDict;
	private:
		bool configured = false;
		int ObjectSize = 0;

	public:
		virtual ~MapValue()
		{
			delete dataFileMap;
			delete accessor;
		}

		MapValue(const std::wstring &fileName, int count, int size)
		{
			if (configured)
			{
				return;
			}

			configured = true;
			ObjectSize = size;
			FileSize = count * ObjectSize;

			dataFileMap = MemoryMappedFile::CreateOrOpen(fileName, FileSize + 100000, MemoryMappedFileAccess::ReadWrite, MemoryMappedFileOptions::None, HandleInheritability::Inheritable);

			accessor = dataFileMap->CreateViewAccessor(0, FileSize, MemoryMappedFileAccess::ReadWrite);

		}

		void SetIdToIndexMap(std::unordered_map<int, long long> &cid)
		{
			coinIndexDict = std::unordered_map<int, long long>();

			for (auto c : cid)
			{
				coinIndexDict.emplace(c.Key, static_cast<long long>(c.Value));
			}
		}

		void SetIdToIndexMap(std::vector<Coin*> &coinArray, long long objSize)
		{
			coinIndexDict = std::unordered_map<int, long long>();

			for (int i = 0; i < coinArray.size(); i++)
			{
				coinIndexDict.emplace(coinArray[i]->Id, i * ObjectSize);
			}
		}

		void GetValueByIndex(long long index, double &value)
		{
			accessor->Read<double>(index * ObjectSize, value);
		}

		void GetValueById(int id, double &value)
		{
			accessor->Read<double>(coinIndexDict[id], value);
		}

		void SetValueByIndex(long long index, double value)
		{
			accessor->Write(index, value);
		}

		void SetValueById(int id, double value)
		{
			accessor->Write<double>(coinIndexDict[id], value);
		}

		void GetValueArray(std::vector<double> &array)
		{
			for (int i = 0, j = 0; i < coinIndexDict.size(); ++i, j += ObjectSize)
			{
				accessor->Read(j, array[i]);
			}
		}

		void SetValueArray(std::vector<double> &array)
		{
			for (int i = 0, j = 0; i < coinIndexDict.size(); ++i, j += ObjectSize)
			{
				accessor->Write(j, array[i]);
			}
		}

	};
}
