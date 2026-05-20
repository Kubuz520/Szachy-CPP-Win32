#pragma once

#include "TypEnum.h"

// Klasa Figury
class Figura {

protected:
	Typ typ{};
	bool isWhite{};
	int x{};
	int y{};

public: 
	virtual void Ruch(Figura* plansza[][8]) = 0;

	void Show();
	Typ GetType();
	bool GetIsWhite();
};

// Klasa Pustego Pola
class PustePole : public Figura {

public:
	PustePole(int x, int y);
	void Ruch(Figura* plansza[][8]);
};

// Klasa Pionka
class Pionek : public Figura {

private:
	bool FirstMove;

public:
	Pionek(int x, int y, bool isWhite);
	void Ruch(Figura* plansza[][8]);
	void Bicie();
};

// Klasa Skoczka
class Skoczek : public Figura {

public:
	Skoczek(int x, int y, bool isWhite);
	void Ruch(Figura* plansza[][8]);
};

// Klasa Wieży
class Wieza : public Figura {

public:
	bool HasMoved;

	Wieza(int x, int y, bool isWhite, bool hasmoved);
	void Ruch(Figura* plansza[][8]);
	bool GetHasMoved();
};

// Klasa Gońca
class Goniec : public Figura {

public:
	Goniec(int x, int y, bool isWhite);
	void Ruch(Figura* plansza[][8]);
};

// Klasa Hetmana
class Hetman : public Figura {

public:
	Hetman(int x, int y, bool isWhite);
	void Ruch(Figura* plansza[][8]);
};

// Klasa Króla
class Krol : public Figura {

public:
	bool HasMoved;

	Krol(int x, int y, bool isWhite, bool hasmoved);
	void Ruch(Figura* plansza[][8]);
	bool GetHasMoved();
};