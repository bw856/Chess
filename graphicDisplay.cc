#include <memory>
#include <utility>
#include <string>

#include "graphicDisplay.h"
#include "window.h"

using namespace std;

GraphicDisplay::GraphicDisplay(shared_ptr<Game> game) : 
	subject{game}, xwindow{make_shared<Xwindow>()} 
{
	// attach graphicdisplay observer to the game
	subject->attach(make_shared<GraphicDisplay>(*this));

	// display the rows and columns 
	for (int i = 0; i < 8; ++i) {
		string number = to_string(i + 1);
		xwindow->drawString(30, 320 - ((i - 2)*SIZE), number);
		string letter;
		letter.push_back(i + 97);
		xwindow->drawString((i + 1)*SIZE + 32, 10*SIZE - 20, letter);
	}
}

GraphicDisplay::~GraphicDisplay() {}

void GraphicDisplay::notify() {
	// 	iterate rows (top to bottom)
	// 	and for each row, iterate columns (left to right)
	for (int row = 0; row < 8; ++row) {
		bool evenRow = (row % 2 == 0) ? true : false;
		
		for (int col = 0; col < 8; ++col) { 
			bool evenCol = (col % 2 == 0) ? true : false;

			// display the black and white squares on the 8x8 grid:
			// 	fillRectangle(int x, int y, int width, int height, int colour)
			if ((evenRow && evenCol) || (!evenRow && !evenCol)) { 
				xwindow->fillRectangle((col+1)*SIZE + 10, (row*SIZE) + 50, SIZE, SIZE, Xwindow::Orange); 
			} 
			else if ((evenRow && !evenCol) || (!evenRow && evenCol)) { 
				xwindow->fillRectangle((col+1)*SIZE + 10, (row*SIZE) + 50, SIZE, SIZE, Xwindow::Brown); 
			}
		}
	}

	// display pieces (letters) ontop of the squares
	// 	void drawString(int x, int y, std::string msg)
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			string piece = subject->getState(col, row);
			if (piece != "Blank") {
				xwindow->drawString((col+1)*SIZE + 32, ((5-row)*SIZE) + 175, piece);
			}	
		}
	}
}
