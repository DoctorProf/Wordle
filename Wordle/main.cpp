#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Data.hpp"
#include "Headers/Cell.hpp"
#include <nlohmann/json.hpp>
#include <boost/random.hpp>
#include <fstream>

using namespace sf;
using json = nlohmann::json;

void generateField(std::vector<std::vector<Cell*>>& cells) 
{
	Vector2f size_cell{ 100, 100 };
	for (int i = 0; i < 5; i++) 
	{
		cells.push_back(std::vector<Cell*>());
		for (int j = 0; j < 6; j++)
		{
			Cell* new_cell = new Cell(Vector2f(600 + j * size_cell.x + j * 10, 20 + i * size_cell.y + i * 10), size_cell);
			new_cell->setTexture(texture::letters[0]);
			cells[i].push_back(new_cell);
		}
	}
}

void generateButtons(std::vector<Cell*>& buttons, std::string alphabet)
{
	Vector2f size_cell{ 60, 60 };
	for (int i = 0; i < 26; i++)
	{
		Cell* new_cell = new Cell(Vector2f(60 + i * size_cell.x + i * 10, 800), size_cell);
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

	boost::random::uniform_real_distribution<> dist(0, 9);

	ContextSettings context;
	context.antialiasingLevel = 8;
	RenderWindow window(VideoMode(1920, 1080), "Wordle", Style::Fullscreen, context);

	std::string word = storage["words"][dist(rng)];

	texture::loadTextures();

	std::vector<std::vector<Cell*>> cells;
	std::vector<Cell*> buttons;
	int attempt = 0;
	int click = 0;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

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
						auto it = std::find_if(word.begin(), word.end(), [&](char letter) {
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
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::BackSpace)
			{
				if (click == 0) continue;
				click--;
			}
		}

		window.clear(Color::Color(149, 200, 216));

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