#ifndef __MOVECHECK_H__
#define __MOVECHECK_H__

#include <string>
#include <memory>
#include "movevisitor.h"

class MoveCheck : public MoveVisitor {
	std::string check = "none";
	public:
	MoveCheck(Board &board);
	void move(King &king, std::pair<int,int> coords);
	void move(Queen &queen, std::pair<int,int> coords);
	void move(Bishop &bishop, std::pair<int,int> coords);
	void move(Knight &knight, std::pair<int,int> coords);
	void move(Rook &rook, std::pair<int,int> coords);
	void move(Pawn &pawn, std::pair<int,int> coords);
	std::string checkStatus();
};

#endif
