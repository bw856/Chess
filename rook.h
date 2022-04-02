#ifndef __ROOK_H__
#define __ROOK_H__

#include "piece.h"
#include <vector>

class Rook : public Piece {
        public:
        Rook(char colour, char pieceType);
        virtual std::vector<std::vector<int, int>> validMoves(int posX, int posY, board &Board) = 0;
        void acceptMove(MoveVisotor &mv, int posX, int posY) = 0;
        ~Rook();
};

