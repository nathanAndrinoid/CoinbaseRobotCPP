export module CoinPathStore;

import Coin;
import <vector>;

using namespace Robot::Common::Models;

namespace Robot::Common::Models
{
	export class CoinPathStore
	{
	public:
		std::vector<Coin*> coins;
	};
}
