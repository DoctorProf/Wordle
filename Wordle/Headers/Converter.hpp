#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

namespace convertor 
{
	std::string wstringToString(std::wstring str);

	std::wstring stringToWstring(const std::string str);
}