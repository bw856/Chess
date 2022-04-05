#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "board.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class Knight : public Piece {
	public:
	int moves = 0;
	Knight(std::string color, std::string type);
	std::vector<std::pair<int,int>> validMoves(std::pair<int,int> coords, Board &b);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	void undoMove();
	~Knight();
};

#endif
