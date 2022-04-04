#include <memory>
#include <utility>
#include <iostream>
#include "game.h"
#include "board.h"
#include "human.h"
#include "player.h"


using namespace std;

Game::Game() {}

void Game::start() {}

char Game::getState(int x, int y) const { return 0; } // returns piece at pos(x, y)

void Game::setpWhite(shared_ptr<Player> player1) { pWhite = player1; } 

void Game::setpBlack(shared_ptr<Player> player2) { pBlack = player2; } 

shared_ptr<Board> Game::getBoard() { return nullptr; }

void Game::winner() {}

void Game::getTurn() {}

void Game::nextTurn() {}

void Game::updateOutput() {}

void Game::displayGame() { notifyObservers(); }
