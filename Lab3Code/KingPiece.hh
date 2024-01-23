#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"
#include "ChessBoard.hh"


/**
 * Student implementation of a King chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class KingPiece : public ChessPiece
    {
        public:

        KingPiece(ChessBoard &c_board, Color colr, int startRow, int startColumn) : ChessPiece(c_board, colr, startRow, startColumn)
        {
            c_type = King;
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
                return "\u2654";
            }
            else
            {
                return "\u265a";
            }
        }
    };
}

#endif
