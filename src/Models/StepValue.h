#pragma once

//#include "Coin.h"

namespace Robot::Common::Models
{
	class StepValue
	{
	public:
		double value = 0.0;
		//Coin *coin;
		virtual ~StepValue()
		{
		//	delete coin;
		}

	};
}
