#include "../Headers/Data.hpp"

Font data::font;

void data::loadFont()
{
	font.loadFromFile("C:/WINDOWS/Fonts/Arial.ttf");
}

void data::setStyleText(Text& text, int size) 
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(Color::White);
}