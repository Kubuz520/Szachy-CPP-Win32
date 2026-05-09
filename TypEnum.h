#pragma once

enum class Typ {
	PUSTEPOLE,
	PIONEK,
	SKOCZEK,
	WIEZA,
	GONIEC,
	HETMAN,
	KROL
};

char GetTyp(Typ typ);