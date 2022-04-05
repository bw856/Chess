#include "king.h"
#include "piece.h"
#include "movevisitor.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

King::King(string color, string type): Piece{color, (color == "white") ? "K" : "k"} {}

vector<pair<int,int>> King::validMoves(pair<int,int> coords, Board &board) {
	vector<pair<int,int>> kingMoves;

	// possible moves for the king
	pair<int,int> up{coords.first, coords.second + 1};
	pair<int,int> upRight{coords.first + 1, coords.second + 1};
	pair<int,int> upLeft{coords.first - 1, coords.second + 1};
	pair<int,int> down{coords.first, coords.second - 1};
	pair<int,int> downRight{coords.first + 1, coords.second - 1};
	pair<int,int> downLeft{coords.first - 1, coords.second - 1};
	pair<int,int> right{coords.first + 1, coords.second};
	pair<int,int> left{coords.first - 1, coords.second};

	// note: the movevisitor will tell us when the king is in check, validMoves will only contain moves of the king within bounds
	if (up.first >= 0 && up.first <= 7 && up.second >= 0 && up.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(up);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(up);
		}
	}

	if (upRight.first >= 0 && upRight.first <= 7 && upRight.second >= 0 && upRight.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(upRight);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(upRight);
		}
	}

	if (upLeft.first >= 0 && upLeft.first <= 7 && upLeft.second >= 0 && upLeft.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(upLeft);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(upLeft);
		}
	}

	if (down.first >= 0 && down.first <= 7 && down.second >= 0 && down.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(down);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(down);
		}
	}

	if (downRight.first >= 0 && downRight.first <= 7 && downRight.second >= 0 && downRight.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(downRight);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(downRight);
		}
	}

	if (downLeft.first >= 0 && downLeft.first <= 7 && downLeft.second >= 0 && downLeft.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(downLeft);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(downLeft);
		}
	}

	if (right.first >= 0 && right.first <= 7 && right.second >= 0 && right.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(right);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(right);
		}
	}

	if (left.first >= 0 && left.first <= 7 && left.second >= 0 && left.second <= 7) {
		shared_ptr<Piece> p = board.getPiece(left);
		if (p->getType() == "Blank" || (p->getColor() != this->getColor() && p->getColor() != "nocolor")) {
			kingMoves.emplace_back(left);
		}
	}
	++moves;
	return kingMoves;
}

void King::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	v.move(*this, coords);
}

void King::undoMove() { --moves; }

King::~King() {}

