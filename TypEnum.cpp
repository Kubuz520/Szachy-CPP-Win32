
#include "TypEnum.h"

char GetTyp(Typ typ) {
	switch (typ) {
	case Typ::PUSTEPOLE:
		return 'X';
	case Typ::PIONEK:
		return 'P';
	case Typ::SKOCZEK:
		return 'S';
	case Typ::WIEZA:
		return 'W';
	case Typ::GONIEC:
		return 'G';
	case Typ::HETMAN:
		return 'H';
	case Typ::KROL:
		return 'K';
	default:
		return 'X';
	}
}