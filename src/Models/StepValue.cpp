export module StepValue;

import Coin;

using namespace Robot::Common::Models;

namespace App1::Models
{
	export class StepValue
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
