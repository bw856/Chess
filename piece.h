#ifndef __PIECE_H__
#define __PIECE_H__

#include <memory>
#include <vector>
#include <string>

class Board;

class Piece {
	std::string color;
	std::string type;
	public:
	Piece(std::string color, std::string type);
	virtual std::vector<std::pair<int,int>> validMoves(std::pair<int, int> coords, Board &b) = 0;
	std::string getColor();
	std::pair<int, int> getPosition();
	std::string getType();
	// add move visitor class and ptr later
	virtual void acceptMove(std::string MoveVisitor, std::pair<int, int> coords) = 0;
	virtual ~Piece();
};

#endif