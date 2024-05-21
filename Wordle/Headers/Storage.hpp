#pragma once
#include "Converter.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

class Storage
{
public:

	Storage();
	int getCountWords();
	std::wstring getWord(int index);
	int getSizeAlphabet();
	std::wstring getAlphabet();

private:

	json storage;

};