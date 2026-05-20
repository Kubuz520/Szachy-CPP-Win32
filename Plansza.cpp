
#include "Plansza.h"

#include <iostream>


Plansza::Plansza() {
	plansza[0][0] = new Wieza(0, 0, false, false);
	plansza[1][0] = new Skoczek(1, 0, false);
	plansza[2][0] = new Goniec(2, 0, false);
	plansza[3][0] = new Hetman(3, 0, false);
	plansza[4][0] = new Krol(4, 0, false, false);
	plansza[5][0] = new Goniec(5, 0, false);
	plansza[6][0] = new Skoczek(6, 0, false);
	plansza[7][0] = new Wieza(7, 0, false, false);

	plansza[0][1] = new Pionek(0, 1, false);
	plansza[1][1] = new Pionek(1, 1, false);
	plansza[2][1] = new Pionek(2, 1, false);
	plansza[3][1] = new Pionek(3, 1, false);
	plansza[4][1] = new Pionek(4, 1, false);
	plansza[5][1] = new Pionek(5, 1, false);
	plansza[6][1] = new Pionek(6, 1, false);
	plansza[7][1] = new Pionek(7, 1, false);

	for (int i = 2; i <= 5; i++)
		for (int j = 0; j < 8; j++)
			plansza[j][i] = new PustePole(j, i);

	plansza[0][6] = new Pionek(0, 6, true);
	plansza[1][6] = new Pionek(1, 6, true);
	plansza[2][6] = new Pionek(2, 6, true);
	plansza[3][6] = new Pionek(3, 6, true);
	plansza[4][6] = new Pionek(4, 6, true);
	plansza[5][6] = new Pionek(5, 6, true);
	plansza[6][6] = new Pionek(6, 6, true);
	plansza[7][6] = new Pionek(7, 6, true);

	plansza[0][7] = new Wieza(0, 7, true, false);
	plansza[1][7] = new Skoczek(1, 7, true);
	plansza[2][7] = new Goniec(2, 7, true);
	plansza[3][7] = new Hetman(3, 7, true);
	plansza[4][7] = new Krol(4, 7, true, false);
	plansza[5][7] = new Goniec(5, 7, true);
	plansza[6][7] = new Skoczek(6, 7, true);
	plansza[7][7] = new Wieza(7, 7, true, false);
}

void Plansza::ShowAll() {
	for (int i{ 0 };i < 8;i++) {
		std::cout << "\n";
		for (int j{ 0 };j < 8;j++) {
			plansza[j][i]->Show();
		}
	}
}

Figura* Plansza::GetFigura(int x, int y) {
    return plansza[x][y];
}