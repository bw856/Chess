#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
	// command
	string cmd;

	while (cin >> cmd) {
		
		// first player
		string firstPlayer;
		cin >> firstPlayer;
		
		// Ask user what they would like for player 1
		cin << "Input type for player 1:" << endl;

		// check what "kind" of player they are
		if (firstPlayer == "human") {

		} else if (firstPlayer == "computer") {

		}

		// second player (repeat same stuff as player 1)
		string secondPlayer;
		cin >> secondPlayer;

		cin << "Input type for player 2:" << endl;
		if (secondPlayer == "human") {
		
		} else if (secondPlayer == "computer") {
		
		}

	}
}
