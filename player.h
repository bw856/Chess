#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

class Player {
	std::string type;
	protected:
	std::string color;
	public:
	Player(std::string type, std::string color);
	std::string getType();
	std::string getColor();
	virtual ~Player();
};

#endif
