#ifndef __BOARD_H__
#define __BOARD_H__

#include "piece.h"
#include <vector>

class Board {
	vector<int, int> squares;
	public:
	Board();
	*Piece getPiece(int posX, int posY);
	void setPiece(Piece *p, int posX, int posY);
	void movePiece(Piece *p, int posX, int posY, int newX, int newY);
	void clear();
};
