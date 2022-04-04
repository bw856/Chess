#include "knight.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Knight::Knight(string color, string type): Piece{color, "Knight"} {}

vector<pair<int,int>> Knight::validMoves(pair<int,int> coords, Board &b) {
	vector<pair<int,int>> temp;
	return temp;
}

void Knight::acceptMove(MoveVisitor &v, pair<int,int> coords) {
}

Knight::~Knight() {}
