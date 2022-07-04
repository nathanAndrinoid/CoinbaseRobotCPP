export module ProcessHelper;

import <string>;
import <vector>;
import stringhelper;

namespace Robot::Common::Helpers
{
	export class ProcessHelper
	{

	public:
		std::wstring GetProcessOwner(int processId)
		{
			std::wstring query = L"Select * From Win32_Process Where ProcessID = " + std::to_wstring(processId);
			ManagementObjectSearcher *searcher = new ManagementObjectSearcher(query);
			ManagementObjectCollection *processList = searcher->Get();

			for (auto obj : *processList)
			{
				std::vector<std::wstring> argList = {L"", L""};
				int returnVal = static_cast<int>(obj->InvokeMethod(L"GetOwner", argList));
				if (returnVal == 0)
				{
					delete searcher;
					return argList[1] + L"\\" + argList[0]; // return DOMAIN\user
				}
			}

			delete searcher;
			return L"NO OWNER";
		}

		/// <summary>
		/// Kill processes if they meet the parameter values of process name, owner name, expired started times.
		/// </summary>
		/// <param name="ProcessName">Process Name, case sensitive, for emample "EXCEL" could not be "excel"</param>
		/// <param name="ProcessUserName">Owner name or user name of the process, casse sensitive</param>
		/// <param name="HasStartedForHours">if process has started for more than n (parameter input) hours. 0 means regardless how many hours ago</param>
		void KillProcessByNameAndUser(const std::wstring &ProcessName, const std::wstring &ProcessUserName, int HasStartedForHours = 99999)
		{
			std::vector<Process*> foundProcesses = Process::GetProcessesByName(ProcessName);

			std::wstring strMessage = L"";
			for (auto p : foundProcesses)
			{
				std::wstring UserName = GetProcessOwner(p->Id);
//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
				strMessage = StringHelper::formatSimple(L"Process Name: {0} | Process ID: {1} | User Name : {2} | StartTime {3}", std::vector<std::wstring> {p->ProcessName, std::to_wstring(p->Id), UserName, p->StartTime.ToString()});

				bool TimeExpired = (p->StartTime.AddHours(HasStartedForHours) < DateTime::Now) || HasStartedForHours == 0;
				bool PrcoessUserName_Is_Matched = UserName == ProcessUserName;

				if ((StringHelper::toLower(ProcessUserName) == L"all" && TimeExpired) || PrcoessUserName_Is_Matched && TimeExpired)
				{
					p->Kill();
				}
			}
		}
	};
}
