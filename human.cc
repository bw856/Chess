#include "player.h"
#include "human.h"
#include <string>

using namespace std;

Human::Human(string color, string type): Player{color, "Human"} {}

Human::~Human() {}
