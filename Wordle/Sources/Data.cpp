#include "../Headers/Data.hpp"

std::vector<Texture> texture::letters;

Texture texture::EMPTY;
//Texture texture::A;
//Texture texture::B;
//Texture texture::C;
//Texture texture::D;
//Texture texture::E;
//Texture texture::F;
//Texture texture::G;
//Texture texture::H;
//Texture texture::I;
//Texture texture::J;
//Texture texture::K;
//Texture texture::L;
//Texture texture::M;
//Texture texture::N;
//Texture texture::O;
//Texture texture::P;
//Texture texture::Q;
//Texture texture::R;
//Texture texture::S;
//Texture texture::T;
//Texture texture::U;
//Texture texture::V;
//Texture texture::W;
//Texture texture::X;
//Texture texture::Y;
//Texture texture::Z;
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
	/*A.loadFromFile("Resources/A.png");
	B.loadFromFile("Resources/B.png");
	C.loadFromFile("Resources/C.png");
	D.loadFromFile("Resources/D.png");
	E.loadFromFile("Resources/E.png");
	F.loadFromFile("Resources/F.png");
	G.loadFromFile("Resources/G.png");
	H.loadFromFile("Resources/H.png");
	I.loadFromFile("Resources/I.png");
	J.loadFromFile("Resources/J.png");
	K.loadFromFile("Resources/K.png");
	L.loadFromFile("Resources/L.png");
	M.loadFromFile("Resources/M.png");
	N.loadFromFile("Resources/N.png");
	O.loadFromFile("Resources/O.png");
	P.loadFromFile("Resources/P.png");
	Q.loadFromFile("Resources/Q.png");
	R.loadFromFile("Resources/R.png");
	S.loadFromFile("Resources/S.png");
	T.loadFromFile("Resources/T.png");
	U.loadFromFile("Resources/U.png");
	V.loadFromFile("Resources/V.png");
	W.loadFromFile("Resources/W.png");
	X.loadFromFile("Resources/X.png");
	Y.loadFromFile("Resources/Y.png");
	Z.loadFromFile("Resources/Z.png");*/
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
	
	/*letters = {
		EMPTY,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z
	};*/
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