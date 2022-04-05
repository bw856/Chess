#include <iostream>
#include <utility>
#include <string>
#include <memory>

#include "game.h"
#include "board.h"
#include "human.h"
#include "player.h"
#include "observer.h"
#include "textDisplay.h"
#include "graphicDisplay.h"

using namespace std;

int main() {
	shared_ptr<Game> game;
	vector<shared_ptr<Observer>> displays;

	// command interpreter
	string cmd;
	while (cin >> cmd) {
		if (cmd == "game") {
			cout << "enter game cmd" << endl;
			auto createGame = make_shared<Game>();

			string pWhite, pBlack;
			bool invalid = false;
			cin >> pWhite >> pBlack;

			cout << "before assigning players" << endl;
			// white player
			if (pWhite == "human") {
				createGame->setpWhite(make_shared<Human>("white"));
			} 
			else { invalid = true; }

			// black player
			if (pBlack == "human") {
				createGame->setpBlack(make_shared<Human>("black"));
			} 
			else { invalid = true; }

			cout << "assigned players" << endl;
			// no invalid players > create and start a new game
			if (!invalid) {
				game = createGame;
				game->start();
				displays.emplace_back(make_shared<TextDisplay>(game));
				//displays.emplace_back(make_shared<GraphicDisplay>(game));
				game->display();
			}

			cout << "end of game command" << endl; //TODO remove this

		}
		else if (cmd == "resign") {
			if (game->getTurn() == "white") { game->victor("black"); }
			else if (game->getTurn() == "black") { game->victor("white"); }
		}
		else if (cmd == "move") {
			bool invalid = false;
			string pos1, pos2;
			cin >> pos1 >> pos2;
			pair<int, int> start, end;

			if ((pos1.length() == 2) && (pos2.length() == 2)) { 
				int c1 = pos1.front() - 'a';
				int r1 = pos1.back() - '1';
				int c2 = pos2.front() - 'a';
				int r2 = pos2.back() - '1';
				if ((0 <= c1 && c1 <= 7) || (0 <= r1 && r1 <= 7) || (0 <= c2 && c2 <= 7) || (0 <= r2 && r2 <= 7)) {  
					start = make_pair(c1, r1);
					end = make_pair(c2, r2);
				}
				else { invalid = true; }
			}
			else { invalid = true; }

			if (invalid) { 
				cout << "Invalid Move." << endl; 
				continue;
			}

			string turn = game->getTurn();
			auto piece = game->getBoard()->getPiece(start);
			if (piece->getColor() == turn) { // check if moving player's corresponding piece
				// move piece, return true if successful
				bool validMove = game->getBoard()->movePiece(piece, start, end);
				if (validMove) {
					//TODO check for pawn promotion

					/*//TODO determines if check, checkmate, stalemate
					string status = game->getStatus(); 
					if (status == turn) { board->undoMove(); } // TODO putting self in check
					else {
						game->display();

						if (status == "white") { game->victor("white"); }
						else if (status == "black") { game->victor("black"); }
						else if (status == "stalemate") { game->victor("tie"); }
						game->nextTurn();
					}*/ 
					game->display(); // remove this later
					game->nextTurn(); //remove this later
				}
				else {
					cout << "Invalid Move." << endl;
				}
			}
			else {
				cout << "Invalid Move. Cannot move opposing piece." << endl;

			}

		}
		else if (cmd == "setup") {
			if (!game->started()) {
				//TODO add pieces, figure out which person plays which color side
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
	game->printScore();
	// TODO free any allocated memory?
}
