
#include "Figury.h"

#include "TypEnum.h"
#include "Global.h"
#include "Plansza.h"
#include <iostream>

int FuncIsWhite(bool iswhite) {
	if (iswhite == true) {
		return -1;
	}
	else {
		return 1;
	}
}

bool isLegalMove(int x, int y, bool IsSetFiguraWhite, Figura* plansza[][8]) {
	if (plansza[x][y]->GetType() == Typ::PUSTEPOLE) {
		return true;
	}
	else if (plansza[x][y]->GetIsWhite() != IsSetFiguraWhite) {
		return true;
	}
	else {
		return false;
	}
}

void AddToPossibleMoves(int x1, int y1) {
	PossibleMoves[ilosc] = new PossibleMove{ x1, y1};
	ilosc++;
}

bool IsMoveOnBoard(int x1, int y1) {
	if (x1 <= 7 && x1 >= 0 && y1 <= 7 && y1 >= 0) {
		return true;
	}
	else {
		return false;
	}
}

void VerticalHorizontalMove(int x, int y, bool isWhite, Figura* plansza[][8]) {
	for (int i{ 1 }; i < 8; i++) {
		if (IsMoveOnBoard(x + i, y) == false) {
			break;
		}
		if (isLegalMove(x + i, y, isWhite, plansza) == false) {
			break;
		}
		AddToPossibleMoves(x + i, y);
		if (plansza[x + i][y]->GetType() != Typ::PUSTEPOLE) {
			break;
		}

	}
	for (int i{ 1 }; i < 8; i++) {
		if (IsMoveOnBoard(x - i, y) == false) {
			break;
		}
		if (isLegalMove(x - i, y, isWhite, plansza) == false) {
			break;
		}
		AddToPossibleMoves(x - i, y);
		if (plansza[x - i][y]->GetType() != Typ::PUSTEPOLE) {
			break;
		}
	}
	for (int i{ 1 }; i < 8; i++) {
		if (IsMoveOnBoard(x, y + i) == false) {
			break;
		}
		if (isLegalMove(x, y + i, isWhite, plansza) == false) {
			break;
		}
		AddToPossibleMoves(x, y + i);
		if (plansza[x][y + i]->GetType() != Typ::PUSTEPOLE) {
			break;
		}
	}
	for (int i{ 1 }; i < 8; i++) {
		if (IsMoveOnBoard(x, y - i) == false) {
			break;
		}
		if (isLegalMove(x, y - i, isWhite, plansza) == false) {
			break;
		}
		AddToPossibleMoves(x, y - i);
		if (plansza[x][y - i]->GetType() != Typ::PUSTEPOLE) {
			break;
		}
	}
}

// Funkcje Klasy Figura ---
void Figura::Show() {
	std::cout << GetTyp(typ);
}

Typ Figura::GetType() {
	return typ;
}

bool Figura::GetIsWhite() {
	return isWhite;
}

// Funkcje Klasy PustePole ---
PustePole::PustePole(int x1, int y1) {
	typ = Typ::PUSTEPOLE;
	x = x1;
	y = y1;
}

void PustePole::Ruch(Figura* plansza[][8]) {
	// Implementacja ruchu
}


// Funkcje Klasy Pionek ---
Pionek::Pionek(int x1, int y1, bool isWhite1) {
	typ = Typ::PIONEK;
	FirstMove = true;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Pionek::Ruch(Figura* plansza[][8]) {
	ilosc = 0;
	std::cout << "Ruch Pionka\n";

	// Ruch o 2 pola do przodu
	if (FirstMove == true) {
		if (IsMoveOnBoard(x, y + (FuncIsWhite(isWhite) * 2)) == false) {
			return;
		}
		if (isLegalMove(x, y + (FuncIsWhite(isWhite) * 2), isWhite, plansza) == false) {
			return;
		}
		AddToPossibleMoves(x, y + (FuncIsWhite(isWhite) * 2));
	}
	// Ruch o 1 pole do przodu
	if (IsMoveOnBoard(x, y + (FuncIsWhite(isWhite))) == false) {
		return;
	}
	if (isLegalMove(x, y + (FuncIsWhite(isWhite)), isWhite, plansza) == false) {
		return;
	}
	AddToPossibleMoves(x, y + FuncIsWhite(isWhite));
}

void Pionek::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Skoczek ---
Skoczek::Skoczek(int x1, int y1, bool isWhite1) {
	typ = Typ::SKOCZEK;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Skoczek::Ruch(Figura* plansza[][8]) {
	ilosc = 0;
	std::cout << "Ruch Skoczka\n";
	int offset[8][2] = { {1, 2}, {1, -2}, 
						{-1, 2}, {-1, -2}, 
						{2, 1}, {2, -1}, 
						{-2, 1}, {-2, -1} };
	for (int i{ 0 };i < 8;i++) {
		if (IsMoveOnBoard(x + offset[i][0], y + offset[i][1]) == false) {
			continue;
		}
		if (isLegalMove(x + offset[i][0], y + offset[i][1], isWhite, plansza) == false) {
			continue;
		}
		AddToPossibleMoves(x + offset[i][0], y + offset[i][1]);
	}
	
}


// Funkcje Klasy Goniec ---
Goniec::Goniec(int x1, int y1, bool isWhite1) {
	typ = Typ::GONIEC;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Goniec::Ruch(Figura* plansza[][8]) {
	// Ruch po przekątnej
}


// Funkcje Klasy Wieza ---
Wieza::Wieza(int x1, int y1, bool isWhite1) {
	typ = Typ::WIEZA;
	FirstMove = true;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Wieza::Ruch(Figura* plansza[][8]) {
	ilosc = 0;
	std::cout << "Ruch Wiezy\n";
	// Ruch w prawo, lewo, do góry i do dołu
	VerticalHorizontalMove(x, y, isWhite, plansza);
}


// Funkcje Klasy Hetman ---
Hetman::Hetman(int x1, int y1, bool isWhite1) {
	typ = Typ::HETMAN;
	FirstMove = true;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Hetman::Ruch(Figura* plansza[][8]) {
	// Ruch w prawo, lewo, do góry i do dołu
	VerticalHorizontalMove(x, y, isWhite, plansza);
	// Ruch po przekątnej
}


// Funkcje Klasy Krol ---
Krol::Krol(int x1, int y1, bool isWhite1) {
	typ = Typ::KROL;
	FirstMove = true;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Krol::Ruch(Figura* plansza[][8]) {
	int offset[8][2] = { {1, 0}, {1, 1}, 
						{0, 1}, {-1, 1}, 
						{-1, 0}, {-1, -1}, 
						{0, -1}, {1, -1} };
	for (int i{ 0 };i < 8;i++) {
		if (IsMoveOnBoard(x + offset[i][0], y + offset[i][1]) == false) {
			continue;
		}
		if (isLegalMove(x + offset[i][0], y + offset[i][1], isWhite, plansza) == false) {
			continue;
		}
		AddToPossibleMoves(x + offset[i][0], y + offset[i][1]);
	}
}
