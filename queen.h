#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "piece.h"
#include <vector>

class Queen : public Piece {
        public:
        Queen(char colour, char pieceType);
        virtual std::vector<std::vector<int, int>> validMoves(int posX, int posY, board &Board) = 0;
        void acceptMove(MoveVisotor &mv, int posX, int posY) = 0;
        ~Queen();
};

