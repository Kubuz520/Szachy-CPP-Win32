
#include "Global.h"

#include <iostream>

void PossibleMove::Show()
{
	std::cout << "x: " << x << " y: " << y << "\n";
	if (castles == true) {
		std::cout << "Roszada" << "\n";
	}
}