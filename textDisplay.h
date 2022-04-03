#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <memory>

#include "observer.h"
#include "game.h"

// text display for the board, inherits from observer
class TextDisplay : public Observer {
	std::shared_ptr<Game> subject;

	public:
	void notify() override;
	TextDisplay(std::shared_ptr<Game> game);
	~TextDisplay();
};

#endif
