#include "pawn.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

Pawn::Pawn(string color, string type): Piece{color, "Pawn"} {}

vector<pair<int,int>> Pawn::validMoves(pair<int,int> coords, Board &board) {
	vector<pair<int,int>> pawnMoves;

	// if direction is 1, it's the white piece (moving +x), if it's -1, it's the black piece (moving -x)
	int direction = 1;
	if (this->getColor() == "black") {
		direction = -1;
	}

	// possible positions
	pair<int,int> up1{coords.first, coords.second + direction};
	pair<int,int> up2{coords.first, coords.second + (2 * direction)};
	pair<int,int> diagRight{coords.first + direction, coords.second + direction};
	pair<int,int> diagLeft{coords.first - direction, coords.second + direction};

	// if moves = 0, means the pawn hasn't moved so it has the option of:
	//	A) moving one forward
	//	B) moving two forward
	if (moves == 0) {
		// if it's within dimensions of the board and no pieces in front of it
		if ((up2.first >= 0 || up2.first <= 7 || up2.second >= 0 || up2.second <= 7)) {
			/*if (board.getPiece(up2.first, up2.second) == nullptr && board->getPiece(up1.first, up1.second) == nullptr) {
				pawnMoves.emplace_back(up2);
			}*/
		}
	}

	// if moves != 0, means:
	//      A) can only move one forward (if there is no piece in front of it)
	if ((up1.first >= 0 || up1.first <= 7 || up1.second >= 0 || up1.second <= 7)) {
		/*if (board.getPiece(up1.first, up1.second) == nullptr) {
			pawnMoves.emplace_back(up1);
		}*/
	}

	// if there is a piece front right or front left of pawn, we can move diagional to "eat" it
	if ((diagRight.first >= 0 || diagRight.first <= 7 || diagRight.second >= 0 || diagRight.second <= 7)) {
		/*if (board.getPiece(diagRight.first, diagRight.second) == nullptr) {
			pawnMoves.emplace_back(diagRight);
		}*/
	}

	if ((diagLeft.first >= 0 || diagLeft.first <= 7 || diagLeft.second >= 0 || diagLeft.second <= 7)) {
		/*if (board.getPiece(diagLeft.first, diagLeft.second) == nullptr) {
			pawnMoves.emplace_back(diagLeft);
		}*/
	}

	++moves;
	return pawnMoves;

}


void Pawn::acceptMove(MoveVisitor &v, pair<int,int> coords) {
	// v.acceptMove(*this, coords);
}

Pawn::~Pawn() {}
