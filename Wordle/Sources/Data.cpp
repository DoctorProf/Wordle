#include "../Headers/Data.hpp"

std::vector<Texture> texture::letters;

Texture texture::EMPTY;
Texture texture::A;
Texture texture::B;
Texture texture::C;
Texture texture::D;
Texture texture::E;
Texture texture::F;
Texture texture::G;
Texture texture::H;
Texture texture::I;
Texture texture::J;
Texture texture::K;
Texture texture::L;
Texture texture::M;
Texture texture::N;
Texture texture::O;
Texture texture::P;
Texture texture::Q;
Texture texture::R;
Texture texture::S;
Texture texture::T;
Texture texture::U;
Texture texture::V;
Texture texture::W;
Texture texture::X;
Texture texture::Y;
Texture texture::Z;

void texture::loadTextures()
{
	EMPTY.loadFromFile("Resources/EMPTY.png");
	A.loadFromFile("Resources/A.png");
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
	Z.loadFromFile("Resources/Z.png");

	letters = {
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
	};
}