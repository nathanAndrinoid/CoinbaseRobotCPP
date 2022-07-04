export module ExchaingMap;

import MarketPair;

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	export class ExchaingMap
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
