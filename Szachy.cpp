
#include <iostream>

#include "TypEnum.h"
#include "Figury.h"
#include "Plansza.h"
#include "Global.h"
#include "SprawdzanieSzacha.h"
#include "ExecuteMove.h"

PossibleMove* currentmove;

PossibleMove* TmpPossibleMoves[64]{};
int TmpIlosc{0};

void ShowPossibleMoves() {
	std::cout << "\n";
	for (int i{ 0 }; i < TmpIlosc; i++) {
		std::cout << i + 1 << ": ";
		TmpPossibleMoves[i]->Show();
	}
}

// Wylacza nielegalne ruchy
void ExcludeIllegal() {
	for (int i{ 0 }; i < TmpIlosc; i++) {
		for (int j{ 0 }; j < illegalilosc; j++) {
			if (TmpPossibleMoves[i] != IllegalMoves[j]) {
				continue;
			}
			TmpIlosc--;
			for (int t{ i };t < TmpIlosc;t++) {
				TmpPossibleMoves[t] = TmpPossibleMoves[t + 1];
			}
		}
	}
}

// Sprawdza czy gra sie skonczyla
void Win(Figura* plansza[][8]) {

	int Ruchy[64*16][2]{};

	illegalilosc = 0;
	ilosc = 0;
	// Szach bialych koniec na czarnych -------
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			if (plansza[x][y]->GetIsWhite() == true) {
				continue;
			}
			int iloscruchow{ ilosc};
			plansza[x][y]->Ruch(plansza);
			// Dodanie Ruchow do tablicy Ruchy
			for (int i{iloscruchow};i < ilosc;i++) {
				Ruchy[i][0] = x;
				Ruchy[i][1] = y;
			}
		}
	}
	
	int tmpilosc{ ilosc-1 };

	blackendgame = true;
	for (int i{ 0 };i < tmpilosc;i++) {
		if (plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetType() == Typ::KROL) {
			whitechecked = true;
			break;
		}
		whitechecked = false;
	}
	for (int i{ 0 };i < tmpilosc;i++) {
		if (Checkmate(Ruchy[i][0], Ruchy[i][1], plansza, PossibleMoves[i]) != true) { blackendgame = false; }
	}
	std::cout << "Szach na Bialych? " << whitechecked<<"\n";
	std::cout << "Koniec Czarnych " << blackendgame << "\n";


	illegalilosc = 0;
	ilosc = 0;
	// Szach na czarnych koniec bialych -------
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			if (plansza[x][y]->GetIsWhite() == false) {
				continue;
			}
			plansza[x][y]->Ruch(plansza);
		}
	}

	tmpilosc = ilosc-1;

	whiteendgame = true;
	for (int i{ 0 };i < tmpilosc;i++) {
		if (plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetType() == Typ::KROL) {
			blackchecked = true;
			break;
		}
		blackchecked = false;
	}
	for (int i{ 0 };i < tmpilosc;i++) {
		if (Checkmate(Ruchy[i][0], Ruchy[i][1], plansza, PossibleMoves[i]) != true) { whiteendgame = false; }
	}
	std::cout << "Szach na Czarnych? " << blackchecked << "\n";
	std::cout << "Koniec Bialych " << whiteendgame << "\n";

}

// Sprawdzanie Czy jak ktos przegral to jest Pat czy Mat
void WinOrDraw() {
	if (whiteendgame == true) {
		if (whitechecked == true) {
			std::cout << "Biali Przegrali" << "\n";
		}
		else {
			std::cout << "Shach Pat" << "\n";
		}
		gameplaying = false;
	}
	else if (blackendgame == true) {
		if (blackchecked == true) {
			std::cout << "Czarni Przegrali" << "\n";
		}
		else {
			std::cout << "Shach Pat" << "\n";
		}
		gameplaying = false;
	}
}

// Sprawdzanie czy pionek jest na koncu
void PawnPromotion(Figura* plansza[][8]) {
	for (int x{ 0 };x < 8;x++) {
		if (plansza[x][0]->GetType() == Typ::PIONEK) {
			delete plansza[x][0];
			plansza[x][0] = new Hetman(x, 0, true);
		}
		if (plansza[x][7]->GetType() == Typ::PIONEK) {
			delete plansza[x][7];
			plansza[x][7] = new Hetman(x, 7, false);
		}
	}
}

// Glowna petla programu
int main()
{
	Plansza plansza;

	do {
		
		Win(plansza.plansza);
		WinOrDraw();

		ilosc = 0;
		plansza.ShowAll();
		int x{}; int y{};
		std::cout << "\n";
		std::cout << "Podaj wspolrzedna figury X: "<<"\n";
		std::cin >> x;
		std::cout << "Podaj wspolrzedna figury Y: " << "\n";
		std::cin >> y;
		plansza.GetFigura(x , y )->Ruch(plansza.plansza);
		
		TmpIlosc = ilosc;
		illegalilosc = 0;
		for (int i{ 0 }; i < ilosc; i++) {
			TmpPossibleMoves[i] = PossibleMoves[i];
		}
		for (int i{ 0 }; i < TmpIlosc; i++) {
			Checks(x, y, plansza.plansza, TmpPossibleMoves[i]);
		}
		ExcludeIllegal();
		ShowPossibleMoves();

		int r{};
		std::cout << "\n";
		std::cout << "Podaj Ruch (0 aby opuscic)" << "\n";
		std::cin >> r;
		if (r == 0 || r > TmpIlosc) {
			continue;
		}
		currentmove = TmpPossibleMoves[r - 1];
		TmpPossibleMoves[r - 1]->Show();
		std::cout << "\n";
		ExecuteMove(x, y, plansza.plansza, currentmove);

		PawnPromotion(plansza.plansza);

	} while (gameplaying);
	
	
    return 0;
}

