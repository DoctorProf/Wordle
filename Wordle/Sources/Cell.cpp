#include "../Headers/Cell.hpp"

Cell::Cell(Vector2f position, Vector2f size) 
{
	this->position = position + size / 2.0f;
	this->size = size;
	cell.setSize(size);
	cell.setPosition(position);
	this->status = 0;
	this->texture = Texture();
	this->letter = ' ';
}

void Cell::draw(RenderWindow& window) 
{
	if (status == 0) cell.setFillColor(Color::White);
	if (status == 1) cell.setFillColor(Color::Green);
	if (status == 2) cell.setFillColor(Color::Blue);
	if (status == 3) cell.setFillColor(Color::Yellow);
	cell.setTexture(&texture);
	window.draw(cell);
}

void Cell::setTexture(Texture texture) 
{
	this->texture = texture;
}

Texture Cell::getTexture() 
{
	return texture;
}

bool Cell::click(Vector2f position)
{
	return (position.x > this->position.x - size.x / 2.0 && position.x < this->position.x + size.x / 2.0) &&
		(position.y > this->position.y - size.y / 2.0 && position.y < this->position.y + size.y / 2.0);
}
void Cell::setLetter(wchar_t letter)
{
	this->letter = letter;
}

wchar_t Cell::getLetter()
{
	return letter;
}

void Cell::setStatus(int status) 
{
	this->status = status;
}

int Cell::getStatus()
{
	return status;
}

void Cell::setPosition(Vector2f position) 
{
	cell.setPosition(position);
	this->position = position + size / 2.0f;
}

Vector2f Cell::getPosition()
{
	return position - size / 2.0f;
}

