#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "piece.h"
#include <vector>

class Knight : public Piece {
	public:
	Knight(char colour, char pieceType);
	virtual std::vector<std::vector<int, int>> validMoves(int posX, int posY, board &Board) = 0;
	void acceptMove(MoveVisotor &mv, int posX, int posY) = 0;
	~Knight();
};
