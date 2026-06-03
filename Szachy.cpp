
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

	ilosc = 0;
	// Szach Czarnych na Białych
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			if (plansza[x][y]->GetIsWhite() == true) {
				continue;
			}
			plansza[x][y]->Ruch(plansza);
		}
	}
	for (int i{ 0 };i < ilosc;i++) {
		if (plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetType() == Typ::KROL) {
			whitechecked = true;
			break;
		}
		whitechecked = false;
	}
	std::cout << "Szach na Bialych? " << whitechecked<<"\n";


	ilosc = 0;
	// Szach Bialych na Czarnych
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			if (plansza[x][y]->GetIsWhite() == false) {
				continue;
			}
			plansza[x][y]->Ruch(plansza);
		}
	}
	for (int i{ 0 };i < ilosc;i++) {
		if (plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetType() == Typ::KROL) {
			blackchecked = true;
			break;
		}
		blackchecked = false;
	}
	std::cout << "Szach na Czarnych? " << blackchecked << "\n";
	
	// Sprawdzanie Mata i Pata

}

// Sprawdzanie czy pionek jest na koncu TODO
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

