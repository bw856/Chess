#ifndef __BOARD_H__
#define __BOARD_H__

#include "piece.h"
#include <memory>
#include <utility>
#include <vector>

class Piece;

class Board {
	std::vector<std::vector<std::shared_ptr<Piece>>> squares;
	public:
	Board();
	std::shared_ptr<Piece> getPiece(std::pair<int, int> coords);
	void setPiece(std::shared_ptr<Piece> p, std::pair<int, int> coords);
	bool movePiece(std::shared_ptr<Piece> p, std::pair<int, int> coords, std::pair<int, int> new_coords);
	void clear();
	~Board();
};

#endif
