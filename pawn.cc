#include "pawn.h"
#include "board.h"
#include "piece.h"
#include "movevisitor.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Pawn::Pawn(string color, string type): Piece{color, (color == "white") ? "P" : "p"} {}

vector<pair<int,int>> Pawn::validMoves(pair<int,int> coords, Board &board) {
	vector<pair<int,int>> pawnMoves;

	// if direction is 1, it's the white piece (moving +x), if it's -1, it's the black piece (moving -x)
	int direction = 1;
	if (this->getColor() == "black") {
		direction = -1;
	}

	// possible positions
	pair<int,int> up1{coords.first, coords.second + direction};
	pair<int,int> up2{coords.first, coords.second + (2 * direction)};
	pair<int,int> diagRight{coords.first + direction, coords.second + direction};
	pair<int,int> diagLeft{coords.first - direction, coords.second + direction};

	// if moves = 0, means the pawn hasn't moved so it has the option of:
	//	A) moving one forward
	//	B) moving two forward
	if (moves == 0) {
		// if it's within dimensions of the board and no pieces in front of it
		if ((up2.first >= 0 && up2.first <= 7 && up2.second >= 0 && up2.second <= 7)) {
			shared_ptr<Piece> p1 = board.getPiece(up2);
			shared_ptr<Piece> p2 = board.getPiece(up1);
			if (p1->getType() == "Blank" && p2->getType() == "Blank") {
				pawnMoves.emplace_back(up2);
			}
		}
	}

	// if moves != 0, means:
	//      A) can only move one forward (if there is no piece in front of it)
	if ((up1.first >= 0 && up1.first <= 7 && up1.second >= 0 && up1.second <= 7)) {
		shared_ptr<Piece> p = board.getPiece(up1);
		if (p->getType() == "Blank") {
			pawnMoves.emplace_back(up1);
		}
	}

	// if there is a piece front right or front left of pawn, we can move diagional to "eat" it
	if ((diagRight.first >= 0 && diagRight.first <= 7 && diagRight.second >= 0 && diagRight.second <= 7)) {
		shared_ptr<Piece> p = board.getPiece(diagRight);
		// we can only consume the piece if it is a piece that is NOT our piece
		if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
			pawnMoves.emplace_back(diagRight);
		}
	}

	if ((diagLeft.first >= 0 && diagLeft.first <= 7 && diagLeft.second >= 0 && diagLeft.second <= 7)) {
		shared_ptr<Piece> p = board.getPiece(diagLeft);
		if (p->getType() != this->getColor() && p->getColor() != "nocolor") {
			pawnMoves.emplace_back(diagLeft);
		}
	}

	return pawnMoves;
}

void Pawn::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	v.move(*this, coords);
}

void Pawn::undoMove() { --moves; }

Pawn::~Pawn() {}
