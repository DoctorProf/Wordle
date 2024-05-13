#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;


class Cell {

public:

	Cell(Vector2f position, Vector2f size);

	void draw(RenderWindow& window);

	void setTexture(Texture texture);

	Texture getTexture();

	bool click(Vector2f position);

	void setLetter(char letter);

	char getLetter();

	void setStatus(int status);
	
	int getStatus();

private:
	RectangleShape cell;

	int status;
	Texture texture;
	char letter;

	Vector2f position;
	Vector2f size;
};