#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;


class Cell {

public:

	Cell(Vector2f position, Vector2f size);

	void draw(RenderWindow& window);

	void setText(Text text);

	Text getText();

	bool click(Vector2f position);

	void setStatus(int status);
	
	int getStatus();

	void setPosition(Vector2f position);

	Vector2f getPosition();

private:
	RectangleShape cell;

	int status;
	Text text;

	Vector2f position;
	Vector2f size;
};