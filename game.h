#ifndef __GAME_H__
#define __GAME_H__

#include "player.h"
#include "board.h"

class Game {
	Player *white;
	Player *black;
	Board *board;
	int scoreW;
	int scoreB;
	bool inProgress;
	char turn;
	public:
	void start();
	&Board getBoard();
	void winner();
	void getTurn();
	void nextTurn();
	void updateOutput();
	void printGame();
};

