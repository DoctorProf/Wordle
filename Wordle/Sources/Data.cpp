#include "../Headers/Data.hpp"

std::vector<Texture> texture::letters;

Texture texture::EMPTY;
Texture texture::À;
Texture texture::Á;
Texture texture::Â;
Texture texture::Ã;
Texture texture::Ä;
Texture texture::Å;
Texture texture::Æ;
Texture texture::Ç;
Texture texture::È;
Texture texture::É;
Texture texture::Ê;
Texture texture::Ë;
Texture texture::Ì;
Texture texture::Í;
Texture texture::Î;
Texture texture::Ï;
Texture texture::Ð;
Texture texture::Ñ;
Texture texture::Ò;
Texture texture::Ó;
Texture texture::Ô;
Texture texture::Õ;
Texture texture::Ö;
Texture texture::×;
Texture texture::Ø;
Texture texture::Ù;
Texture texture::Ú;
Texture texture::Û;
Texture texture::Ü;
Texture texture::Ý;
Texture texture::Þ;
Texture texture::ß;

void texture::loadTextures()
{
	EMPTY.loadFromFile("Resources/EMPTY.png");
	À.loadFromFile("Resources/À.png");
	Á.loadFromFile("Resources/Á.png");
	Â.loadFromFile("Resources/Â.png");
	Ã.loadFromFile("Resources/Ã.png");
	Ä.loadFromFile("Resources/Ä.png");
	Å.loadFromFile("Resources/Å.png");
	Æ.loadFromFile("Resources/Æ.png");
	Ç.loadFromFile("Resources/Ç.png");
	È.loadFromFile("Resources/È.png");
	É.loadFromFile("Resources/É.png");
	Ê.loadFromFile("Resources/Ê.png");
	Ë.loadFromFile("Resources/Ë.png");
	Ì.loadFromFile("Resources/Ì.png");
	Í.loadFromFile("Resources/Í.png");
	Î.loadFromFile("Resources/Î.png");
	Ï.loadFromFile("Resources/Ï.png");
	Ð.loadFromFile("Resources/Ð.png");
	Ñ.loadFromFile("Resources/Ñ.png");
	Ò.loadFromFile("Resources/Ò.png");
	Ó.loadFromFile("Resources/Ó.png");
	Ô.loadFromFile("Resources/Ô.png");
	Õ.loadFromFile("Resources/Õ.png");
	Ö.loadFromFile("Resources/Ö.png");
	×.loadFromFile("Resources/×.png");
	Ø.loadFromFile("Resources/Ø.png");
	Ù.loadFromFile("Resources/Ù.png");
	Ú.loadFromFile("Resources/Ú.png");
	Û.loadFromFile("Resources/Û.png");
	Ü.loadFromFile("Resources/Ü.png");
	Ý.loadFromFile("Resources/Ý.png");
	Þ.loadFromFile("Resources/Þ.png");
	ß.loadFromFile("Resources/ß.png");

	letters = {
		EMPTY,
		À,
		Á,
		Â,
		Ã,
		Ä,
		Å,
		Æ,
		Ç,
		È,
		É,
		Ê,
		Ë,
		Ì,
		Í,
		Î,
		Ï,
		Ð,
		Ñ,
		Ò,
		Ó,
		Ô,
		Õ,
		Ö,
		×,
		Ø,
		Ù,
		Ú,
		Û,
		Ü,
		Ý,
		Þ,
		ß
	};
}