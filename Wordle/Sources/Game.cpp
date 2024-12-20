#include "../Headers/Game.hpp"

Game::Game() 
{
	word = storage.getWord(generator::generateNumber(0, storage.getCountWords()));
	word.resize(6);
	attempt_word = L"";
	alphabet = storage.getAlphabet();
	attempt = 0;
	current_letter = 0;
	generateCells();
}

void Game::generateField()
{
	Vector2f size_cell{ 100, 100 };
	for (int i = 0; i < 5; i++)
	{
		cells.push_back(std::vector<Cell*>());
		for (int j = 0; j < 6; j++)
		{
			Cell* new_cell = new Cell(Vector2f(10 + j * size_cell.x + j * 10, 20 + i * size_cell.y + i * 10), size_cell);
			cells[i].push_back(new_cell);
		}
	}
}

void Game::generateButtons()
{
	Vector2f size_cell{ 50, 50 };
	int k = 0;
	for (int i = 0; i < storage.getSizeAlphabet(); i++)
	{
		Vector2f position{};
		if (i <= 10)
		{
			position = Vector2f(10 + k * size_cell.x + k++ * 10, 600);
			if (i == 10) k = 0;
		}
		else if (i > 10 && i <= 19)
		{
			position = Vector2f(70 + k * size_cell.x + k++ * 10, 670);
			if (i == 19) k = 0;
		}
		else if (i > 19 && i <= 26)
		{
			position = Vector2f(130 + k * size_cell.x + k++ * 10, 740);
			if (i == 26) k = 0;
		}
		else
		{
			position = Vector2f(190 + k * size_cell.x + k++ * 10, 810);
		}
		Cell* new_cell = new Cell(position, size_cell);
		Text new_text;
		data::setStyleText(new_text, 24);
		new_text.setString(alphabet[i]);
		new_cell->setText(new_text);
		buttons.push_back(new_cell);
	}
}

void Game::generateCells()
{
	cells.clear();
	buttons.clear();
	generateField();
	generateButtons();
}

void Game::checkEvents(Event& event, RenderWindow& window)
{
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
	{
		Vector2i mouse_position = Mouse::getPosition(window);

		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i]->click(Vector2f(mouse_position)))
			{
				if (current_letter >= 6 || attempt > 4) continue;
				cells[attempt][current_letter++]->setText(buttons[i]->getText());
				attempt_word += buttons[i]->getText().getString();
			}
		}
	}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
	{
		if (current_letter != 6) return;

		for (int i = 0; i < 6; i++)
		{
			if (cells[attempt][i]->getText().getString() == word[i]) cells[attempt][i]->setStatus(1);
			else
			{
				auto it = std::find_if(word.begin(), word.end(), [&](wchar_t letter) {
					return letter == cells[attempt][i]->getText().getString();
					});

				if (it != word.end()) cells[attempt][i]->setStatus(3);
				else cells[attempt][i]->setStatus(2);
			}
		}
		for (int i = 0; i < buttons.size(); i++)
		{
			for (int j = 0; j < cells[attempt].size(); j++)
			{
				if (buttons[i]->getText().getString() == cells[attempt][j]->getText().getString()) buttons[i]->setStatus(cells[attempt][j]->getStatus());
			}
		}
		attempt++;
		current_letter = 0;
		if (word != attempt_word && attempt == 5) window.setTitle(word);
	}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::BackSpace)
	{
		Text empty_text;
		if (current_letter == 0) return;
		cells[attempt][--current_letter]->setText(empty_text);
		attempt_word[current_letter] = wchar_t();
	}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
	{
		window.setTitle("Wordle");
		restartGame();
	}
}

std::vector<std::vector<Cell*>>& Game::getCells() 
{
	return cells;
}
std::vector<Cell*>& Game::getButtons() 
{
	return buttons;
}

void Game::restartGame() 
{
	generateCells();
	word = storage.getWord(generator::generateNumber(0, storage.getCountWords()));
	word.resize(6);
	attempt_word = L"";
	attempt = 0;
	current_letter = 0;
}