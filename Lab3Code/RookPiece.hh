#ifndef _ROOKPIECE_H__
#define _ROOKPIECE_H__

#include "ChessPiece.hh"
#include "ChessBoard.hh"
//#include "stdio.h"

/**
 * Student implementation of a Rook chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class RookPiece : public ChessPiece
    {
        public:

            RookPiece(ChessBoard &c_board, Color colr, int startRow, int startColumn) : ChessPiece(c_board, colr, startRow, startColumn)
            {
                c_type = Rook;
            }

            void setPosition(int row, int column)
            {
                if (canMoveToLocation(row, column) == true)
                {
                    ChessPiece :: setPosition(row, column);
                }
            }

            bool canMoveToLocation(int toRow, int toColumn)
            {
                int cur_row = getRow();
                int cur_col = getColumn();
                Color cur_color = getColor();

                if(cur_row == toRow && cur_col == toColumn)
                {
                    return false;
                }
                
                //printf("%s %d\n", __func__, c_board.getNumRows());

                //check if out of bound
                if(toRow > c_board.getNumRows() || toRow < 0 || toColumn > c_board.getNumCols() || toColumn < 0)
                {
                    return false;
                }

                //no need
                //if colour = white
                //if colour = black
            
                if(cur_row != toRow && cur_col != toColumn)
                {
                    return false;
                }

                if((c_board.getPiece(toRow, toColumn) != NULL) && (c_board.getPiece(toRow, toColumn))->getColor() == cur_color)
                {
                    return false;
                }

                if(cur_row == toRow)
                {
                    if(toColumn - cur_col < 0)
                    {
                        for(int i = cur_col - 1; i > toColumn; i--)
                        {
                            if(c_board.getPiece(toRow, i) != NULL)
                            {
                                return false;
                            }
                        }
                        return true;
                    }
                    else if(toColumn - cur_col > 0)
                    {
                        for(int i = cur_col + 1; i < toColumn; i++)
                        {
                            if(c_board.getPiece(toRow, i) != NULL)
                            {
                                return false;
                            }
                        }
                        return true;
                    }
                    return true;
                }

                else if(cur_col == toColumn)
                {
                    if(toRow - cur_row < 0)
                    {
                        for(int i = cur_row - 1; i > toRow; i--)
                        {
                            if(c_board.getPiece(i, toColumn) != NULL)
                            {
                                return false;
                            }
                        }
                        return true;
                    }
                    else if(toRow - cur_row > 0)
                    {
                        for(int i = cur_row + 1; i < toRow; i++)
                        {
                            if(c_board.getPiece(i, toColumn) != NULL)
                            {
                                return false;
                            }
                        }
                        return true;
                    }
                } 
                return true;
            }

            const char *toString()
            {
                if(c_color == White)
                {
                    return "\u2656";
                }
                else
                {
                    return "\u265c";
                } 
            }
    };
}

#endif
