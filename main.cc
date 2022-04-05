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
				//	displays.emplace_back(make_shared<GraphicDisplay>(game));
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
					}

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
				// note: make sure the game board is "empty" (game is not already running so every piece is a "Blank")
				shared_ptr<Game> game = make_shared<Game>();
				game->getBoard()->clear();
				string curColor = "white";
				int whiteKingCount = 0;
				int blackKingCount = 0;
				// NOTE: assumes player starts inputting pieces on WHITE, if they wish to change colors, they must use the "=color" command
				while (cin >> cmdSetup) {
					if (cmdSetup == "+") {
						string piece; // reads in piece type
						char x; // reads in x-coord
						char y; // reads in y-coord

						// reads in information
						cin >> piece >> x >> y;

						// convert chars x and y into pair<int,int>
						const char CONVERT_X = 97;
						const char CONVERT_Y = 49;
						int x_comp = x - CONVERT_X;
						int y_comp = y - CONVERT_Y;

						pair<int,int> coords{x_comp, y_comp};

						// Construct Piece and put piece on the board
						if (piece == "K" || piece == "k") {
							game->getBoard()->setPiece(make_shared<King>(curColor, piece), coords);						
						} else if (piece == "Q" || piece == "q") {
							game->getBoard()->setPiece(make_shared<Queen>(curColor, piece), coords);
						} else if (piece == "B" || piece == "b") {
							game->getBoard()->setPiece(make_shared<Bishop>(curColor, piece), coords);
						} else if (piece == "N" || piece == "n") {
							game->getBoard()->setPiece(make_shared<Knight>(curColor, piece), coords);
						} else if (piece == "R" || piece == "r") {
							game->getBoard()->setPiece(make_shared<Rook>(curColor, piece), coords);
						} else if (piece == "P" || piece == "p") {
							game->getBoard()->setPiece(make_shared<Pawn>(curColor, piece), coords);
						}

						// add king count, this is used to satisfy requirements for ONE king per color
						if (piece == "K") {
							whiteKingCount++;
						} else if (piece == "k") {
							blackKingCount++;
						}

						// display board after a change
						game->display();
					}
					else if (cmdSetup == "-") {
						char x;
						char y;
						cin >> x >> y;

						// convert chars x and y into pair<int,int>
						const char CONVERT_X = 97;
						const char CONVERT_Y = 49;
						int x_comp = x - CONVERT_X;
						int y_comp = y - CONVERT_Y;

						pair<int,int> coords{x_comp, y_comp};

						// get the name of the piece at those coords
						string piece = game->getBoard()->getPiece(coords)->getType();

						// remove the piece at that position (replace it with a "Blank" piece)
						game->getBoard()->setPiece(make_shared<Blank>(), coords);

						// subtract king count (if the piece removed was a king), this is used to satisfy requirements for ONE king per color 
						if (piece == "K") {
							whiteKingCount--;
						} else if (piece == "k") {
							blackKingCount--;
						}

						// display board after a change
						game->display();
					}
					else if (cmdSetup == "=") {
						// read in color and sets it to white's turn if inputted white and black's turn if black
						string color;
						cin >> color;
						if (color == "white") {
							curColor = "white";
						} else if (color == "black") {
							curColor = "black";
						}
					}
					else if (cmdSetup == "done") {
						bool pawnsVerified = true;
						bool kingNotCheck = false;

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

						// verify kings are not checked



						// verify all requirements are reached, otherwise displays error message
						if (whiteKingCount == 0 && blackKingCount == 0 && pawnsVerified && kingNotCheck) {
							break;
						} else {
							cout << "Cannot exit setup, following errors have occurred:" << endl;
							if (whiteKingCount > 0) {
								cout << "More than one white king exists!" << endl;
							}

							if (blackKingCount > 0) {
								cout << "More than one black king exists!" << endl;
							}

							if (!pawnsVerified) {
								cout << "Pawns cannot be on the first or last row of the board!" << endl;
							}

							if (!kingNotCheck) {
								cout << "One OR both of the king(s) are in check!" << endl;
							}
						}
					}
				}
			}
		}
	}
	game->printScore();
	// TODO free any allocated memory?
}
