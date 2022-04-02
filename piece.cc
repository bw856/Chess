#include <vector>
#include "piece.h"

using namespace std;

Piece::Piece(char colour, char pieceType): colour{colour}, pieceType{pieceType} {}

char Piece::getColour() { return colour; }

char Piece::getType() { return pieceType; }

Piece::~Piece() {}


