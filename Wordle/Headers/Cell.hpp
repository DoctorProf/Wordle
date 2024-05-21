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

	void setLetter(wchar_t letter);

	wchar_t getLetter();

	void setStatus(int status);
	
	int getStatus();

	void setPosition(Vector2f position);

	Vector2f getPosition();

private:
	RectangleShape cell;

	int status;
	Texture texture;
	wchar_t letter;

	Vector2f position;
	Vector2f size;
};