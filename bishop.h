#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "piece.h"
#include <vector>

class Bishop : public Piece {
        public:
        Bishop(char colour, char pieceType);
        virtual std::vector<std::vector<int, int>> validMoves(int posX, int posY, board &Board) = 0;
        void acceptMove(MoveVisotor &mv, int posX, int posY) = 0;
        ~Bishop();
};

