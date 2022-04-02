#ifndef __PIECE_H__
#define __PIECE_H__

#include <vector>
#include "movevisitor.h"
#include "board.h"

class Piece {
	char colour;
	char pieceType;
	public:
	Piece(char colour, char pieceType);
	virtual std::vector<std::vector<int, int>> validMoves(int posX, int posY, board &Board) = 0;
	char getColour();
	virtual std::vector<int, int> getPosition();
	char getType();
	virtual void acceptMove(MoveVisitor &mv, int posX, int posY) = 0;
	virtual ~Piece();
};
