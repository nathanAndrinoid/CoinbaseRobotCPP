export module Base26;

import <string>;
import <cctype>;
import stringbuilder;

namespace Robot::Common::Helpers
{
	export class Base26
	{
	public:
		static int GetIdFromStr(const std::wstring &str)
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
	};
}
