#include "CoinbaseRobotCpp.h"

using namespace Robot::Common::Models;

namespace CoinbaseRobotTranlator
{

ManualResetEvent *const CoinbaseRobotCpp::ExitEvent = new ManualResetEvent(false);
const std::wstring CoinbaseRobotCpp::API_KEY = L"2e506aa3ec83fb4164e50b79ff0a7fd4";
const std::wstring CoinbaseRobotCpp::API_SECRET = L"YN3Zf9zH+zdi53MiKBmjWq267/j+BZQkVt/RXUNyTW+jj2TzT5m58XgTuH1LAvzApvQeaOPkZ7aOhu5WkS828A==";
const std::wstring CoinbaseRobotCpp::API_PASSPHRASE = L"tzi4cbvjyt";

	CoinbaseRobotCpp::CoinbaseRobotCpp()
	{

	}
}
