#pragma once
#include <ctime>

namespace Robot::Common::Models
{
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Serializable][StructLayout(LayoutKind.Sequential)] public class MarketRateState
	class MarketRateState
	{
	public:
		int marketPairIndex = 0;
		double askPrice = 0;
		double bidPrice = 0;
		time_t lastMarketUpdate;
	};
}
