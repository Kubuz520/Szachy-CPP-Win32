
#include "Figury.h"

#include "TypEnum.h"
#include "Global.h"
#include "Plansza.h"
#include <iostream>

int IsWhite(bool iswhite) {
	if (iswhite == true) {
		return -1;
	}
	else {
		return 1;
	}
}

bool isLegalMove(int x, int y) {
	// Implementacja sprawdzania legalności ruchu
	return true; // Placeholder
}

void AddToPossibleMoves(int x1, int y1) {
	if (x1 <= 7 && x1 >= 0 && y1 <= 7 && x1 >= 0) {
		PossibleMoves[ilosc] = new PossibleMove{ x1, y1, isLegalMove(x1,y1) };
		ilosc++;
	}
}


// Funkcje Klasy Figura ---
void Figura::Show() {
	std::cout << GetTyp(typ);
}

Typ Figura::GetType(int x1, int y1) {
	if (x1 <= 7 && x1 >= 0 && y1 <= 7 && x1 >= 0) {
		return typ;
	}
}

bool Figura::GetIsWhite(int x1, int y1) {
	if (x1 <= 7 && x1 >= 0 && y1 <= 7 && x1 >= 0) {
		return isWhite;
	}
}

// Funkcje Klasy PustePole ---
PustePole::PustePole(int x1, int y1) {
	typ = Typ::PUSTEPOLE;
	x1 = x;
	y1 = y;
}

void PustePole::Ruch(Figura* plansza[][8]) {
	// Implementacja ruchu
}


// Funkcje Klasy Pionek ---
Pionek::Pionek(int x1, int y1, bool isWhite1) {
	typ = Typ::PIONEK;
	FirstMove = true;
	x1 = x;
	y1 = y;
	isWhite1 = isWhite;
}

void Pionek::Ruch(Figura* plansza[][8]) {
	ilosc = 0;
	std::cout << "Ruch Pionka\n";
	if (FirstMove == true) {
		AddToPossibleMoves(x, y + (IsWhite(isWhite) * 2));
	}
	AddToPossibleMoves(x, y + IsWhite(isWhite));
}

void Pionek::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Skoczek ---
Skoczek::Skoczek(int x1, int y1, bool isWhite1) {
	typ = Typ::SKOCZEK;
	x1 = x;
	y1 = y;
	isWhite1 = isWhite;
}

void Skoczek::Ruch(Figura* plansza[][8]) {
	ilosc = 0;
	std::cout << "Ruch Skoczka\n";
	AddToPossibleMoves(x + 2, y + 1);
	AddToPossibleMoves(x + 2, y - 1);

	AddToPossibleMoves(x - 2, y + 1);
	AddToPossibleMoves(x - 2, y - 1);

	AddToPossibleMoves(x + 1, y + 2);
	AddToPossibleMoves(x - 1, y + 2);

	AddToPossibleMoves(x + 1, y - 2);
	AddToPossibleMoves(x - 1, y - 2);
}


// Funkcje Klasy Goniec ---
Goniec::Goniec(int x1, int y1, bool isWhite1) {
	typ = Typ::GONIEC;
	x1 = x;
	y1 = y;
	isWhite1 = isWhite;
}

void Goniec::Ruch(Figura* plansza[][8]) {
	// Implementacja ruchu
}


// Funkcje Klasy Wieza ---
Wieza::Wieza(int x1, int y1, bool isWhite1) {
	typ = Typ::WIEZA;
	FirstMove = true;
	x1 = x;
	y1 = y;
	isWhite1 = isWhite;
}

void Wieza::Ruch(Figura* plansza[][8]) {
	for (int i{1}; i < 8; i++) {
		if (plansza[x + i][y]->GetType(x+1,y) != Typ::PUSTEPOLE) {
			break;
		}
		AddToPossibleMoves(x + i, y);
		
	}
	for (int i{ 1 }; i < 8; i++) {
		if (plansza[x - i][y]->GetType(x-1,y) != Typ::PUSTEPOLE) {
			break;
		}
		AddToPossibleMoves(x - i, y);
	}
	for (int i{ 1 }; i < 8; i++) {
		if (plansza[x][y + 1]->GetType(x,y+1) != Typ::PUSTEPOLE) {
			break;
		}
		AddToPossibleMoves(x, y + i);
	}
	for (int i{ 1 }; i < 8; i++) {
		if (plansza[x][y - i]->GetType(x,y-1) != Typ::PUSTEPOLE) {
			break;
		}
		AddToPossibleMoves(x, y - i);
	}
}


// Funkcje Klasy Hetman ---
Hetman::Hetman(int x1, int y1, bool isWhite1) {
	typ = Typ::HETMAN;
	FirstMove = true;
	x1 = x;
	y1 = y;
	isWhite1 = isWhite;
}

void Hetman::Ruch(Figura* plansza[][8]) {
	// Implementacja ruchu
}


// Funkcje Klasy Krol ---
Krol::Krol(int x1, int y1, bool isWhite1) {
	typ = Typ::KROL;
	FirstMove = true;
	x1 = x;
	y1 = y;
	isWhite1 = isWhite;
}

void Krol::Ruch(Figura* plansza[][8]) {
	AddToPossibleMoves(x, y + 1);
	AddToPossibleMoves(x, y - 1);

	AddToPossibleMoves(x + 1, y);
	AddToPossibleMoves(x - 1, y);

	AddToPossibleMoves(x + 1, y + 1);
	AddToPossibleMoves(x - 1, y - 1);

	AddToPossibleMoves(x + 1, y - 1);
	AddToPossibleMoves(x - 1, y + 1);
}
