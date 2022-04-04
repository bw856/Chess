#include "player.h"
#include <string>

using namespace std;

Player::Player(string type, string color): type{type}, color{color} {}

string Player::getType() { return type; }

string Player::getColor() { return color; }

Player::~Player() {}
