#pragma once

#include "Coin.h"
#include <string>

namespace Robot::Common::Models
{
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Serializable][StructLayout(LayoutKind.Sequential)] public class MarketPair
	class MarketPair
	{
	public:
		std::wstring Symbol;
		int Index = 0;
		void *BaseCurrency;
		void *QuoteCurrency;
		std::wstring BaseCurrencySymbol;
		int BasePrecision = 0;
		std::wstring QuoteCurrencySymbol;
		int QuotePrecision = 0;
		bool IsBusy = false;
		std::wstring Exchange;
		time_t LastOrderSearch;

		virtual ~MarketPair()
		{
			// delete (Coin*)BaseCurrency;
			// delete (Coin*)QuoteCurrency;
		}

		MarketPair();

		MarketPair(MarketPair *sourceMarket, bool clone = false);
	};
}
