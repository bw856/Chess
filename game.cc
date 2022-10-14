#include <memory>
#include <utility>
#include <iostream>
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
//	string inCheckmate = checkmate();
	if (inCheck != "none") { status = inCheck; }
//	if (inCheckmate != "none") { status = inCheckmate; }
//	if (stalemate) { status = "tie"; }
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
	return "";
}

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
	if (winner == "white") { ++scoreWhite; }
	else if (winner == "black") { ++scoreBlack; }
	else if (winner == "tie") {
		scoreWhite += 0.5;
		scoreBlack += 0.5;
	}
	resetBoard();
}

void Game::updateOutput() {
	// check state of game - check, checkmate, stalemate, nothing

}

void Game::display() { notifyObservers(); }

void Game::printScore(string status) {
	if (status == "final") { cout << "Final Score:" << endl; }
	cout << "White: " << scoreWhite << endl;
	cout << "Black: " << scoreBlack << endl;
	cout << "\n" << endl;
}

