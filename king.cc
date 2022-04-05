#include "king.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

King::King(string color, string type): Piece{color, (color == "white") ? "K" : "k"} {}

vector<pair<int,int>> King::validMoves(pair<int,int> coords, Board &b) {
	vector<pair<int,int>> temp;
	return temp;
}

void King::acceptMove(MoveVisitor &v, pair<int,int> coords) {
}

King::~King() {}

