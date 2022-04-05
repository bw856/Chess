#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class Pawn : public Piece {
	public:
	int moves = 0;
	Pawn(std::string color, std::string type);
	std::vector<std::pair<int, int>> validMoves(std::pair<int,int> coords, Board &board);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	void undoMove();
	~Pawn();
};

#endif
