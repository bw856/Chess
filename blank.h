#ifndef __BLANK_H__
#define __BLANK_H__

#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class Blank : public Piece {
	public:
	Blank();
	std::vector<std::pair<int, int>> validMoves(std::pair<int,int> coords, Board &board);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	void undoMove();
	~Blank();
};

#endif
