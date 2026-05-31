
#include <iostream>

#include "TypEnum.h"
#include "Figury.h"
#include "Plansza.h"
#include "Global.h"

PossibleMove* currentmove;

void ShowPossibleMoves() {
	for (int i{ 0 }; i < ilosc; i++) {
		std::cout << i + 1 << ": ";
		PossibleMoves[i]->Show();
	}
}

// Funkcja Wykonująca ruch
void ExecuteMove(int x1, int y1, Figura* plansza[][8]) {

	delete plansza[currentmove->x][currentmove->y];

	if (currentmove->castles == true) {

		// sprawdzenie po ktorej stronie mamy roszade
		bool leftcastle{};
		if (currentmove->x == 0) {
			leftcastle = true;
		}
		else {
			leftcastle = false;
		}

		if (leftcastle == true) {
			delete plansza[x1 - 2][y1];
			delete plansza[x1 - 1][y1];
			plansza[x1-2][y1] = new Krol(x1 - 2, y1, plansza[x1][y1]->GetIsWhite(), true);
			plansza[x1-1][y1] = new Wieza(x1 - 1, y1, plansza[x1][y1]->GetIsWhite(), true);
		}
		else {
			delete plansza[x1 + 2][y1];
			delete plansza[x1 + 1][y1];
			plansza[x1 + 2][y1] = new Krol(x1 + 2, y1, plansza[x1][y1]->GetIsWhite(), true);
			plansza[x1 + 1][y1] = new Wieza(x1 + 1, y1, plansza[x1][y1]->GetIsWhite(), true);
		}

		delete plansza[x1][y1];
		plansza[x1][y1] = new PustePole(x1, y1);
	}

	// Ruch EnPassant
	if (currentmove->enpassant == true) {

		if (plansza[x1][y1]->GetIsWhite() == true) {
			delete plansza[currentmove->x][currentmove->y + 1];
			plansza[currentmove->x][currentmove->y + 1] = new PustePole(currentmove->x, currentmove->y + 1);
		}
		else {
			delete plansza[currentmove->x][currentmove->y - 1];
			plansza[currentmove->x][currentmove->y - 1] = new PustePole(currentmove->x, currentmove->y - 1);
		}

		Figura* tmp = dynamic_cast<Pionek*>(plansza[x1][y1]);
		plansza[currentmove->x][currentmove->y] = new Pionek(currentmove->x, currentmove->y, plansza[x1][y1]->GetIsWhite(), reinterpret_cast<Pionek*>(plansza[x1][y1])->MoveNumber + 1);

		delete plansza[x1][y1];
		plansza[x1][y1] = new PustePole(x1, y1);

		return;
	}
	
	
	// Zamiana Pola Wybranego na Figure Poruszajaca się
	Figura* tmp = dynamic_cast<Pionek*>(plansza[x1][y1]);

	if (tmp != nullptr) {
		plansza[currentmove->x][currentmove->y] = new Pionek(currentmove->x, currentmove->y, plansza[x1][y1]->GetIsWhite(), reinterpret_cast<Pionek*>(plansza[x1][y1])->MoveNumber + 1);
	}
	tmp = dynamic_cast<Skoczek*>(plansza[x1][y1]);
	
	if (tmp != nullptr) {
		plansza[currentmove->x][currentmove->y] = new Skoczek(currentmove->x, currentmove->y, plansza[x1][y1]->GetIsWhite());
	}
	tmp = dynamic_cast<Goniec*>(plansza[x1][y1]);

	if (tmp != nullptr) {
		plansza[currentmove->x][currentmove->y] = new Goniec(currentmove->x, currentmove->y, plansza[x1][y1]->GetIsWhite());
	}
	tmp = dynamic_cast<Wieza*>(plansza[x1][y1]);
	
	if (tmp != nullptr) {
		plansza[currentmove->x][currentmove->y] = new Wieza(currentmove->x, currentmove->y, plansza[x1][y1]->GetIsWhite(), true);
	}
	tmp = dynamic_cast<Hetman*>(plansza[x1][y1]);

	if (tmp != nullptr) {
		plansza[currentmove->x][currentmove->y] = new Hetman(currentmove->x, currentmove->y, plansza[x1][y1]->GetIsWhite());
	}
	tmp = dynamic_cast<Krol*>(plansza[x1][y1]);

	if (tmp != nullptr) {
		plansza[currentmove->x][currentmove->y] = new Krol(currentmove->x, currentmove->y, plansza[x1][y1]->GetIsWhite(), true);
	}

	// Zamiana Pola wybranej figury na puste

	delete plansza[x1][y1];
	plansza[x1][y1] = new PustePole(x1, y1);
	
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
		ShowPossibleMoves();

		int r{};
		std::cout << "\n";
		std::cout << "Podaj Ruch (0 aby opuscic)" << "\n";
		std::cin >> r;
		if (r == 0) {
			continue;
		}
		currentmove = PossibleMoves[r - 1];
		PossibleMoves[r - 1]->Show();
		std::cout << "\n";
		ExecuteMove(x, y, plansza.plansza);

	} while (true);
	
	
    return 0;
}

