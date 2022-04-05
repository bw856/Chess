#include "blank.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Blank::Blank(): Piece{"nocolor", "Blank"} {};

vector<pair<int,int>> Blank::validMoves(pair<int,int> coords, Board &board) {
	vector<pair<int,int>> noMoves;
	return noMoves;
}

void Blank::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	// no accept move because no moves
}

void Blank::undoMove() {}

Blank::~Blank() {}


