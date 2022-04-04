#ifndef __KING_H__
#define __KING_H__

#include "board.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class King : public Piece {
	public:
	King(std::string color, std::string type);
	std::vector<std::pair<int,int>> validMoves(std::pair<int,int> coords, Board &b);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	~King();
};

#endif
