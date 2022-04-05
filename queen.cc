#include "queen.h"
#include "piece.h"
#include "movevisitor.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Queen::Queen(string color, string type): Piece{color, (color == "white") ? "Q" : "q"} {}

vector<pair<int,int>> Queen::validMoves(pair<int,int> coords, Board &board) {
	vector<pair<int,int>> queenMoves;

	// queen can move up, down, left, right, and diagionally as many squares as long as its within the board and doesn't go "through" other pieces
	const int BOARD_LIMIT = 7;
	bool upPossible = true;
	bool upRightPossible = true;
	bool upLeftPossible = true;
	bool downPossible = true;
	bool downRightPossible = true;
	bool downLeftPossible = true;
	bool rightPossible = true;
	bool leftPossible = true;

	for (int i = 1; i <= BOARD_LIMIT; ++i) {
		// possible moves for this "cycle"
		pair<int,int> up{coords.first, coords.second + i};
		pair<int,int> upRight{coords.first + i, coords.second + i};
		pair<int,int> upLeft{coords.first - i, coords.second + i};
		pair<int,int> down{coords.first, coords.second - i};
		pair<int,int> downRight{coords.first + i, coords.second - i};
		pair<int,int> downLeft{coords.first - i, coords.second - i};
		pair<int,int> right{coords.first + i, coords.second};
		pair<int,int> left{coords.first - i, coords.second};


		// RIGHT: we only add them to the possible move if it's within the dimensions of the board	
		if (rightPossible && right.first >= 0 && right.first <= 7 && right.second >= 0 && right.second <= 7) {
			// can only move forward IF 1) "Blank" piece in front or 2) to consume enemy piece
			shared_ptr<Piece> p = board.getPiece(right);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(right);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				rightPossible = false;
				queenMoves.emplace_back(right);

			} else {
				rightPossible = false;
			}
		}

		// LEFT: we add to possible moves if it's within the dimensions of the board and until it encounters another piece (includes the
		//position of that piece if diff. color)
		if (leftPossible && left.first >= 0 && left.first <= 7 && left.second >= 0 && left.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(left);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(left);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				leftPossible = false;
				queenMoves.emplace_back(left);

			} else {
				leftPossible = false;
			}
		}

		// UP: same thing but we do this with moving up squares
		if (upPossible && up.first >= 0 && up.first <= 7 && up.second >= 0 && up.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(up);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(up);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				upPossible = false;
				queenMoves.emplace_back(up);

			} else {
				upPossible = false;
			}
		}

		// UPRIGHT:
		if (upRightPossible && upRight.first >= 0 && upRight.first <= 7 && upRight.second >= 0 && upRight.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(upRight);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(upRight);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				upRightPossible = false;
				queenMoves.emplace_back(upRight);

			} else {
				upRightPossible = false;
			}
		}

		// UPLEFT:
		if (upLeftPossible && upLeft.first >= 0 && upLeft.first <= 7 && upLeft.second >= 0 && upLeft.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(upLeft);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(upLeft);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				upLeftPossible = false;
				queenMoves.emplace_back(upLeft);

			} else {
				upLeftPossible = false;
			}
		}

		// DOWN: same thing but we do this with moving down squares
		if (downPossible && down.first >= 0 && down.first <= 7 && down.second >= 0 && down.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(down);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(down);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				downPossible = false;
				queenMoves.emplace_back(down);
			} else {
				downPossible = false;
			}
		}

		// DOWNRIGHT:
		if (downRightPossible && downRight.first >= 0 && downRight.first <= 7 && downRight.second >= 0 && downRight.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(downRight);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(downRight);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				downRightPossible = false;
				queenMoves.emplace_back(downRight);

			} else {
				downRightPossible = false;
			}
		}

		// DOWNLEFT:
		if (downLeftPossible && downLeft.first >= 0 && downLeft.first <= 7 && downLeft.second >= 0 && downLeft.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(downLeft);
			if (p->getType() == "Blank") {
				queenMoves.emplace_back(downLeft);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				downLeftPossible = false;
				queenMoves.emplace_back(downLeft);

			} else {
				downLeftPossible = false;
			}
		}
	}
	return queenMoves;
}

void Queen::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	v.move(*this, coords);
}

void Queen::undoMove() {}

Queen::~Queen() {}

