
#include "SprawdzanieSzacha.h"

void DeleteBoard(Plansza tmpPlansza) {
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			delete tmpPlansza.plansza[x][y];
		}
	}
}

void Checks(int x1, int y1, Figura* plansza[][8], PossibleMove* currentmove) {

	// Tworzenie tymczasowej planszy
	Plansza tmpPlansza;

	// Przestawianie istniejacej planszy do tymczasowej
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			delete tmpPlansza.plansza[x][y];

			Figura* tmp = dynamic_cast<Pionek*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Pionek(x, y, plansza[x][y]->GetIsWhite(), reinterpret_cast<Pionek*>(plansza[x][y])->MoveNumber);
				continue;
			}
			tmp = dynamic_cast<Skoczek*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Skoczek(x, y, plansza[x][y]->GetIsWhite());
				continue;
			}
			tmp = dynamic_cast<Goniec*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Goniec(x, y, plansza[x][y]->GetIsWhite());
				continue;
			}
			tmp = dynamic_cast<Wieza*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Wieza(x, y, plansza[x][y]->GetIsWhite(), reinterpret_cast<Wieza*>(plansza[x][y])->HasMoved);
				continue;
			}
			tmp = dynamic_cast<Hetman*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Hetman(x, y, plansza[x][y]->GetIsWhite());
				continue;
			}
			tmp = dynamic_cast<Krol*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Krol(x, y, plansza[x][y]->GetIsWhite(), reinterpret_cast<Krol*>(plansza[x][y])->HasMoved);
				continue;
			}

			else {
				tmpPlansza.plansza[x][y] = new PustePole(x, y);
				continue;
			}
		}
	}
	ExecuteMove(x1, y1, tmpPlansza.plansza, currentmove);
	std::cout << "\n";
	tmpPlansza.ShowAll();

	// Stworzenie listy wszystkich 
	for (int y{ 0 };y < 8;y++) {
		for (int x{ 0 };x < 8;x++) {
			tmpPlansza.plansza[x][y]->Ruch(tmpPlansza.plansza);
		}
	}

	// Sprawdzenie czy jakis ruch atakuje krola
	for (int i{ 0 }; i < ilosc; i++) {
		if (tmpPlansza.plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetType() == Typ::KROL) {
			if (plansza[x1][y1]->GetIsWhite() != tmpPlansza.plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetIsWhite()) {
				continue;
			}
			std::cout << "\n";
			std::cout << "Ruch Niepoprawny \n";
			IllegalMoves[illegalilosc] = currentmove;
			illegalilosc++;
		}
	}
	
	// Usuwanie tymczasowej planszy
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			delete tmpPlansza.plansza[x][y];
		}
	}

}



bool Checkmate(int x1, int y1, Figura* plansza[][8], PossibleMove* currentmove) {


	//std::cout << GetTyp(plansza[x1][y1]->GetType()) << "\n";
	//std::cout << "x: " << x1 << "y: " << y1 << "\n";
	//std::cout << "Ruch Do X: " << currentmove->x << "  Ruch Do Y: " << currentmove->y << "\n";

	// Tworzenie tymczasowej planszy
	Plansza tmpPlansza;

	// Przestawianie istniejacej planszy do tymczasowej
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			delete tmpPlansza.plansza[x][y];

			Figura* tmp = dynamic_cast<Pionek*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Pionek(x, y, plansza[x][y]->GetIsWhite(), reinterpret_cast<Pionek*>(plansza[x][y])->MoveNumber);
				continue;
			}
			tmp = dynamic_cast<Skoczek*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Skoczek(x, y, plansza[x][y]->GetIsWhite());
				continue;
			}
			tmp = dynamic_cast<Goniec*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Goniec(x, y, plansza[x][y]->GetIsWhite());
				continue;
			}
			tmp = dynamic_cast<Wieza*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Wieza(x, y, plansza[x][y]->GetIsWhite(), reinterpret_cast<Wieza*>(plansza[x][y])->HasMoved);
				continue;
			}
			tmp = dynamic_cast<Hetman*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Hetman(x, y, plansza[x][y]->GetIsWhite());
				continue;
			}
			tmp = dynamic_cast<Krol*>(plansza[x][y]);

			if (tmp != nullptr) {
				tmpPlansza.plansza[x][y] = new Krol(x, y, plansza[x][y]->GetIsWhite(), reinterpret_cast<Krol*>(plansza[x][y])->HasMoved);
				continue;
			}

			else {
				tmpPlansza.plansza[x][y] = new PustePole(x, y);
				continue;
			}
		}
	}
	ExecuteMove(x1, y1, tmpPlansza.plansza, currentmove);

	int j{ ilosc };

	// Stworzenie listy wszystkich 
	for (int y{ 0 };y < 8;y++) {
		for (int x{ 0 };x < 8;x++) {
			tmpPlansza.plansza[x][y]->Ruch(tmpPlansza.plansza);
		}
	}

	// Sprawdzenie czy jakis ruch atakuje krola
	for (int i{ j }; i < ilosc; i++) {
		if (tmpPlansza.plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetType() == Typ::KROL) {
			if (plansza[x1][y1]->GetIsWhite() != tmpPlansza.plansza[PossibleMoves[i]->x][PossibleMoves[i]->y]->GetIsWhite()) {
				DeleteBoard(tmpPlansza);
				return true;
			}
		}
	}
	
	// Usuwanie tymczasowej planszy
	for (int x{ 0 };x < 8;x++) {
		for (int y{ 0 };y < 8;y++) {
			delete tmpPlansza.plansza[x][y];
		}
	}
	return false;
}