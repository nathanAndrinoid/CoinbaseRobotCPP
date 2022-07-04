export module MarketLevel;

import Coin;

namespace Robot::Common::Models
{
	export class MarketLevel
	{
	public:
		double value = 0.0;
		Coin *cStart;
		Coin *cEnd;
		virtual ~MarketLevel()
		{
			delete cStart;
			delete cEnd;
		}

	};
}
