#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
	// command
	string cmd;

	while (cin >> cmd) {
		string pWhite, pBlack;

		if (cmd == "game") {
			bool invalid = false;

			cin >> pWhite >> pBlack;

			// white player
			if (pWhite == "human") {
				//TODO
			} 
			else if (pWhite == "computer1") {
				//TODO
			}
			else if (pWhite == "computer2") {
				//TODO
			} 
			else { invalid = true; }

			// black player
			if (pBlack == "human") {
				//TODO
			} 
			else if (pBlack == "computer1") {
				//TODO
			}
			else if (pBlack == "computer2") {
				//TODO
			}
			else { invalid = true; }

			if (!invalid) {
				// TODO create a new game 
				// TODO display the game (to text, graphic)
			}

		}
		else if (cmd == "resign") {
			//TODO
		}
		else if (cmd == "move") {
			string pos1, pos2;
			cin >> pos1 >> pos2;
			//TODO determine whose move it is
			//TODO actually moving pieces
			//TODO update and display the game

		}
		else if (cmd == "setup") {
			bool inGame; //TODO assign function to return game in progress

			if (!inGame) {
				string cmdSetup;
				while (cin >> cmdSetup) {
					if (cmdSetup == "+") {
						//TODO
					}
					else if (cmdSetup == "-") {
						//TODO
					}
					else if (cmdSetup == "=") {
						//TODO
					}
					else if (cmdSetup == "done") {
						//TODO
					}

				}
			}
		}

	}

	// TODO print final score
	// free any allocated memory
}
