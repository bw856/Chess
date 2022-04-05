#ifndef __MOVEVISITOR_H__
#define __MOVEVISITOR_H__

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"
#include "board.h"

#include <memory>

class MoveVisitor {
	protected:
	Board &board;
	public:
	MoveVisitor(Board &board);
	virtual void move(King &king, std::pair<int,int> coords) = 0;
	virtual void move(Queen &queen, std::pair<int,int> coords) = 0;
	virtual void move(Bishop &bishop, std::pair<int,int> coords) = 0;
	virtual void move(Rook &rook, std::pair<int,int> coords) = 0;
	virtual void move(Knight &knight, std::pair<int,int> coords) = 0;
	virtual void move(Pawn &pawn, std::pair<int,int> coords) = 0;
	virtual ~MoveVisitor();
};

#endif
