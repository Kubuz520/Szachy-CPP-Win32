#pragma once

#include "TypEnum.h"

// Klasa Figury
class Figura {

protected:
	Typ typ;
	bool isWhite;
	int x;
	int y;

public: 
	virtual void Ruch() = 0;
	virtual void Bicie() = 0;

	void Show();
};

// Klasa Pustego Pola
class PustePole : public Figura {

public:
	PustePole(int x, int y);
	void Ruch();
	void Bicie();
};

// Klasa Pionka
class Pionek : public Figura {

private:
	bool FirstMove;

public:
	Pionek(int x, int y, bool isWhite);
	void Ruch();
	void Bicie();
};

// Klasa Skoczka
class Skoczek : public Figura {

public:
	Skoczek(int x, int y, bool isWhite);
	void Ruch();
	void Bicie();
};

// Klasa Wieży
class Wieza : public Figura {

private:
	bool FirstMove;

public:
	Wieza(int x, int y, bool isWhite);
	void Ruch();
	void Bicie();
};

// Klasa Gońca
class Goniec : public Figura {

public:
	Goniec(int x, int y, bool isWhite);
	void Ruch();
	void Bicie();
};

// Klasa Hetmana
class Hetman : public Figura {

private:
	bool FirstMove;

public:
	Hetman(int x, int y, bool isWhite);
	void Ruch();
	void Bicie();
};

// Klasa Króla
class Krol : public Figura {

private:
	bool FirstMove;

public:
	Krol(int x, int y, bool isWhite);
	void Ruch();
	void Bicie();
};