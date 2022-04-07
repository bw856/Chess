#include <memory>
#include <iostream>

#include "textDisplay.h"

using namespace std;

TextDisplay::TextDisplay(shared_ptr<Game> game) : subject{game} {
	// attach textdisplay observer to the game
	subject->attach(make_shared<TextDisplay>(*this));
}

TextDisplay::~TextDisplay() {}

void TextDisplay::notify() {
	// iterate over 8 rows (top to bottom) 
	// and for each row, iterate over 8 columns (left to right)
	for (int row = 8; row > 0; --row) {
		cout << row << " "; // print row number followed by space

		bool evenRow = (row % 2 == 0) ? true : false;

		for (int col = 0; col < 8; ++col) { 
			string piece = subject->getState(col, row - 1);
			if (piece != "Blank") {
				cout << piece; // print piece
			}
			else {
				// black square = hyphen
				// white square = blank
				bool evenCol = (col % 2 == 0) ? true : false;
				if 		((evenRow && evenCol) || (!evenRow && !evenCol)) { cout << " "; } 
				else if ((evenRow && !evenCol) || (!evenRow && evenCol)) { cout << "-"; }
			}
		}
		cout << endl; // end of row, newline
	}

	cout << "  ";
	for (char letter = 'a'; letter <= 'h'; ++letter) cout << letter;
	cout << "\n" << endl;
}
