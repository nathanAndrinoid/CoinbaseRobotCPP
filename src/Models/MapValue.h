// ﻿#pragma once
//
// #include "Coin.h"
// #include <string>
// #include <unordered_map>
// #include <vector>
//
// using namespace Robot::Common::Models;
//
// namespace Robot::Common::Models
// {
// 	class MapValue
// 	{
// 	private:
// 		long long FileSize = 0;
// 		MemoryMappedFile *dataFileMap;
// 		MemoryMappedViewAccessor *accessor;
// 	public:
// 		std::unordered_map<int, long long> coinIndexDict;
// 	private:
// 		bool configured = false;
// 		int ObjectSize = 0;
//
// 	public:
// 		virtual ~MapValue()
// 		{
// 			delete dataFileMap;
// 			delete accessor;
// 		}
//
// 		MapValue(const std::wstring &fileName, int count, int size);
//
// 		void SetIdToIndexMap(std::unordered_map<int, long long> &cid);
//
// 		void SetIdToIndexMap(std::vector<Coin*> &coinArray, long long objSize);
//
// 		void GetValueByIndex(long long index, double &value);
//
// 		void GetValueById(int id, double &value);
//
// 		void SetValueByIndex(long long index, double value);
//
// 		void SetValueById(int id, double value);
//
// 		void GetValueArray(std::vector<double> &array);
//
// 		void SetValueArray(std::vector<double> &array);
//
// 	};
// }
