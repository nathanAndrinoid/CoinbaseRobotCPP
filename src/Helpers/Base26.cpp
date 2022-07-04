#include "Base26.h"

namespace Robot::Common::Helpers
{

	int Base26::GetIdFromStr(const std::wstring &str)
	{
		std::wstring cleanStr = std::wstring(str.Where([&] (std::any c)
		{
			return std::isalpha(c);
		})->Select([&] (std::any c)
		{
			return std::tolower(c);
		})->ToArray());

		if (cleanStr.length() > 5)
		{
			cleanStr = cleanStr.substr(0, 5);
		}

		StringBuilder *sb = new StringBuilder();

		int num1 = static_cast<int>(L'a');
		int diff = num1 - 1;

		for (auto c : cleanStr)
		{
			int num = static_cast<int>(c);
			sb->append(num - diff);
		}

		delete sb;
		return std::stoi(sb->toString());
	}
}
