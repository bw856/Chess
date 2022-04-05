#include <memory>
#include <utility>
#include <string>

#include "graphicDisplay.h"
#include "window.h"

#include <iostream> // for debugging (remove later)

using namespace std;

GraphicDisplay::GraphicDisplay(shared_ptr<Game> game) : 
	subject{game}, xwindow{make_shared<Xwindow>()} 
{
	// attach graphicdisplay observer to the game
	subject->attach(make_shared<GraphicDisplay>(*this));
}

GraphicDisplay::~GraphicDisplay() {}

void GraphicDisplay::notify() {
	cout << "enter graphic notify" << endl; //TODO remove this
	/*xwindow->fillRectangle(10, 10, 40, 40, Xwindow::Black);
	xwindow->fillRectangle(50, 10, 40, 40, Xwindow::Red);
	xwindow->fillRectangle(90, 10, 40, 40, Xwindow::Green);
	xwindow->fillRectangle(130, 10, 40, 40, Xwindow::Blue);
	xwindow->fillRectangle(170, 10, 40, 40, Xwindow::Cyan);
	xwindow->fillRectangle(210, 10, 40, 40, Xwindow::White);
	xwindow->fillRectangle(250, 10, 40, 40, Xwindow::Magenta);
	xwindow->fillRectangle(290, 10, 40, 40, Xwindow::Orange);
	xwindow->fillRectangle(290, 10, 40, 40, Xwindow::Brown);
	*/
	// 	iterate rows (top to bottom)
	// 	and for each row, iterate columns (left to right)
	for (int row = 0; row < 8; ++row) {
		bool evenRow = (row % 2 == 0) ? true : false;
		
		for (int col = 0; col < 8; ++col) { 
			bool evenCol = (col % 2 == 0) ? true : false;

			// display the black and white squares on the 8x8 grid:
			// 	fillRectangle(int x, int y, int width, int height, int colour)
			if ((evenRow && evenCol) || (!evenRow && !evenCol)) { 
				xwindow->fillRectangle((col+1)*SIZE + 10, (row*SIZE) + 50, SIZE, SIZE, Xwindow::White); 
			} 
			else if ((evenRow && !evenCol) || (!evenRow && evenCol)) { 
				xwindow->fillRectangle((col+1)*SIZE + 10, (row*SIZE) + 50, SIZE, SIZE, Xwindow::Red); 
			}
		}
	}
	cout << "squares displayed to graphic" << endl; // TODO remove this

	// display pieces (letters) ontop of the squares
	// 	void drawString(int x, int y, std::string msg)
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			string piece = subject->getState(col, row);
			if (piece != "Blank") {
				//string letter = "";
				//letter.push_back('K'); // convert char to string to draw
				xwindow->drawString((col+1)*SIZE + 32, ((5-row)*SIZE) + 175, piece);
			}	
		}
	}
	cout << "pieces displayed to graphic" << endl; // TODO remove this
}
