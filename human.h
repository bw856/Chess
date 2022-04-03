#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.h"
#include <string>

class Human : public Player {
	Human(std::string color);
	~Human();
};

#endif
