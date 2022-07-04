#pragma once

#include <string>
#include <cctype>
#include "../stringbuilder.h"

namespace Robot::Common::Helpers
{
	class Base26
	{
	public:
		static int GetIdFromStr(const std::wstring &str);
	};
}
