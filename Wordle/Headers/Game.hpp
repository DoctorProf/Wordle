#pragma once
#include "Cell.hpp"
#include "Generator.hpp"
#include "Data.hpp"
#include "Storage.hpp"

class Game 
{
public:

	Game();
	void generateField();
	void generateButtons();
	void generateCells();
	void checkEvents(Event& event, RenderWindow& window);

	std::vector<std::vector<Cell*>>& getCells();
	std::vector<Cell*>& getButtons();

	void restartGame();

private:

	Storage storage;

	std::wstring word;
	std::wstring attempt_word;
	std::wstring alphabet;

	std::vector<std::vector<Cell*>> cells;
	std::vector<Cell*> buttons;

	int attempt;
	int current_letter;
};
