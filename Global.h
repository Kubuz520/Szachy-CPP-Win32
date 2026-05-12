#pragma once

struct PossibleMove {
	int x;
	int y;

public:
	void Show();
};

inline PossibleMove* PossibleMoves[64]{};
inline int ilosc{0};