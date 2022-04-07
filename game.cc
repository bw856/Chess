#include <memory>
#include <utility>
#include <iostream>
#include <vector>
#include "game.h"
#include "board.h"
#include "human.h"
#include "player.h"
#include "movecheck.h"
#include "movestalemate.h"

using namespace std;

Game::Game(): board{make_shared<Board>()} {}

void Game::start() { 
	inProgress = true; 
	resetStatus();
}

bool Game::started() const { return inProgress; } 


shared_ptr<Board> Game::getBoard() const { return board; }

void Game::resetBoard() {
	board = make_shared<Board>();
	turn = "white";
}


void Game::setpWhite(shared_ptr<Player> player1) { pWhite = player1; } 

void Game::setpBlack(shared_ptr<Player> player2) { pBlack = player2; } 

shared_ptr<Player> Game::getpWhite() const { return pWhite; };

shared_ptr<Player> Game::getpBlack() const { return pBlack; };


string Game::getTurn() const { return turn; }

string Game::nextTurn() { 
	return (turn = (turn == "white") ? "black" : "white");
}

void Game::resetStatus() { status = "none"; }

void Game::updateStatus() {	
	string inCheck = check();
	if (inCheck != "none") { 
		status = (inCheck == "white") ? "whiteChecked" : "blackChecked"; 
		string inCheckmate = checkmate();
		if (inCheckmate != "not") { 
			status = (inCheckmate == "white") ? "blackWins": "whiteWins"; 
		} 
	}
	cout << "checking status: " << status << endl;
	if (stalemate()) { status = "stalemate"; }
	cout << "checking again: " << status << endl;
}

string Game:: getStatus() const { return status; }

string Game::check() {
	MoveCheck anyChecks(*board);
	string inCheck = "none";
	for (int col = 0; col < 8; ++col) {
		for (int row = 0; row < 8; ++row) {
			shared_ptr<Piece> piece = board->getPiece(make_pair(col, row));
			piece->acceptMove(anyChecks, make_pair(col, row));
			inCheck = anyChecks.checkStatus();
			if (inCheck != "none") { break; } 
		}
	}
	return inCheck;
}

string Game::checkmate() {
	bool mated = true; // use a contradiction
	string kingColor, kingType;
	if (status == "whiteChecked") {
		kingColor = "white";
		kingType = "K";
	} else {
		kingColor = "black";
		kingType = "k";
	}
	pair<int, int> kingCoords;
	vector<pair<int, int>> attackedSquares;

	// get all opponent's attacked squares (valid squares of opponent)
	for (int col = 0; col < 8; ++col) {
		for (int row = 0; row < 8; ++row) {
			pair<int, int> coords = make_pair(col, row);
			auto p = board->getPiece(coords);
			if (p->getType() != "Blank" && p->getColor() != kingColor) {
				// concatenate all attacked moves into one vector
				vector<pair<int, int>> attacks = p->validMoves(coords, *board);
				attackedSquares.insert(attackedSquares.end(), attacks.begin(), attacks.end());
			}
			if (p->getType() == kingType && p->getColor() == kingColor) { kingCoords = coords; }
		}
	}

	shared_ptr<Piece> king = board->getPiece(kingCoords);
	vector<pair<int, int>> kingValid = king->validMoves(kingCoords, *board); 

	// iterate over valid moves for king
	// 	if all valid moves result in check, it is checkmate
	for (auto coords : kingValid) {
		bool checked = false;
		for (auto attacked : attackedSquares) {
			if (coords.first == attacked.first && coords.second == attacked.second) {
				checked = true; // king's valid move is an attacked square
				break;
			}
		}
		// satisfied when all attacking squares do not overlap with this king move
		if (!checked) { 
			// check if moving to those coords will cause a check
			board->movePiece(king, kingCoords, coords);
			bool causedCheck = (check() == kingColor);
			board->undoMove();
			if (!causedCheck) { // causes check, keep iterating
				mated = false;
				return "not";
			}
		}
	}
	if (mated) { return kingColor; }
	return "not";
}
/*
bool Game::stalemate() {
	MoveStalemate anyMoves(*board);
	for (int col = 0; col < 8; ++col) {
		for (int row = 0; row < 8; ++row) {
			auto piece = board->getPiece(make_pair(col, row));
			if (turn == piece->getColor()) {
				cout << "matched stale" << endl;
				piece->acceptMove(anyMoves, make_pair(col, row));
				bool movesLeft = anyMoves.anyMovesLeft();
				if (movesLeft) return false; // has moves left, not a stalemate
			}
		}
	}
	return true;
}
*/
/*
bool Game::stalemate() {
	MoveStalemate anyMoves(*board);
	bool movesLeft = false;
	for (int col = 0; col < 8; ++col) {
		for (int row = 0; row < 8; ++row) {
			auto piece = board->getPiece(make_pair(col, row));
			if (piece->getColor() == turn) {
				piece->acceptMove(anyMoves, make_pair(col, row));
				if (anyMoves.anyMovesLeft()) { 
					movesLeft = true;
					break; 
				}
			}
		}
		if (movesLeft) break;
	}
	return !movesLeft;
}
*/

bool Game::stalemate() {
	MoveStalemate anyChecks(*board);
	bool inStalemate;
	for (int col = 0; col < 8; ++col) {
		for (int row = 0; row < 8; ++row) {
			shared_ptr<Piece> piece = board->getPiece(make_pair(col, row));
			piece->acceptMove(anyChecks, make_pair(col, row));
			inStalemate = anyChecks.anyMovesLeft();
			if (inStalemate) { break; }
		}
	}
	return inStalemate;
}

// returns piece at pos(x, y)
string Game::getState(int x, int y) const { 
	auto piece = board->getPiece(make_pair(x, y));
	return piece->getType();
} 

// Allocates the resulting score of the game
void Game::victor(string winner) {
	display();
	if (winner == "white") { 
		++scoreWhite; 
		cout << "White wins!" << endl;
	}
	else if (winner == "black") { 
		++scoreBlack;
		cout << "Black wins!" << endl;
	}
	else if (winner == "tie") {
		scoreWhite += 0.5;
		scoreBlack += 0.5;
		cout << "Stalemate." << endl;
	}
	printScore();
	resetStatus();
	resetBoard();
	display();
}

void Game::display() { notifyObservers(); }

void Game::printScore(string status) {
	if (status == "final") { cout << "Final Score:" << endl; }
	cout << "White: " << scoreWhite << endl;
	cout << "Black: " << scoreBlack << endl;
	cout << "\n" << endl;
}

