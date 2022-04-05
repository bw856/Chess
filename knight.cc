#include "knight.h"
#include "piece.h"
#include "movevisitor.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Knight::Knight(string color, string type): Piece{color, (color == "white") ? "N" : "n"} {}

vector<pair<int,int>> Knight::validMoves(pair<int,int> coords, Board &b) {
	vector<pair<int,int>> knightMoves;

	// possible positions
	pair<int,int> left2up1{coords.first - 2, coords.second + 1};
	pair<int,int> left1up2{coords.first - 1, coords.second + 2};
	pair<int,int> right2up1{coords.first + 2, coords.second + 1};
	pair<int,int> right1up2{coords.first + 1, coords.second + 2};
	pair<int,int> right2down1{coords.first + 2, coords.second - 1};
	pair<int,int> right1down2{coords.first + 1, coords.second - 2};
	pair<int,int> left2down1{coords.first - 2, coords.second - 1};
	pair<int,int> left1down2{coords.first - 1, coords.second - 2};

	// note: for knights we don't have to check if any pieces are "in their way", just have to check if new pos is within range

	if (left2up1.first >= 0 && left2up1.first <= 7 && left2up1.second >= 0 && left2up1.second <= 7) {
		knightMoves.emplace_back(left2up1);
	}

	if (left1up2.first >= 0 && left1up2.first <= 7 && left1up2.second >= 0 && left1up2.second <= 7) {
		knightMoves.emplace_back(left1up2);
	}

	if (right2up1.first >=0 && right2up1.first <= 7 && right2up1.first >= 0 && right2up1.second <= 7) {
		knightMoves.emplace_back(right2up1);
	}

	if (right1up2.first >= 0 && right1up2.first <= 7 && right1up2.second >= 0 && right1up2.second <= 7) {
		knightMoves.emplace_back(right1up2);
	}

	if (right2down1.first >=0 && right2down1.first <= 7 && right2down1.second >= 0 && right2down1.second <= 7) {
		knightMoves.emplace_back(right2down1);
	}

	if (right1down2.first >= 0 && right1down2.first <= 7 && right1down2.second >= 0 && right1down2.second <= 7) {
		knightMoves.emplace_back(right1down2);
	}

	if (left2down1.first >= 0 && left2down1.first <= 7 && left2down1.second >= 0 && left2down1.second <= 7) {
		knightMoves.emplace_back(left2down1);
	}

	if (left1down2.first >= 0 && left1down2.first <= 7 && left1down2.second >= 0 && left1down2.second <= 7) {
		knightMoves.emplace_back(left1down2);
	}
	
	return knightMoves;
}

void Knight::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	v.move(*this, coords);
}

void Knight::undoMove() {}

Knight::~Knight() {}
