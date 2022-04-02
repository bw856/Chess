#ifndef __KING_H__
#define __KING_H__

#include "piece.h"
#include <vector>

class King : public Piece {
        public:
        King(char colour, char pieceType);
        virtual std::vector<std::vector<int, int>> validMoves(int posX, int posY, board &Board) = 0;
        void acceptMove(MoveVisotor &mv, int posX, int posY) = 0;
        ~King();
};

