#ifndef __KING_H__
#define __KING_H__

#include "board.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class King : public Piece {
	public:
	int moves = 0;
	King(std::string color, std::string type);
	std::vector<std::pair<int,int>> validMoves(std::pair<int,int> coords, Board &board);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	void undoMove();
	~King();
};

#endif
