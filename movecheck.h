#ifndef __MOVECHECK_H__
#define __MOVECHECK_H__

#include <string>
#include <memory>
#include "movevisitor.h"

class MoveCheck : public MoveVisitor {
	std::string check = "none";
	public:
	MoveCheck(Board &board);
	void acceptMove(King &king, std::pair<int,int> coords);
	void acceptMove(Queen &queen, std::pair<int,int> coords);
	void acceptMove(Bishop &bishop, std::pair<int,int> coords);
	void acceptMove(Knight &knight, std::pair<int,int> coords);
	void acceptMove(Rook &rook, std::pair<int,int> coords);
	void acceptMove(Pawn &pawn, std::pair<int,int> coords);
	std::string checkStatus();
};

#endif
