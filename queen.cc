#include "queen.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Queen::Queen(string color, string type): Piece{color, "Queen"} {}

vector<pair<int,int>> Queen::validMoves(pair<int,int> coords, Board &b) {
	vector<pair<int,int>> temp;
	return temp;
}

void Queen::acceptMove(MoveVisitor &v, pair<int,int> coords) {
}

Queen::~Queen() {}

