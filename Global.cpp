
#include "Global.h"

#include <iostream>

void PossibleMove::Show()
{
	std::cout << "x: " << x << " y: " << y;
	if (castles == true) {
		std::cout << " Roszada" << "\n";
		return;
	}
	std::cout << "\n";
}