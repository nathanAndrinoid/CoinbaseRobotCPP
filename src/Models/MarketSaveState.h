#pragma once

#include "MarketRateState.h"
#include <vector>

namespace Robot::Common::Models
{
	class MarketSaveState
	{
	private:
		std::vector<MarketRateState*> marketRates;

	public:
		std::vector<MarketRateState*> getMarketRates() const;
		void setMarketRates(const std::vector<MarketRateState*> &value);
	};


}
