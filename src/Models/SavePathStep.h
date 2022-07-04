#pragma once

#include "PathStep.h"
#include <any>
#include <mutex>

namespace Robot::Common::Models
{
	class SavePathStep final
	{
	private:
		static MemoryMappedFile *dataFileMap;
		static MemoryMappedViewAccessor *accessor;
		static std::mutex accessControl;
		static long long ObjectSize;
		static long long FileSize;
		static double zero;
		static int noMarket;
		static long long offset;

	public:
		static void Init(std::any ac);

		static void ClearPath();

		static void GetPathStep(int index, double &value, int &market, int &orderSide, int &amountType, int &percision, int &toCoinId);

		static int GetIndex1();

		static int GetIndex2();

		static int GetIndex3();

		static int GetIndex4();

		static bool IsGreaterValue(double newValue);

		static void SetPathStep(int index, int market, int orderSide, int amountType, int percision, int toCoinId);

		static void SetPathStepEnd1();

		static void SetPathStepEnd2();

		static void SetPathStepEnd3();

		static void SetPathStepEnd4();

		static void SaveLinks0(PathStep *pathStep);

		static void SaveLinks1(PathStep *pathStep1);
		static void SaveLinks2(PathStep *pathStep);
		static void SaveLinks3(PathStep *pathStep);
		static void SaveLinks4(PathStep *pathStep);
	};
}
