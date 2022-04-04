#include "rook.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Rook::Rook(string color, string type): Piece{color, "Rook"} {}

vector<pair<int,int>> Rook::validMoves(pair<int,int> coords, Board &b) {
	vector<pair<int,int>> temp;
	return temp;
}

void Rook::acceptMove(MoveVisitor &v, pair<int,int> coords) {
}

Rook::~Rook() {}

