#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "board.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class Queen : public Piece {
	public:
	int moves = 0;
	Queen(std::string color, std::string type);
	std::vector<std::pair<int,int>> validMoves(std::pair<int,int> coords, Board &board);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	void undoMove();
	~Queen();
};

#endif
