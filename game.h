#ifndef __GAME_H__
#define __GAME_H__

#include "board.h"
//#include "subject.h"
#include "player.h"
#include <utility>
#include <string> // remove this later

class Game /*: public Subject*/ {
	// replace string with <Player>
	std::unique_ptr<std::string> pWhite;
	std::unique_ptr<std::string> pBlack;
	std::shared_ptr<Board> board;
	int scoreWhite = 0;
	int scoreBlack = 0;
	bool inProgress = false;
	std::string turn = "white"; // white is the "first" player to move
	public:
	void start();
	//char getState(int x, int y) const;
	std::shared_ptr<Board> getBoard();
	void winner();
	void getTurn();
	void nextTurn();
	void updateOutput();
	void displayGame();
};

#endif
