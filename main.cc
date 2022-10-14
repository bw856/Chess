#include <iostream>
#include <utility>
#include <string>
#include <memory>

#include "game.h"
#include "board.h"
#include "human.h"
#include "player.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "blank.h"
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
			if (game != nullptr) { game = nullptr; }

			auto createGame = make_shared<Game>();

			string pWhite, pBlack;
			bool invalid = false;
			cin >> pWhite >> pBlack;

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

			// no invalid players > create and start a new game
			if (!invalid) {
				game = createGame;
				game->start();
				displays.emplace_back(make_shared<TextDisplay>(game));
				//	displays.emplace_back(make_shared<GraphicDisplay>(game));
				game->display();
			}

		}
		else if (cmd == "resign") {
			if (game->getTurn() == "white") { game->victor("black"); }
			else if (game->getTurn() == "black") { game->victor("white"); }
			game->printScore(); // display updated score after resignation
			game->display(); // display the new game;
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
				if ((0 <= c1 && c1 <= 7) && (0 <= r1 && r1 <= 7) && (0 <= c2 && c2 <= 7) && (0 <= r2 && r2 <= 7)) {  
					start = make_pair(c1, r1);
					end = make_pair(c2, r2);
				}
				else { invalid = true; }
			}
			else { invalid = true; }

			if (invalid) { 
				cout << "Invalid move input." << endl; 
				continue;
			}

			string turn = game->getTurn();
			auto piece = game->getBoard()->getPiece(start);
			if (piece->getColor() == turn) { // check if moving player's corresponding piece
				// move piece, return true if successful
				bool validMove = game->getBoard()->movePiece(piece, start, end);
				if (validMove) {
					// check for pawn promotion
					bool pawnPromotion = false;
					pair<int,int> pawnCoords;
					string type;
					const int FIRST_ROW = 0;
					const int LAST_ROW = 7;
					for (int i = 0; i <= 7; i++) {
						pair<int,int> first_coords = make_pair(i, FIRST_ROW);
						pair<int,int> last_coords = make_pair(i, LAST_ROW);
						auto piece1 = game->getBoard()->getPiece(first_coords)->getType();
						auto piece2 = game->getBoard()->getPiece(last_coords)->getType();
						if (piece1 == "p" || piece1 == "P") {
							pawnPromotion = true;
							pawnCoords = first_coords;
							type = "black";
							break;

						} else if (piece2 == "p" || piece2 == "P") {
							pawnPromotion = true;
							pawnCoords = last_coords;
							type = "white";
							break;
						}
					}

					// if there is a pawn promotion, then:
					if (pawnPromotion) {
						// read in piece that the user wants
						string newPiece;
						cin >> newPiece;

						// make that new piece and replace the Pawn with that new piece
						if (newPiece == "Q" || newPiece == "q") {
							shared_ptr<Queen> p = make_shared<Queen>(type, newPiece);
							game->getBoard()->setPiece(p, pawnCoords);
						} else if (newPiece == "B" || newPiece == "b") {
							shared_ptr<Bishop> p = make_shared<Bishop>(type, newPiece);
							game->getBoard()->setPiece(p, pawnCoords);
						} else if (newPiece == "R" || newPiece == "r") {
							shared_ptr<Rook> p = make_shared<Rook>(type, newPiece);
							game->getBoard()->setPiece(p, pawnCoords);
						} else if (newPiece == "N" || newPiece == "n") {
							shared_ptr<Knight> p = make_shared<Knight>(type, newPiece);
							game->getBoard()->setPiece(p, pawnCoords);
						}
						else {
							cout << "Invalid Promotion." << endl;
							game->getBoard()->undoMove();
							game->resetStatus();
						}
					}

					// TODO determines if check, checkmate, stalemate
					game->updateStatus();
					string status = game->getStatus(); 
					// cout << "status: " << status << endl;
					if (status == turn) { // TODO putting self in check
						cout << "invalid: putting self in check" << endl;
						game->getBoard()->undoMove();
						game->resetStatus();
					}
					else {
						game->display();

						if (status == "whiteChecked") { 
							cout << "White is in check." << endl; 
						}
						else if (status == "blackChecked") {
							cout << "Black is in check." << endl;
						}
						else if (status == "whiteWins") { game->victor("white"); }
						else if (status == "blackWins") { game->victor("black"); }
						else if (status == "stalemate") { game->victor("tie"); }
						game->nextTurn();
					} 
				}
				else {
					cout << "Invalid Move." << endl;
				}
			}
			else {
				cout << "Invalid Move. Cannot move opposing piece." << endl;
			}
		}
		// requires that game white-player black-player cmd is never ran
		else if (cmd == "setup") {
			// if the game is already started, exit setup cmd
			if (game != nullptr) { continue; }

			game = make_shared<Game>(); // create a new game
			game->getBoard()->clear();  // empty the board

			// playing with two humans if using setup
			game->setpWhite(make_shared<Human>("white"));
			game->setpBlack(make_shared<Human>("black"));

			displays.emplace_back(make_shared<TextDisplay>(game));
			//displays.emplace_back(make_shared<GraphicDisplay>(game));
			game->display(); // display empty initial board

			string nextTurn = "white";  // default initial color is white
			int whiteKingCount = 0;
			int blackKingCount = 0;

			string cmdSetup;
			while (cin >> cmdSetup) {
				if (cmdSetup == "+") {
					bool invalid = false;
					string piece; // reads in piece type
					char xIn; // reads in x-coord (col)
					char yIn; // reads in y-coord (row)

					// reads in information
					cin >> piece >> skipws >> xIn >> yIn;

					// convert chars x and y into pair<int,int>
					const char CONVERT_X = 97;
					const char CONVERT_Y = 49;
					int x = xIn - CONVERT_X;
					int y = yIn - CONVERT_Y;
					pair<int, int> coords;

					if ((0 <= x && x <= 7) || (0 <= y && y <= 7)) {  
						coords = make_pair(x, y);
					}
					else { invalid = true; }

					string oldPiece = game->getBoard()->getPiece(coords)->getType();

					// Construct Piece and put piece on the board
					// white pieces
					if (piece == "K") {
						game->getBoard()->setPiece(make_shared<King>("white", piece), coords);
					} else if (piece == "Q") {
						game->getBoard()->setPiece(make_shared<Queen>("white", piece), coords);
					} else if (piece == "B") {
						game->getBoard()->setPiece(make_shared<Bishop>("white", piece), coords);
					} else if (piece == "N") {
						game->getBoard()->setPiece(make_shared<Knight>("white", piece), coords);
					} else if (piece == "R") {
						game->getBoard()->setPiece(make_shared<Rook>("white", piece), coords);
					} else if (piece == "P") {
						game->getBoard()->setPiece(make_shared<Pawn>("white", piece), coords);
						// black pieces
					} else if (piece == "k") {
						game->getBoard()->setPiece(make_shared<King>("black", piece), coords);
					} else if (piece == "q") {
						game->getBoard()->setPiece(make_shared<Queen>("black", piece), coords);
					} else if (piece == "b") {
						game->getBoard()->setPiece(make_shared<Bishop>("black", piece), coords);
					} else if (piece == "n") {
						game->getBoard()->setPiece(make_shared<Knight>("black", piece), coords);
					} else if (piece == "r") {
						game->getBoard()->setPiece(make_shared<Rook>("black", piece), coords);
					} else if (piece == "p") {
						game->getBoard()->setPiece(make_shared<Pawn>("black", piece), coords);
					} else {
						invalid = true;
					}

					if (invalid) {
						cout << "Invalid Input." << endl;
						continue;
					}

					// add king count, to satisfy requirement of ONE king per color
					if (piece == "K" && oldPiece != "K") {
						whiteKingCount++;
					} else if (piece == "k" && oldPiece != "k") {
						blackKingCount++;
					}

					// display board after a change
					game->display();

				}
				else if (cmdSetup == "-") {
					char xIn;
					char yIn;
					cin >> skipws >> xIn >> yIn;

					// convert chars x and y into pair<int,int>
					const char CONVERT_X = 97;
					const char CONVERT_Y = 49;
					int x = xIn - CONVERT_X;
					int y = yIn - CONVERT_Y;
					pair<int, int> coords;

					if ((0 <= x && x <= 7) || (0 <= y && y <= 7)) {  
						coords = make_pair(x, y);
					}
					else {
						cout << "Invalid Input." << endl;
						continue;
					}

					// get the name of the piece at those coords
					string piece = game->getBoard()->getPiece(coords)->getType();

					// remove the piece at that position (replace it with a "Blank" piece)
					game->getBoard()->setPiece(make_shared<Blank>(), coords);

					// subtract king count (if the piece removed was a king), 
					// 	this is used to satisfy requirements for ONE king per color 
					if (piece == "K") {
						whiteKingCount--;
					} else if (piece == "k") {
						blackKingCount--;
					}

					// display board after a change
					game->display();
				}
				else if (cmdSetup == "=") {
					// sets next turn to inputted color
					string color;
					cin >> color;
					if (color == "white") { nextTurn = "white"; } 
					else if (color == "black") { nextTurn = "black"; }
					cout << "Starting turn set to " << color << endl;
				}
				else if (cmdSetup == "done") {
					bool pawnsVerified = true;
					bool inCheck = false;

					// verify pawns match requirements
					const int FIRST_ROW = 0;
					const int LAST_ROW = 7;
					for (int i = 0; i <= 7; i++) {
						pair<int,int> first_coords = make_pair(i, FIRST_ROW);
						pair<int,int> last_coords = make_pair(i, LAST_ROW);
						auto piece1 = game->getBoard()->getPiece(first_coords)->getType();
						auto piece2 = game->getBoard()->getPiece(last_coords)->getType();
						if (piece1 == "p" || piece1 == "P" || piece2 == "p" || piece2 == "P") {
							pawnsVerified = false;
							break;
						}
					}

					// TODO verify kings are not checked
					game->updateStatus();
					string status = game->getStatus(); 
					  if (status == "white" || status == "black") { inCheck = true; }

					// verify all requirements are reached, otherwise displays error message
					if (whiteKingCount == 1 && blackKingCount == 1 && pawnsVerified && !inCheck) {
						// if nextTurn is set to black, move to "next turn of game" (black)
						// 	else, defaults to start on white
						if (nextTurn == "black") { game->nextTurn(); }
						game->start();
						game->display();
						break;
					} 
					else {
						// cout << "status: " << status << endl; //TODO
						cout << "Cannot exit setup, following errors have occurred:" << endl;
						if (whiteKingCount != 1 || blackKingCount != 1) {
							cout << "Need exactly one of each king." << endl;
						}

						if (!pawnsVerified) {
							cout << "Pawns cannot be on the first or last row of the board." << endl;
						}

						if (inCheck) {
							cout << "One OR both of the king(s) are in check." << endl;
						}
					}
				}
				else {
					cout << "Invalid command." << endl;
				}
			}
		}
		else {
			cout << "Invalid command." << endl;
		}
	}

	game->printScore("final");
	// TODO free any allocated memory?
}
