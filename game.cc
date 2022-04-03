#include "game.h"
#include "board.h"
#include "subject.h"
#include <utility>

using namespace std;

#include <iostream>

Game::Game(): pWhite{nullptr}, pBlack{nullptr} {}

void Game::start() {}

char Game::getState(int x, int y) const { return 0; } // returns piece at pos(x, y)

void Game::setpWhite(shared_ptr<Player> player1) { /*pWhite = player1;*/ } //TODO broken

void Game::setpBlack(shared_ptr<Player> player2) { /*pBlack = player2;*/ } // ^^

shared_ptr<Board> Game::getBoard() { return nullptr; }

void Game::winner() {}

void Game::getTurn() {}

void Game::nextTurn() {}

void Game::updateOutput() {}

void Game::displayGame() { notifyObservers(); }
