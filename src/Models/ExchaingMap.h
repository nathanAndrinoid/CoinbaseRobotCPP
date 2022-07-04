#pragma once

#include "MarketPair.h"

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	class ExchaingMap
	{
	public:
		int marketId = 0;
		MarketPair *marketPair;
		bool Selling = false;
		virtual ~ExchaingMap()
		{
			delete marketPair;
		}

	};
}
