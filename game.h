#ifndef __GAME_H__
#define __GAME_H__

#include "board.h"
#include "subject.h"
#include "player.h"
#include <utility>
#include <string> // remove this later

class Game : public Subject {
	std::unique_ptr<Player> pWhite;
	std::unique_ptr<Player> pBlack;
	std::shared_ptr<Board> board;
	int scoreWhite = 0;
	int scoreBlack = 0;
	bool inProgress = false;
	std::string turn = "white"; // white is the "first" player to move
	public:
	void start();
	std::shared_ptr<Board> getBoard();
	char getState(int x, int y) const;
	void winner();
	void getTurn();
	void nextTurn();
	void updateOutput();
	void displayGame();
};

#endif
