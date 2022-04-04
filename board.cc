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

Board::Board() {
	const int BOARD_LIMIT = 7;

	// initialize every position in the board to be a "blank" piece
	for (int i = 0; i <= BOARD_LIMIT; ++i) {
		for (int j = 0; j <= BOARD_LIMIT; ++j) {
			squares[i][j] = make_shared<Blank>();
		}
	}

	// set up the pieces for white
	squares[0][0] = make_shared<Rook>("white", "Rook");
	squares[1][0] = make_shared<Knight>("white", "Knight");
	squares[2][0] = make_shared<Bishop>("white", "Bishop");
	squares[3][0] = make_shared<Queen>("white", "Queen");
	squares[4][0] = make_shared<King>("white", "King");
	squares[5][0] = make_shared<Bishop>("white", "Bishop");
	squares[6][0] = make_shared<Knight>("white", "Knight");
	squares[7][0] = make_shared<Rook>("white", "Rook");

	// set up pawns for white
	for (int i = 0; i <= BOARD_LIMIT; i++) {
		squares[i][1] = make_shared<Pawn>("white", "Pawn");
	}

	// set up the pieces for black
	squares[0][7] = make_shared<Rook>("black", "Rook");
	squares[1][7] = make_shared<Knight>("black", "Knight");
	squares[2][7] = make_shared<Bishop>("black", "Bishop");
	squares[3][7] = make_shared<Queen>("black", "Queen");
	squares[4][7] = make_shared<King>("black", "King");
	squares[5][7] = make_shared<Bishop>("black", "Bishop");
	squares[6][7] = make_shared<Knight>("black", "Knight");
	squares[7][7] = make_shared<Rook>("black", "Rook");

	// set up pawns for white
	for (int i = 0; i <= BOARD_LIMIT; i++) {
		squares[i][7] = make_shared<Pawn>("black", "Pawn");
	}
}

shared_ptr<Piece> Board::getPiece(pair<int,int> coords) { return squares[coords.first][coords.second]; }

void Board::setPiece(shared_ptr<Piece> p, pair<int,int> coords) { squares[coords.first][coords.second] = p; };

void Board::movePiece(shared_ptr<Piece> p, pair<int,int> coords, pair<int, int> new_coords) {}

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

