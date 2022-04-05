#include <utility>
#include <vector>

#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"
#include "blank.h"
#include "board.h"

using namespace std;

Board::Board(): squares{8, std::vector<std::shared_ptr<Piece>>(8)} {
	const int BOARD_LIMIT = 7;

	// initialize every position in the board to be a "blank" piece
	for (int i = 0; i <= BOARD_LIMIT; ++i) {
		for (int j = 0; j <= BOARD_LIMIT; ++j) {
			squares[i][j] = make_shared<Blank>();
		}
	}

	// set up the pieces for white
	squares[0][0] = make_shared<Rook>("white", "R");
	squares[1][0] = make_shared<Knight>("white", "K");
	squares[2][0] = make_shared<Bishop>("white", "B");
	squares[3][0] = make_shared<Queen>("white", "Q");
	squares[4][0] = make_shared<King>("white", "K");
	squares[5][0] = make_shared<Bishop>("white", "B");
	squares[6][0] = make_shared<Knight>("white", "N");
	squares[7][0] = make_shared<Rook>("white", "R");

	// set up pawns for white
	for (int i = 0; i <= BOARD_LIMIT; i++) {
		squares[i][1] = make_shared<Pawn>("white", "P");
	}

	// set up the pieces for black
	squares[0][7] = make_shared<Rook>("black", "r");
	squares[1][7] = make_shared<Knight>("black", "n");
	squares[2][7] = make_shared<Bishop>("black", "b");
	squares[3][7] = make_shared<Queen>("black", "q");
	squares[4][7] = make_shared<King>("black", "k");
	squares[5][7] = make_shared<Bishop>("black", "b");
	squares[6][7] = make_shared<Knight>("black", "n");
	squares[7][7] = make_shared<Rook>("black", "r");

	// set up pawns for white
	for (int i = 0; i <= BOARD_LIMIT; i++) {
		squares[i][6] = make_shared<Pawn>("black", "p");
	}
}

shared_ptr<Piece> Board::getPiece(pair<int,int> coords) { return squares[coords.first][coords.second]; }

void Board::setPiece(shared_ptr<Piece> p, pair<int,int> coords) { squares[coords.first][coords.second] = p; };

bool Board::movePiece(shared_ptr<Piece> p, pair<int,int> coords, pair<int, int> new_coords) {

	if (p->getType() != "Blank") {
		bool new_coords_true = false;

		// get the Piece's possible moves at the specified coords <int,int>
		vector<pair<int,int>> validMoves = p->validMoves(coords, *this);

		// look through each valid pair
		for (pair<int,int> Move : validMoves) {
			// if one of the valid pairs match the new coords, means it's a valid move, otherwise we can't move the piece to new_coords
			if (Move.first == new_coords.first && Move.second == new_coords.second) {
				new_coords_true = true;
			}
		}

		// means we can move the piece to new_coords (cause it's a valid move)
		if (new_coords_true) {

			// store moves in pieces and coords vectors used for undo
			coords_pair.first = coords;
			coords_pair.second = new_coords;

			pieces.first = p;
			pieces.second = this->getPiece(new_coords);

			// increasing move count by 1 since the move was successful (for the piece)
				p->moves++;

			// move the piece to new coords
			this->setPiece(p, new_coords);

			// set the old coords to be "Blank" piece
			this->setPiece(make_shared<Blank>(), coords);

			// return true because the piece is now moved to new_coords
			return true;
		}
	}
	return false;
}

void Board::undoMove() {
	this->setPiece(pieces.first, coords_pair.first);
	this->setPiece(pieces.second, coords_pair.second);

	// we have to undo the move of the piece that moved
		pieces.first->undoMove();
}

void Board::clear() {
	const int BOARD_LIMIT = 7;

	// reset every piece to be Blank
	for (int i = 0; i <= BOARD_LIMIT; ++i) {
		for (int j = 0; j <= BOARD_LIMIT; ++j) {
			squares[i][j] = make_shared<Blank>();
		}
	}
}

Board::~Board() {}

