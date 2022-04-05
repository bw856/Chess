#include <memory>
#include <utility>
#include <iostream>
#include "game.h"
#include "board.h"
#include "human.h"
#include "player.h"


using namespace std;

Game::Game(): board{make_shared<Board>()} {}

void Game::start() { inProgress = true; }

bool Game::started() const { return inProgress; } 


shared_ptr<Board> Game::getBoard() const { return board; }

void Game::resetBoard() {
	board = make_shared<Board>();
	turn == "white";
}


void Game::setpWhite(shared_ptr<Player> player1) { pWhite = player1; } 

void Game::setpBlack(shared_ptr<Player> player2) { pBlack = player2; } 

shared_ptr<Player> Game::getpWhite() const { return pWhite; };

shared_ptr<Player> Game::getpBlack() const { return pBlack; };


string Game::getTurn() const { return turn; }

string Game::nextTurn() { 
	return (turn = (turn == "white") ? "black" : "white");
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

void Game::updateOutput() {} // TODO: check state of game - check, checkmate, stalemate, nothing

void Game::display() { notifyObservers(); }

void Game::printScore(string status) {
	if (status == "final") { cout << "Final Score:" << endl; }
	cout << "White: " << scoreWhite << endl;
	cout << "Black: " << scoreBlack << endl;
	cout << "\n" << endl;
}

