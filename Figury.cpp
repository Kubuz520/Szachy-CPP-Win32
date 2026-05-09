
#include "Figury.h"

#include "TypEnum.h"
#include <iostream>

// Funkcje Klasy Figura ---
void Figura::Show() {
	std::cout << GetTyp(typ);
}


// Funkcje Klasy PustePole ---
PustePole::PustePole(int x, int y) {
	typ = Typ::PUSTEPOLE;
	this->x = x;
	this->y = y;
}

void PustePole::Ruch() {
	// Implementacja ruchu
}

void PustePole::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Pionek ---
Pionek::Pionek(int x, int y, bool isWhite) {
	typ = Typ::PIONEK;
	FirstMove = true;
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
}

void Pionek::Ruch() {
	// Implementacja ruchu
}

void Pionek::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Skoczek ---
Skoczek::Skoczek(int x, int y, bool isWhite) {
	typ = Typ::SKOCZEK;
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
}

void Skoczek::Ruch() {
	// Implementacja ruchu
}

void Skoczek::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Goniec ---
Goniec::Goniec(int x, int y, bool isWhite) {
	typ = Typ::GONIEC;
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
}

void Goniec::Ruch() {
	// Implementacja ruchu
}

void Goniec::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Wieza ---
Wieza::Wieza(int x, int y, bool isWhite) {
	typ = Typ::WIEZA;
	FirstMove = true;
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
}

void Wieza::Ruch() {
	// Implementacja ruchu
}

void Wieza::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Hetman ---
Hetman::Hetman(int x, int y, bool isWhite) {
	typ = Typ::HETMAN;
	FirstMove = true;
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
}

void Hetman::Ruch() {
	// Implementacja ruchu
}

void Hetman::Bicie() {
	// Implementacja Bicia
}


// Funkcje Klasy Krol ---
Krol::Krol(int x, int y, bool isWhite) {
	typ = Typ::KROL;
	FirstMove = true;
	this->x = x;
	this->y = y;
	this->isWhite = isWhite;
}

void Krol::Ruch() {
	// Implementacja ruchu
}

void Krol::Bicie() {
	// Implementacja Bicia
}