#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Data.hpp"
#include "Headers/Cell.hpp"
#include <nlohmann/json.hpp>
#include <boost/random.hpp>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace sf;
using json = nlohmann::json;

std::string wstringToString(std::wstring str)
{
	int size = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, nullptr, 0, nullptr, nullptr);
	std::string utf8Str(size, 0);
	WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, &utf8Str[0], size, nullptr, nullptr);
	return utf8Str;
}
std::wstring stringToWstring(const std::string str)
{
	int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	std::wstring wstr(size, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size);
	return wstr;
}

void generateField(std::vector<std::vector<Cell*>>& cells) 
{
	Vector2f size_cell{ 100, 100 };
	for (int i = 0; i < 5; i++) 
	{
		cells.push_back(std::vector<Cell*>());
		for (int j = 0; j < 6; j++)
		{
			Cell* new_cell = new Cell(Vector2f(10 + j * size_cell.x + j * 10, 20 + i * size_cell.y + i * 10), size_cell);
			new_cell->setTexture(texture::letters[0]);
			cells[i].push_back(new_cell);
		}
	}
}

void generateButtons(std::vector<Cell*>& buttons, std::wstring alphabet)
{
	Vector2f size_cell{ 50, 50 };
	int k = 0;
	for (int i = 0; i < 32; i++)
	{
		Vector2f position{};
		if (i <= 10) 
		{
			position = Vector2f(10 + k * size_cell.x + k++ * 10, 600);
			if (i == 10) k = 0;
		}
		else if (i > 10 && i <= 19)
		{
			position =  Vector2f(70 + k * size_cell.x + k++ * 10, 670);
			if (i == 19) k = 0;
		}
		else if(i > 19 && i <= 26)
		{
			position = Vector2f(130 + k * size_cell.x + k++ * 10, 740);
			if (i == 26) k = 0;
		}
		else
		{
			position = Vector2f(190 + k * size_cell.x + k++ * 10, 810);
		}
		Cell* new_cell = new Cell(position, size_cell);
		new_cell->setTexture(texture::letters[i + 1]);
		new_cell->setLetter(alphabet[i]);
		buttons.push_back(new_cell);
	}
}

int main() 
{
	std::ifstream file_storage("storage.json");
	json storage = json::parse(file_storage);

	boost::random::mt19937 rng(time(NULL));

	boost::random::uniform_real_distribution<> dist(0, storage["words"].size());

	ContextSettings context;
	context.antialiasingLevel = 8;
	RenderWindow window(VideoMode(670, 900), "Wordle", Style::Titlebar, context);

	std::wstring word = stringToWstring(storage["words"][dist(rng)]);
	word.resize(6);
	std::wstring atteempt_word = L"";
	texture::loadTextures();

	std::vector<std::vector<Cell*>> cells;
	std::vector<Cell*> buttons;
	int attempt = 0;
	int click = 0;
	std::wstring alphabet = L"абвгдежзийклмнопрстуфхцчшщъыьэюя";

	generateField(cells);
	generateButtons(buttons, alphabet);

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) 
			{
				window.close();
			}
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) 
			{
				Vector2i mouse_position = Mouse::getPosition(window);

				for (int i = 0; i < buttons.size(); i++) 
				{
					if (buttons[i]->click(Vector2f(mouse_position)))
					{
						if (click >= 6 || attempt > 4) continue;
						cells[attempt][click]->setTexture(buttons[i]->getTexture());
						cells[attempt][click++]->setLetter(buttons[i]->getLetter());
						atteempt_word += buttons[i]->getLetter();
					}
				}
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
				if (click != 6) continue;
				for (int i = 0; i < 6; i++) 
				{
					if (cells[attempt][i]->getLetter() == word[i]) cells[attempt][i]->setStatus(1);
					else 
					{
						auto it = std::find_if(word.begin(), word.end(), [&](wchar_t letter) {
							return letter == cells[attempt][i]->getLetter();
							});

						if (it != word.end()) cells[attempt][i]->setStatus(3);
						else cells[attempt][i]->setStatus(2);
					}
				}
				for (int i = 0; i < buttons.size(); i++)
				{
					for (int j = 0; j < cells[attempt].size(); j++)
					{
						if (buttons[i]->getLetter() == cells[attempt][j]->getLetter()) buttons[i]->setStatus(cells[attempt][j]->getStatus());
					}
				}
				attempt++;
				click = 0;
				std::cout << (word == atteempt_word) << std::endl;
				if (word == atteempt_word) window.close();
				atteempt_word = L"";
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::BackSpace)
			{
				if (click == 0) continue;
				cells[attempt][--click]->setLetter(' ');
				cells[attempt][click]->setTexture(texture::letters[0]);
				atteempt_word[click] = wchar_t();
			}
		}

		window.clear(Color::Black);

		for (int i = 0; i < buttons.size(); i++)
		{
			buttons[i]->draw(window);
		}

		for (int i = 0; i < cells.size(); i++)
		{
			for (int j = 0; j < cells[i].size(); j++)
			{
				cells[i][j]->draw(window);
			}
		}
		
		window.display();
	}

	return 0;
}