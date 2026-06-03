#pragma once

#include "Global.h"
#include "TypEnum.h"
#include "Plansza.h"
#include "Figury.h"
#include "ExecuteMove.h"
#include <iostream>

void Checks(int x1, int y1, Figura* plansza[][8], PossibleMove* currentmove);
bool Checkmate(int x1, int y1, Figura* plansza[][8], PossibleMove* currentmove);
void DeleteBoard(Plansza tmpPlansza);