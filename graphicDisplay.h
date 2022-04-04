#ifndef _GRAPHICDISPLAY_H_
#define _GRAPHICDISPLAY_H_

#include <memory>

#include "observer.h"
#include "game.h"
#include "window.h"

// graphic display for the board, inherits from observer
class GraphicDisplay : public Observer {
	std::shared_ptr<Game> subject;
	std::shared_ptr<Xwindow> xwindow;
	const int SIZE = 48;

	public:
	void notify() override;
	GraphicDisplay(std::shared_ptr<Game> game);
	~GraphicDisplay();
};

#endif
