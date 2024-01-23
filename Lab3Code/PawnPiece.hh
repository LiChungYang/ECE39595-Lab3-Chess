#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"
#include "ChessBoard.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class PawnPiece : public ChessPiece
    {
        public:

        PawnPiece(ChessBoard &c_board, Color colr, int startRow, int startColumn) : ChessPiece(c_board, colr, startRow, startColumn)
        {
            c_type = Pawn;
        }

        void setPosition(int row, int column)
        {
            if (canMoveToLocation(row, column) == true)
            {
                ChessPiece :: setPosition(row, column);
            }
        }

        bool canMoveToLocation(int toRow, int toColumn);

        const char *toString()
        {
            if(c_color == White)
            {
                return "\u2659";
            }
            else
            {
                return "\u265f";
            } 
        }

    };
}

#endif
