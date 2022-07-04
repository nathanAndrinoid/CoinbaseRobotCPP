export module MarketPair;

import Coin;
import <string>;

namespace Robot::Common::Models
{
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Serializable][StructLayout(LayoutKind.Sequential)] public class MarketPair
	export class MarketPair
	{
	public:
		std::wstring Symbol;
		int Index = 0;
		Coin *BaseCurrency;
		Coin *QuoteCurrency;
		std::wstring BaseCurrencySymbol;
		int BasePrecision = 0;
		std::wstring QuoteCurrencySymbol;
		int QuotePrecision = 0;
		bool IsBusy = false;
		std::wstring Exchange;
		DateTime LastOrderSearch;

		virtual ~MarketPair()
		{
			delete BaseCurrency;
			delete QuoteCurrency;
		}

		MarketPair()
		{
		}

		MarketPair(MarketPair *sourceMarket, bool clone = false)
		{
			Index = sourceMarket->Index;
			Symbol = sourceMarket->Symbol;
			BaseCurrencySymbol = sourceMarket->BaseCurrencySymbol;
			QuoteCurrencySymbol = sourceMarket->QuoteCurrencySymbol;
			Exchange = sourceMarket->Exchange;
			IsBusy = sourceMarket->IsBusy;

			if (!clone)
			{
				BaseCurrency = sourceMarket->BaseCurrency;
				QuoteCurrency = sourceMarket->QuoteCurrency;
			}

		}
	};
}
