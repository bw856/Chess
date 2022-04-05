#include "bishop.h"
#include "piece.h"
#include "movevisitor.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Bishop::Bishop(string color, string type): Piece{color, (color == "white") ? "B" : "b"} {}

vector<pair<int,int>> Bishop::validMoves(pair<int,int> coords, Board &board) {
	vector<pair<int,int>> bishopMoves;


	const int BOARD_LIMIT = 7;
	bool upRightPossible = true;
	bool upLeftPossible = true;
	bool downRightPossible = true;
	bool downLeftPossible = true;

	for (int i = 1; i <= BOARD_LIMIT; ++i) {
		// possible moves for this "cycle"
		pair<int,int> diagUpRight{coords.first + i, coords.second + i};
		pair<int,int> diagUpLeft{coords.first - i, coords.second + i};
		pair<int,int> diagDownRight{coords.first + i, coords.second - i};
		pair<int,int> diagDownLeft{coords.first - i, coords.second - i};

		// UPRIGHT: if the move is within the dimensions of the chess board (note: if it encounters a piece of opposing color, this will be the last move in this "direction")
		if (upRightPossible && diagUpRight.first >= 0 && diagUpRight.first <= 7 && diagUpRight.second >= 0 && diagUpRight.second <= 7) {
			// can only move forward IF 1) "Blank" piece in front or 2) to consume enemy piece
			shared_ptr<Piece> p = board.getPiece(diagUpRight);
			if (p->getType() == "Blank") {
				bishopMoves.emplace_back(diagUpRight);
				// note: if getColor == nocolor, means it's a blank piece and we cannot consume a blank piece!
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				upRightPossible = false;
				bishopMoves.emplace_back(diagUpRight);

			} else {
				upRightPossible = false;
			}
		}

		// UPLEFT
		if (upLeftPossible && diagUpLeft.first >= 0 && diagUpLeft.first <= 7 && diagUpLeft.second >= 0 && diagUpLeft.second <= 7) {
			// can only move forward IF 1) "Blank" piece in front or 2) to consume enemy piece
			shared_ptr<Piece> p = board.getPiece(diagUpLeft);
			if (p->getType() == "Blank") {
				bishopMoves.emplace_back(diagUpLeft);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				upLeftPossible = false;
				bishopMoves.emplace_back(diagUpLeft);

			} else {
				upLeftPossible = false;
			}
		}

		// DOWNRIGHT
		if (downRightPossible && diagDownRight.first >= 0 && diagDownRight.first <= 7 && diagDownRight.second >= 0 && diagDownRight.second <= 7) {
			// can only move forward IF 1) "Blank" piece in front or 2) to consume enemy piece
			shared_ptr<Piece> p = board.getPiece(diagDownRight);
			if (p->getType() == "Blank") {
				bishopMoves.emplace_back(diagDownRight);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				downRightPossible = false;
				bishopMoves.emplace_back(diagDownRight);

			} else {
				downRightPossible = false;
			}
		}

		// DOWNLEFT
		if (downLeftPossible && diagDownLeft.first >= 0 && diagDownLeft.first <= 7 && diagDownLeft.second >= 0 && diagDownLeft.second <= 7) {
			// can only move forward IF 1) "Blank" piece in front or 2) to consume enemy piece
			shared_ptr<Piece> p = board.getPiece(diagDownLeft);
			if (p->getType() == "Blank") {
				bishopMoves.emplace_back(diagDownLeft);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				downLeftPossible = false;
				bishopMoves.emplace_back(diagDownLeft);

			} else {
				downLeftPossible = false;
			}
		}
	}
	return bishopMoves;
}

void Bishop::undoMove() {}

void Bishop::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	v.move(*this, coords);
}

Bishop::~Bishop() {}

