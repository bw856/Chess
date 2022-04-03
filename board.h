#ifndef __BOARD_H__
#define __BOARD_H__

#include <utility>
#include <vector>

class Board {
	std::vector<std::vector<shared_ptr<Piece>>> squares;
	public:
	Board();
	void getPiece(std::pair<int, int> coords);
	void setPiece(/* piece */ std::pair<int, int> coords);
	void movePiece(/* piece */ std::pair<int, int> coords, std::pair<int, int> new_coords);
	void clear();
	~Board();
};
