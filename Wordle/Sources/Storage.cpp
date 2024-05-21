#include "../Headers/Storage.hpp"

Storage::Storage() 
{
	std::ifstream file_storage("storage.json");
	storage = json::parse(file_storage);
}

int Storage::getCountWords() 
{
	return storage["words"].size();
}

std::wstring Storage::getWord(int index)
{
	return convertor::stringToWstring(storage["words"][index]);
}
int Storage::getSizeAlphabet()
{
	return storage["size_alphabet"];
}
std::wstring Storage::getAlphabet() 
{
	return convertor::stringToWstring(storage["alphabet"]);
}