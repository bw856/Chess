#ifndef __GAME_H__
#define __GAME_H__

#include "board.h"
#include "subject.h"
#include "player.h"
#include <utility>
#include <memory>
#include <string> 

class Player;
class Human;

class Game : public Subject {
	std::shared_ptr<Player> pWhite = nullptr; // later assigned with set functions
	std::shared_ptr<Player> pBlack = nullptr;
	double scoreWhite = 0;
	double scoreBlack = 0;
	std::shared_ptr<Board> board;
	bool inProgress = false;
	std::string turn = "white"; // white is the "first" player to move
	
	public:
	Game();
	void start();
	bool started() const;
	std::shared_ptr<Board> getBoard() const;
	void resetBoard();
	void setpWhite(std::shared_ptr<Player> player1);
	void setpBlack(std::shared_ptr<Player> player2);
	std::shared_ptr<Player> getpWhite() const;
	std::shared_ptr<Player> getpBlack() const;
	std::string getTurn() const;
	std::string nextTurn();	
	std::string getState(int x, int y) const;
	void victor(std::string winner);
	void updateOutput();
	// TODO include functions to determine state of game: check, stalemate, checkmate
	void display();
	void printScore();
};

#endif
