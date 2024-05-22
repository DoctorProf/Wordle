#include "../Headers/Cell.hpp"

Cell::Cell(Vector2f position, Vector2f size) 
{
	this->position = position + size / 2.0f;
	this->size = size;
	cell.setSize(size);
	cell.setPosition(position);
	this->status = 0;
	cell.setFillColor(Color(46, 46, 46));
}

void Cell::draw(RenderWindow& window) 
{
	if (status == 1) cell.setFillColor(Color::Green);
	if (status == 2) cell.setFillColor(Color::Blue);
	if (status == 3) cell.setFillColor(Color::Magenta);
	window.draw(cell);
	window.draw(text);
}

void Cell::setText(Text text) 
{
	this->text = text;
	FloatRect rect_text = this->text.getLocalBounds();
	this->text.setOrigin(Vector2f(rect_text.left + rect_text.getSize().x / 2, rect_text.top + rect_text.getSize().y / 2));
	this->text.setPosition(position);
}
Text Cell::getText() 
{
	return text;
}

bool Cell::click(Vector2f position)
{
	return (position.x > this->position.x - size.x / 2.0 && position.x < this->position.x + size.x / 2.0) &&
		(position.y > this->position.y - size.y / 2.0 && position.y < this->position.y + size.y / 2.0);
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

