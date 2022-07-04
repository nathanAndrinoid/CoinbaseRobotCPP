#pragma once

#include <string>
#include <vector>

namespace Robot::Common::Helpers
{
	class ProcessHelper
	{

	public:
		std::wstring GetProcessOwner(int processId);

		/// <summary>
		/// Kill processes if they meet the parameter values of process name, owner name, expired started times.
		/// </summary>
		/// <param name="ProcessName">Process Name, case sensitive, for emample "EXCEL" could not be "excel"</param>
		/// <param name="ProcessUserName">Owner name or user name of the process, casse sensitive</param>
		/// <param name="HasStartedForHours">if process has started for more than n (parameter input) hours. 0 means regardless how many hours ago</param>
		void KillProcessByNameAndUser(const std::wstring &ProcessName, const std::wstring &ProcessUserName, int HasStartedForHours = 99999);
	};
}
