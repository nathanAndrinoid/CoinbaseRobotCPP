export module CoinbaseRobotCpp;

import MarketRate;
import MarketRateState;
import Coin;
import MarketPair;
import MapValue;
import MarketData;
import <string>;
import <unordered_map>;
import <vector>;

using namespace Robot::Common::Models;

namespace CoinbaseRobotTranlator
{
	export class CoinbaseRobotCpp
	{
	private:
		int marketCount = 0;
		bool Running = false;
		DateTime appStartTime;
		CancellationTokenSource *tokenSource;
		CancellationToken ct;
		std::unordered_map<std::wstring, MarketRate*> marketRateDict;
		MarketRateState *marketRateState;
		std::vector<Coin*> coins;
		std::unordered_map<int, Coin*> coinDict;
		std::unordered_map<int, Coin*> tempCoinDict;
		std::unordered_map<int, MarketPair*> marketDict;
		std::vector<MarketPair*> marketPairArray;
		BinaryFormatter *binaryFormatter;
		MapValue *dValueMap;
		std::vector<MarketRate*> marketRates;
		MarketData *marketData;
		std::vector<Coin*> coinArray;
//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static ManualResetEvent *const ExitEvent = new ManualResetEvent(false);

//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const std::wstring API_KEY = L"2e506aa3ec83fb4164e50b79ff0a7fd4";
//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const std::wstring API_SECRET = L"YN3Zf9zH+zdi53MiKBmjWq267/j+BZQkVt/RXUNyTW+jj2TzT5m58XgTuH1LAvzApvQeaOPkZ7aOhu5WkS828A==";
//C# TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const std::wstring API_PASSPHRASE = L"tzi4cbvjyt";

	public:
		virtual ~CoinbaseRobotCpp()
		{
			delete tokenSource;
			delete marketRateState;
			delete binaryFormatter;
			delete dValueMap;
			delete marketData;
		}

		CoinbaseRobotCpp()
		{

		}
	};
}
