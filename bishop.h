#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "board.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

class Bishop : public Piece {
	public:
	Bishop(std::string color, std::string type);
	std::vector<std::pair<int,int>> validMoves(std::pair<int,int> coords, Board &b);
	void acceptMove(MoveVisitor &v, std::pair<int,int> coords);
	~Bishop();
};

#endif