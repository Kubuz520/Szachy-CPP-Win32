
#include "Plansza.h"

#include <iostream>


Plansza::Plansza() {
    plansza[0][0] = new Wieza(0, 0, false);
    plansza[0][1] = new Skoczek(0, 1, false);
    plansza[0][2] = new Goniec(0, 2, false);
    plansza[0][3] = new Hetman(0, 3, false);
    plansza[0][4] = new Krol(0, 4, false);
    plansza[0][5] = new Goniec(0, 5, false);
    plansza[0][6] = new Skoczek(0, 6, false);
    plansza[0][7] = new Wieza(0, 7, false);

    plansza[1][0] = new Pionek(1, 0, false);
    plansza[1][1] = new Pionek(1, 1, false);
    plansza[1][2] = new Pionek(1, 2, false);
    plansza[1][3] = new Pionek(1, 3, false);
    plansza[1][4] = new Pionek(1, 4, false);
    plansza[1][5] = new Pionek(1, 5, false);
    plansza[1][6] = new Pionek(1, 6, false);
    plansza[1][7] = new Pionek(1, 7, false);

    for (int i = 2; i <= 5; i++)
        for (int j = 0; j < 8; j++)
            plansza[i][j] = new PustePole(i, j);

    plansza[6][0] = new Pionek(6, 0, true);
    plansza[6][1] = new Pionek(6, 1, true);
    plansza[6][2] = new Pionek(6, 2, true);
    plansza[6][3] = new Pionek(6, 3, true);
    plansza[6][4] = new Pionek(6, 4, true);
    plansza[6][5] = new Pionek(6, 5, true);
    plansza[6][6] = new Pionek(6, 6, true);
    plansza[6][7] = new Pionek(6, 7, true);

    plansza[7][0] = new Wieza(7, 0, true);
    plansza[7][1] = new Skoczek(7, 1, true);
    plansza[7][2] = new Goniec(7, 2, true);
    plansza[7][3] = new Hetman(7, 3, true);
    plansza[7][4] = new Krol(7, 4, true);
    plansza[7][5] = new Goniec(7, 5, true);
    plansza[7][6] = new Skoczek(7, 6, true);
    plansza[7][7] = new Wieza(7, 7, true);
}

void Plansza::ShowAll() {
	for (int i{ 0 };i < 8;i++) {
		std::cout << "\n";
		for (int j{ 0 };j < 8;j++) {
			plansza[i][j]->Show();
		}
	}
}