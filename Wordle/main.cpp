#include <iostream>
#include "Headers/Game.hpp"

using namespace sf;

int main() 
{
	texture::loadTextures();

	ContextSettings context;
	context.antialiasingLevel = 8;
	RenderWindow window(VideoMode(670, 900), "Wordle", Style::Titlebar, context);

	Game game;

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
			{
				window.close();
			}
			game.checkEvents(event, window);
		}

		window.clear(Color::Black);

		for (int i = 0; i < game.getButtons().size(); i++)
		{
			game.getButtons()[i]->draw(window);
		}

		for (int i = 0; i < game.getCells().size(); i++)
		{
			for (int j = 0; j < game.getCells()[i].size(); j++)
			{
				game.getCells()[i][j]->draw(window);
			}
		}
		
		window.display();
	}

	return 0;
}