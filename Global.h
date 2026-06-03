#pragma once

struct PossibleMove {
	int x;
	int y;
	bool castles;
	bool enpassant;

	void Show();
};

inline bool blackchecked{ false };
inline bool blackendgame{ false };

inline bool whitechecked{ false };
inline bool whiteendgame{ false };
inline bool gameplaying{ true };

inline PossibleMove* PossibleMoves[64 * 32]{};
inline int ilosc{0};

inline PossibleMove* IllegalMoves[64* 32]{};
inline int illegalilosc{ 0 };