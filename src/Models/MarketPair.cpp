#include "MarketPair.h"

namespace Robot::Common::Models
{

	MarketPair::MarketPair()
	{
	}

	MarketPair::MarketPair(MarketPair *sourceMarket, bool clone)
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
}
