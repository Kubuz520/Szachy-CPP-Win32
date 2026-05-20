#include "Figury.h"

#include "TypEnum.h"
#include "Global.h"
#include "Plansza.h"
#include <iostream>

// Funckje Globalne ---

// funkcja zwracająca -1 dla białych i 1 dla czarnych, ułatwiająca obliczenia ruchów pionków
int FuncIsWhite(bool iswhite) {
	if (iswhite == true) {
		return -1;
	}
	else {
		return 1;
	}
}

// funkcja sprawdzająca czy pole docelowe jest puste lub zajęte przez figurę przeciwnego koloru
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

// funkcja dodająca możliwy ruch do tablicy PossibleMoves
void AddToPossibleMoves(int x1, int y1, bool castles = false, bool enpassant = false) {
	PossibleMoves[ilosc] = new PossibleMove{ x1, y1, castles};
	ilosc++;
}

// funkcja sprawdzająca czy pole docelowe jest na planszy
bool IsMoveOnBoard(int x1, int y1) {
	if (x1 <= 7 && x1 >= 0 && y1 <= 7 && y1 >= 0) {
		return true;
	}
	else {
		return false;
	}
}


// ############### Funkcje Ruchów ###############


// funkcja obsługująca ruchy w pionie i poziomie
void VerticalHorizontalMove(int x, int y, bool isWhite, Figura* plansza[][8]) {
	int offset[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	// Ruch w prawo, lewo, do góry i do dołu
	for (int j{ 0 }; j < 4; j++) {
		for (int i{ 1 }; i < 8; i++) {
			if (IsMoveOnBoard(x + (offset[j][0] * i), y + (offset[j][1] * i)) == false) {
				continue;
			}
			if (isLegalMove(x + (offset[j][0] * i), y + (offset[j][1] * i), isWhite, plansza) == false) {
				continue;
			}
			AddToPossibleMoves(x + (offset[j][0] * i), y + (offset[j][1] * i));
			if (plansza[x + (offset[j][0] * i)][y + (offset[j][1] * i)]->GetType() != Typ::PUSTEPOLE) {
				j++;
				i = 0;
				continue;
			}
		}
	}
}

// funkcja obsługująca ruchy po przekątnej
void SkosyMove(int x, int y, bool isWhite, Figura* plansza[][8]) {
	int offset[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	
	// Skosy
	for (int j{ 0 }; j < 4; j++) {
		for (int i{ 0 }; i < 8; i++) {
			if (IsMoveOnBoard(x + (offset[j][0] * i), y + (offset[j][1] * i)) == false) {
				continue;
			}
			if (isLegalMove(x + (offset[j][0] * i), y + (offset[j][1] * i), isWhite, plansza) == false) {
				continue;
			}
			AddToPossibleMoves(x + (offset[j][0] * i), y + (offset[j][1] * i));
			if (plansza[x + (offset[j][0] * i)][y + (offset[j][1] * i)]->GetType() != Typ::PUSTEPOLE) {
				j++;
				i = 0;
				continue;
			}
		}
	}
}

// funkcje Bicia Pionka
void EnPassant(int x, int y, Figura* plansza[][8], bool iswhite) {

	if (x < 7) {
		Pionek* p = dynamic_cast<Pionek*>(plansza[x + 1][y]);
		if (p != nullptr) {
			if (p->MoveNumber == 1 && p->GetIsWhite() != iswhite) {
				AddToPossibleMoves(x + 1, y + FuncIsWhite(iswhite), false, true);
			}
		}
	}
	if (x > 0) {
		Pionek* l = dynamic_cast<Pionek*>(plansza[x - 1][y]);
		if (l != nullptr) {
			if (l->MoveNumber == 1 && l->GetIsWhite() != iswhite) {
				AddToPossibleMoves(x - 1, y + FuncIsWhite(iswhite), false, true);
			}
		}
	}

}
void PawnCapture(int x, int y, Figura* plansza[][8], bool iswhite) {

	// lewo
	if (plansza[x - 1][y + FuncIsWhite(iswhite)]->GetType() != Typ::PUSTEPOLE && x > 0 && iswhite != plansza[x - 1][y + FuncIsWhite(iswhite)]->GetIsWhite()) {
		AddToPossibleMoves(x - 1, y + FuncIsWhite(iswhite));
	}
	// prawo
	if (plansza[x + 1][y + FuncIsWhite(iswhite)]->GetType() != Typ::PUSTEPOLE && x < 7 && iswhite != plansza[x + 1][y + FuncIsWhite(iswhite)]->GetIsWhite()) {
		AddToPossibleMoves(x + 1, y + FuncIsWhite(iswhite));
	}
	EnPassant(x, y, plansza, iswhite);
}

// funkcje Roszady ----
// Lewa Roszada
void CastlesLeft(int x, int y, Figura* plansza[][8]) {
	
	Wieza* w1 = dynamic_cast<Wieza*>(plansza[0][y]);

	if (w1 == nullptr) {
		return;
	}
	else if (w1->GetHasMoved() == true) {
		return;
	}

	for (int i{ 1 };i < x;i++) {
		if (plansza[i][y]->GetType() != Typ::PUSTEPOLE) {
			return;
		}
	}
	AddToPossibleMoves(0, y, true);
}

// Prawa Roszada
void CastlesRight(int x, int y, Figura* plansza[][8]) {
	
	Wieza* w2 = dynamic_cast<Wieza*>(plansza[7][y]);

	if (w2 == nullptr) {
		return;
	}
	else if (w2->GetHasMoved() == true) {
		return;
	}

	for (int i{ x + 1 };i < 7;i++) {
		if (plansza[i][y]->GetType() != Typ::PUSTEPOLE) {
			return;
		}
	}
	AddToPossibleMoves(7, y, true);
}

void Castles(int x, int y, Figura* plansza[][8]) {

	// Sprawdza czy krol sie ruszyl
	Krol* k = reinterpret_cast<Krol*>(plansza[x][y]);
	if (k->GetHasMoved() == true) {
		return;
	}
	
	// Sprawdza czy wieze sie ruszyly i czy pola miedzy nimi sa puste
	CastlesLeft(x, y, plansza);
	CastlesRight(x, y, plansza);
}


// ############### Funkcje Klas ###############


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
Pionek::Pionek(int x1, int y1, bool isWhite1, int movenumber1) {
	typ = Typ::PIONEK;
	x = x1;
	y = y1;
	isWhite = isWhite1;
	MoveNumber = movenumber1;
}

void Pionek::Ruch(Figura* plansza[][8]) {
	
	std::cout << "Ruch Pionka\n";

	// Ruch o 2 pola do przodu
	if (MoveNumber == 0) {
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

	// Bicie Pionka
	PawnCapture(x, y, plansza, isWhite);
}


// Funkcje Klasy Skoczek ---
Skoczek::Skoczek(int x1, int y1, bool isWhite1) {
	typ = Typ::SKOCZEK;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Skoczek::Ruch(Figura* plansza[][8]) {
	
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
	ilosc = 0;
	std::cout << "Ruch Gonca\n";
	// Ruch po przekątnej
	SkosyMove(x, y, isWhite, plansza);
}

// Funkcje Klasy Wieza ---
Wieza::Wieza(int x1, int y1, bool isWhite1, bool hasmoved1) {
	typ = Typ::WIEZA;
	x = x1;
	y = y1;
	isWhite = isWhite1;
	HasMoved = hasmoved1;
}

void Wieza::Ruch(Figura* plansza[][8]) {
	
	std::cout << "Ruch Wiezy\n";
	// Ruch w prawo, lewo, do góry i do dołu
	VerticalHorizontalMove(x, y, isWhite, plansza);
}

bool Wieza::GetHasMoved() {
	return HasMoved;
}

// Funkcje Klasy Hetman ---
Hetman::Hetman(int x1, int y1, bool isWhite1) {
	typ = Typ::HETMAN;
	x = x1;
	y = y1;
	isWhite = isWhite1;
}

void Hetman::Ruch(Figura* plansza[][8]) {
	
	std::cout << "Ruch Hetmana\n";
	// Ruch w prawo, lewo, do góry i do dołu
	VerticalHorizontalMove(x, y, isWhite, plansza);
	// Ruch po przekątnej
	SkosyMove(x, y, isWhite, plansza);
}


// Funkcje Klasy Krol ---
Krol::Krol(int x1, int y1, bool isWhite1, bool hasmoved1) {
	typ = Typ::KROL;
	x = x1;
	y = y1;
	isWhite = isWhite1;
	HasMoved = hasmoved1;
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
	Castles(x, y, plansza);
}

bool Krol::GetHasMoved() {
	return HasMoved;
}