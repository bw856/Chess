#include <iostream>
#include <utility>
#include <string>

#include "game.h"
#include "board.h"
#include "human.h"
#include "observer.h"
#include "textDisplay.h"

using namespace std;

int main() {
	shared_ptr<Game> game;
	vector<shared_ptr<Observer>> displays;

	// command interpreter
	string cmd;
	while (cin >> cmd) {

		if (cmd == "game") {
			auto createGame = make_shared<Game>();

			string pWhite, pBlack;
			bool invalid = false;
			cin >> pWhite >> pBlack;
			
			cout << "after getting players" << endl;

			// white player
			if (pWhite == "human") {
				game->setpWhite(make_shared<Human>("white")); //TODO this does not work
			} 
			else if (pWhite == "computer1") {
				//TODO
			}
			else { invalid = true; }
			
			cout << "got white player" << endl;			

			// black player
			if (pBlack == "human") {
				game->setpBlack(make_shared<Human>("black"));
			} 
			else if (pBlack == "computer1") {
				//TODO
			}
			else { invalid = true; }
			
			cout << "before invalid check" << endl;
	
			// no invalid players > create a new game
			if (!invalid) {
				game = createGame;
				displays.emplace_back(make_shared<TextDisplay>(game));
				// TODO display game to graphical
				game->displayGame();
			}

			cout << "end of game command" << endl;

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
			bool inGame = false; //TODO assign function to return game in progress

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
