
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

// Wylacza 
void ExcludeIllegal() {
	for (int i{ 0 }; i < TmpIlosc; i++) {
		for (int j{ 0 }; j < illegalilosc; j++) {
			if (TmpPossibleMoves[i] == IllegalMoves[j]) {
				TmpIlosc--;
				for (int t{ i };t < TmpIlosc;t++) {
					TmpPossibleMoves[i] = TmpPossibleMoves[i + 1];
				}
			}
		}
	}
	
}

// Glowna petla programu
int main()
{
	Plansza plansza;

	do {
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

	} while (true);
	
	
    return 0;
}

