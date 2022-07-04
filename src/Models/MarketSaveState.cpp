export module MarketSaveState;

import MarketRateState;
import <vector>;

namespace Robot::Common::Models
{
	export class MarketSaveState
	{
	private:
		std::vector<MarketRateState*> marketRates;

	public:
		std::vector<MarketRateState*> getMarketRates() const
		{
			return marketRates;
		}
		void setMarketRates(const std::vector<MarketRateState*> &value)
		{
			marketRates = value;
		}
	};


}
