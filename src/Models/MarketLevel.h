#pragma once

#include "Coin.h"

namespace Robot::Common::Models
{
	class MarketLevel
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
