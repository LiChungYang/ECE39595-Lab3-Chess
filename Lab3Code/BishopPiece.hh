#ifndef __BISHOPPIECE_H__
#define __BISHOPPIECE_H__

#include "ChessPiece.hh"
#include "ChessBoard.hh"


/**
 * Student implementation of a Bishop chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class BishopPiece : public ChessPiece
    {
        public:
            BishopPiece(ChessBoard &c_board, Color colr, int startRow, int startColumn) : ChessPiece(c_board, colr, startRow, startColumn)
            {
                c_type = Bishop;
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
                    return "\u2657";
                }
                else
                {
                    return "\u265d";
                } 
            }

        
    };
}

#endif
