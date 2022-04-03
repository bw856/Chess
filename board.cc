#include <utility>
#include <vector>
// include "piece.h"
#include "board.h"

using namespace std;

Board::Board() {}

shared_ptr<Piece> Board::getPiece(pair<int,int> coords) { return nullptr; }

void Board::setPiece(shared_ptr<Piece> p, pair<int,int> coords) {}

void Board::movePiece(shared_ptr<Piece> p, pair<int,int> coords, pair<int, int> new_coords) {}

void Board::clear() {}

Board::~Board() {}

