#include "movevisitor.h"
#include "movecheck.h"

#include <string>
#include <memory>

using namespace std;

MoveCheck::MoveCheck(Board &board): MoveVisitor{board} {}

void MoveCheck::move(King &king, pair<int,int> coords) {

	// get the valid moves
	vector<pair<int,int>> validMoves = king.validMoves(coords, board);

	// if any of the valid moves put the opposite king in check:
	for (pair<int,int> move_coords : validMoves) {
		// get the piece at the coords of the move
		shared_ptr<Piece> p = board.getPiece(move_coords);

		// if the piece at the "move" coordinates is a KING AND the piece putting the king in check is an enemy piece, means it's in check
		if ((p->getType() == "K" && p->getColor() != king.getColor()) || (p->getType() == "k" && p->getColor() != king.getColor())) {
			check = (p->getType() == "K") ? "white" : "black";
			// get out of the loop, already know the king is in check so no point of continuing
			break;
		}
	}
}

void MoveCheck::move(Queen &queen, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = queen.validMoves(coords, board);

	for (pair<int,int> move_coords : validMoves) {
		shared_ptr<Piece> p = board.getPiece(move_coords);

		if ((p->getType() == "K" && p->getColor() != queen.getColor()) || (p->getType() == "k" && p->getColor() != queen.getColor())) {
			check = (p->getType() == "K") ? "white" : "black";
		}
	}
} 

void MoveCheck::move(Bishop &bishop, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = bishop.validMoves(coords, board);

	for (pair<int,int> move_coords : validMoves) {
		shared_ptr<Piece> p = board.getPiece(move_coords);

		if ((p->getType() == "K" && p->getColor() != bishop.getColor()) || (p->getType() == "k" && p->getColor() != bishop.getColor())) {
			check = (p->getType() == "K") ? "white" : "black";
		}
	}
}

void MoveCheck::move(Knight &knight, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = knight.validMoves(coords, board);

	for (pair<int,int> move_coords : validMoves) {
		shared_ptr<Piece> p = board.getPiece(move_coords);

		if ((p->getType() == "K" && p->getColor() != knight.getColor()) || (p->getType() == "k" && p->getColor() != knight.getColor())) {
			check = (p->getType() == "K") ? "white" : "black";
		}
	}
}

void MoveCheck::move(Rook &rook, pair<int,int> coords) {
	vector<pair<int,int>> validMoves = rook.validMoves(coords, board);

	for (pair<int,int> move_coords : validMoves) {
		shared_ptr<Piece> p = board.getPiece(move_coords);

		if ((p->getType() == "K" && p->getColor() != rook.getColor()) || (p->getType() == "k" && p->getColor() != rook.getColor())) {
			check = (p->getType() == "K") ? "white" : "black";
		}
	}
}

void MoveCheck::move(Pawn &pawn, pair<int,int> coords) { 
	vector<pair<int,int>> validMoves = pawn.validMoves(coords, board);

	for (pair<int,int> move_coords : validMoves) {
		shared_ptr<Piece> p = board.getPiece(move_coords);

		if ((p->getType() == "K" && p->getColor() != pawn.getColor()) || (p->getType() == "k" && p->getColor() != pawn.getColor())) {
			check = (p->getType() == "K") ? "white" : "black";
		}
	}
}

string MoveCheck::checkStatus() { return check; }

