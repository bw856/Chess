#include "movevisitor.h"
#include "movestalemate.h"

#include <memory>

using namespace std;

const int EMPTY = 0;

MoveStalemate::MoveStalemate(Board &board): MoveVisitor{board} {}

void MoveStalemate::move(King &king, pair<int,int> coords) {
	// get any valid moves
	vector<pair<int,int>> validMoves = king.validMoves(coords, board);

	// if there ARE valid moves, then movesLeft is TRUE (meaning stalemate is FALSE)
	if (validMoves.size() != EMPTY) {
		movesLeft = true;
	}
}

void MoveStalemate::move(Queen &queen, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = queen.validMoves(coords, board);

	if (validMoves.size() != EMPTY) {
		movesLeft = true;
	}
}

void MoveStalemate::move(Bishop &bishop, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = bishop.validMoves(coords, board);

	if (validMoves.size() != EMPTY) {
		movesLeft = true;
	}
}

void MoveStalemate::move(Rook &rook, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = rook.validMoves(coords, board);

	if (validMoves.size() != EMPTY) {
		movesLeft = true;
	}
}

void MoveStalemate::move(Knight &knight, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = knight.validMoves(coords, board);

	if (validMoves.size() != EMPTY) {
		movesLeft = true;
	}
}

void MoveStalemate::move(Pawn &pawn, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = pawn.validMoves(coords, board);

	if (validMoves.size() != EMPTY) {
		movesLeft = true;
	}
}

bool MoveStalemate::anyMovesLeft() { return movesLeft; }
