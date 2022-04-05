#ifndef __MOVESTALEMATE_H__
#define __MOVESTALEMATE_H__

#include "movevisitor.h"
#include <memory>

class MoveStalemate : public MoveVisitor {
	bool movesLeft = false;
	public:
	MoveStalemate(Board &board);
	void move(King &king, std::pair<int,int> coords);
	void move(Queen &queen, std::pair<int,int> coords);
	void move(Bishop &bishop, std::pair<int,int> coords);
	void move(Rook &rook, std::pair<int,int> coords);
	void move(Knight &knight, std::pair<int,int> coords);
	void move(Pawn &pawn, std::pair<int,int> coords);
	bool anyMovesLeft();
};

#endif
