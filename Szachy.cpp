
#include <iostream>

#include "TypEnum.h"
#include "Figury.h"
#include "Plansza.h"
#include "Global.h"

void ShowPossibleMoves() {
	for (int i{ 0 }; i < ilosc; i++) {
		PossibleMoves[i]->Show();
	}
}

int main()
{
	Plansza plansza;

	do {
		plansza.ShowAll();
		int x{};
		int y{};
		std::cout << "\n";
		std::cout << "Podaj wspolrzedna figury X: "<<"\n";
		std::cin >> x;
		std::cout << "Podaj wspolrzedna figury Y: " << "\n";
		std::cin >> y;
		plansza.GetFigura(x - 1, y - 1)->Ruch(plansza.plansza);
		ShowPossibleMoves();
	} while (true);
	

    return 0;
}

