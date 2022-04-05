#include <memory>
#include <vector>
#include <string>
#include "piece.h"
#include "board.h"

using namespace std;

Piece::Piece(string color, string type): color{color}, type{type} {}

string Piece::getColor() { return color; }

string Piece::getType() { return type; }

Piece::~Piece() {}
