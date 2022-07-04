#include "MarketSaveState.h"

namespace Robot::Common::Models
{

	std::vector<MarketRateState*> MarketSaveState::getMarketRates() const
	{
		return marketRates;
	}

	void MarketSaveState::setMarketRates(const std::vector<MarketRateState*> &value)
	{
		marketRates = value;
	}
}
