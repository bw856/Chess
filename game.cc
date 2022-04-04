#include <memory>
#include <utility>
#include <iostream>
#include "game.h"
#include "board.h"
#include "subject.h"
#include "player.h"
#include "memory.h"
#include "human.h"

using namespace std;

Game::Game(): pWhite{nullptr}, pBlack{nullptr} {}

void Game::start() {}

char Game::getState(int x, int y) const { return 0; } // returns piece at pos(x, y)

void Game::setpWhite(shared_ptr<Player> player1) { 
//	pWhite = player1; 
	cout << "white player set" << endl;
} //TODO broken

void Game::setpBlack(shared_ptr<Player> player2) {
//	pBlack = nullptr; 
	cout << "black player set" << endl;
} //TODO broken

shared_ptr<Board> Game::getBoard() { return nullptr; }

void Game::winner() {}

void Game::getTurn() {}

void Game::nextTurn() {}

void Game::updateOutput() {}

void Game::displayGame() { notifyObservers(); }
