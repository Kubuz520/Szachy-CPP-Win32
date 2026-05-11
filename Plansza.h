#pragma once

#include "TypEnum.h"
#include "Figury.h"

class Plansza {

public:
	Figura* plansza[8][8];
	Plansza();
	void ShowAll();
	Figura* GetFigura(int x, int y);

};