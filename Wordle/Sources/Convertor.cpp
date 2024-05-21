#include "../Headers/Converter.hpp"

std::string convertor::wstringToString(std::wstring str)
{
	int size = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, nullptr, 0, nullptr, nullptr);
	std::string utf8Str(size, 0);
	WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, &utf8Str[0], size, nullptr, nullptr);
	return utf8Str;
}
std::wstring convertor::stringToWstring(const std::string str)
{
	int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	std::wstring wstr(size, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size);
	return wstr;
}