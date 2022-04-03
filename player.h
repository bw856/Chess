#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

class Player {
	std::string color;
	std::string type;
	public:
	Player(std::string color, std::string type);
	std::string getColor();
	std::string getType();
	~Player();
};

#endif
