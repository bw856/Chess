#ifndef __PAWN_H__
#define __PAWN_H__

#include <vector>
#include "piece.h"

class Pawn : public Piece {
	public:
	Pawn(char color, char pieceType);
	std::vector<std::vector<int, int>> validMoves(int posX, int posY, board &Board);
	void acceptMove(MoveVisitor &mv, int posX, int posY);
	~Pawn();
}
