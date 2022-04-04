#include "bishop.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Bishop::Bishop(string color, string type): Piece{color, "Bishop"} {}

vector<pair<int,int>> Bishop::validMoves(pair<int,int> coords, Board &b) {
	vector<pair<int,int>> temp;
	return temp;
}

void Bishop::acceptMove(MoveVisitor &v, pair<int,int> coords) {
}

Bishop::~Bishop() {}

