#include "rook.h"
#include "piece.h"
#include "movevisitor.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Rook::Rook(string color, string type): Piece{color, (color == "white") ? "R" : "r"} {}

vector<pair<int,int>> Rook::validMoves(pair<int,int> coords, Board &board) {
	vector<pair<int,int>> rookMoves;

	// rook can move X pieces vertically or horizontally as long as it doesn't exceed the board itself
	// 	at MOST, can move 7 in one direction
	const int BOARD_LIMIT = 7;
	bool upPossible = true;
	bool downPossible = true;
	bool rightPossible = true;
	bool leftPossible = true;

	for (int i = 1; i <= BOARD_LIMIT; ++i) {
		// possible moves

		// move to right
		pair<int,int> right{coords.first + i, coords.second};

		// move to left
		pair<int,int> left {coords.first - i, coords.second};

		// move down
		pair<int,int> down{coords.first, coords.second - i};

		// move up
		pair<int,int> up{coords.first, coords.second + i};

		// we only add them to the possible move if it's within the dimensions of the board	
		if (rightPossible && right.first >= 0 && right.first <= 7 && right.second >= 0 && right.second <= 7) {
			// can only move forward IF 1) "Blank" piece in front or 2) to consume enemy piece
			shared_ptr<Piece> p = board.getPiece(right);
			if (p->getType() == "Blank") {
				rookMoves.emplace_back(right);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				rightPossible = false;
				rookMoves.emplace_back(right);

			} else {
				rightPossible = false;
			}
		}

		// we add to possible moves if it's within the dimensions of the board and until it encounters another piece (includes the position of that piece if diff. color)
		if (leftPossible && left.first >= 0 && left.first <= 7 && left.second >= 0 && left.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(left);
			if (p->getType() == "Blank") {
				rookMoves.emplace_back(left);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				leftPossible = false;
				rookMoves.emplace_back(left);

			} else {
				leftPossible = false;
			}
		}

		// same thing but we do this with moving up squares
		if (upPossible && up.first >= 0 && up.first <= 7 && up.second >= 0 && up.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(up);
			if (p->getType() == "Blank") {
				rookMoves.emplace_back(up);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				upPossible = false;
				rookMoves.emplace_back(up);
			
			} else {
				upPossible = false;
			}
		}

		// same thing but we do this with moving down squares
		if (downPossible && down.first >= 0 && down.first <= 7 && down.second >= 0 && down.second <= 7) {
			shared_ptr<Piece> p = board.getPiece(down);
			if (p->getType() == "Blank") {
				rookMoves.emplace_back(down);
			} else if (p->getColor() != this->getColor() && p->getColor() != "nocolor") {
				downPossible = false;
				rookMoves.emplace_back(down);
			
			} else {
				downPossible = false;
			}
		}
	}
	++moves;
	return rookMoves;
}

void Rook::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	v.move(*this, coords);
}

void Rook::undoMove() { --moves; }

Rook::~Rook() {}

