#pragma once

#include "Coin.h"
#include <vector>

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	class CoinPathStore
	{
	public:
		std::vector<Coin*> coins;
	};
}
