#pragma once

#include "Coin.h"

using namespace Robot::Common::Models;

namespace App1::Models
{
	class StepValue
	{
	public:
		double value = 0.0;
		Coin *coin;
		virtual ~StepValue()
		{
			delete coin;
		}

	};
}
