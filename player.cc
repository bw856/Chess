#include "player.h"
#include <string>

using namespace std;

Player::Player(string color, string type): color{color}, type{type} {}

string Player::getColor() { return color; }

string Player::getType() { return type; }

Player::~Player() {}

