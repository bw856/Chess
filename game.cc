#include "game.h"
#include "board.h"
#include <utility>

using namespace std;

void Game::start() {}

// char getState(int x, int y) { return 0; }

shared_ptr<Board> Game::getBoard() { return nullptr; }

void Game::winner() {}

void Game::getTurn() {}

void Game::nextTurn() {}

void Game::updateOutput() {}

void Game::displayGame() {}
