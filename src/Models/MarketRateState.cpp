export module MarketRateState;

namespace Robot::Common::Models
{
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Serializable][StructLayout(LayoutKind.Sequential)] public class MarketRateState
	export class MarketRateState
	{
	public:
		int marketPairIndex = 0;
		double askPrice = 0;
		double bidPrice = 0;
		DateTime lastMarketUpdate;
	};
}
