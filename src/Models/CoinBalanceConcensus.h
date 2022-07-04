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
// 	class CoinBalanceConcensus final
// 	{
// 	private:
// 		static MemoryMappedFile *consensusFileMap;
// 		static MemoryMappedViewAccessor *consensusAccessorRead;
// 		static MemoryMappedViewAccessor *consensusAccessorWrite;
// 		static std::unordered_map<int, int> coinIndexDict;
// 		static int CoinCount;
//
// 	public:
// 		static void InitCoinBalanceConcensus(const std::wstring &fileName, int cc, std::unordered_map<int, int> &cid, std::vector<Coin*> &ca = std::vector<Coin*>());
//
// 		static bool ValidateConsensusRequest();
//
// 		static void SendActualValue();
//
// 		static double GetValidatedValueById(int id);
//
// 		static void RespondToValueRequest();
//
// 		static double GetValidatedValueByIndex(int coinIndex);
//
// 		static void SetConsensusFlag(int requestFlag);
//
// 		static void SetConsensusById(int id, double amount);
//
// 		static void SetConsensusByIndex(int index, double amount);
// 	};
// }
