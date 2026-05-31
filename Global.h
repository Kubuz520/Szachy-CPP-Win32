#pragma once

struct PossibleMove {
	int x;
	int y;
	bool castles;
	bool enpassant;

	void Show();
};

inline PossibleMove* PossibleMoves[64 * 32]{};
inline int ilosc{0};

inline PossibleMove* IllegalMoves[64]{};
inline int illegalilosc{ 0 };