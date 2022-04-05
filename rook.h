#ifndef __ROOK_H__
#define __ROOK_H__

#include "board.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class Rook : public Piece {
	public:
	int moves = 0;
	Rook(std::string color, std::string type);
	std::vector<std::pair<int,int>> validMoves(std::pair<int,int> coords, Board &board);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	void undoMove();
	~Rook();
};

#endif
