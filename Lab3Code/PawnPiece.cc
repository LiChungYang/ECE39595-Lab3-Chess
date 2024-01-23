#include "PawnPiece.hh"
using Student :: PawnPiece;
using Student :: ChessBoard;

static bool checkmove(int start_row, int start_column, int to_row, int to_column, Color colr, ChessBoard &Rboard)
{
    //if colour = white, row = N - 2
    //if colour = black, row = N = 1
    //if is first move, pawn can move 1 or 2 steps
    //also, need to make sure no piece in the destination
    if(colr == White)
    {
        if((start_column - to_column) != 0)
        {
            return false;
        }

        if(start_row - to_row > 2)
        {
            return false;
        }

        if(to_row - start_row < 0)
        {
            for(int i = start_row - 1; i > to_row; i--)
            {
                if(Rboard.getPiece(i, to_column) != NULL)
                {
                    return false;
                }
            }
        }

        if(start_row - to_row < 0)
        {
            return false;
        }

        if(start_row == Rboard.getNumRows() - 2)
        {   if (start_row - to_row == 1)
            {
                return ((start_row-to_row == 1) && (Rboard.getPiece(to_row, to_column) == NULL));
            }
            else if(start_row - to_row == 2)
            {
                return ((Rboard.getPiece(to_row + 1, to_column) == NULL) && (Rboard.getPiece(to_row, to_column) == NULL));
            }
            return true;
        }
        else
        {
            if((start_row - to_row) != 1)
            {
                return false;
            }
            return true;
        }

    }
    else
    {
        if((start_column - to_column) != 0)
        {
            return false;
        }
        if(start_row - to_row > 0)
        {
            return false;
        }

        if(to_row - start_row > 2)
        {
            return false;
        }

        if(to_row - start_row > 0)
        {
            for(int i = start_row + 1; i < to_row; i++)
            {
                if(Rboard.getPiece(i, to_column) != NULL)
                {
                    return false;
                }
            }
        }
        if(start_row == 1)
        {
            if((to_row - start_row) != 1 && (to_row - start_row) != 2 && Rboard.getPiece(to_row, to_column) != NULL)
            {
                return false;
            }
            return true;
        }
        else
        {// && Rboard.getPiece(to_row, to_column) != NULL
            if((to_row - start_row) != 1)
            {
                return false;
            }
        }
        return true;
    }
    
}

static bool checkeat(int start_row, int start_column, int to_row, int to_column, Color colr, ChessBoard &Rboard)
{
    if(colr == White)
    {
        if(to_row - start_row > 0)
        {
            return false;
        }
        if((start_column - to_column) != 1 && (start_column - to_column) != -1 && Rboard.getPiece(to_row, to_column) == NULL)
        {
            return false;
        }
        return true;
    }
    else
    {
        if(to_row - start_row < 0)
        {
            return false;
        }

        if((to_column - start_column) != 1 && (to_column - start_column) != -1 && Rboard.getPiece(to_row, to_column) == NULL)
        {
            return false;
        }
        return true;
    }
}

bool PawnPiece :: canMoveToLocation(int toRow, int toColumn)
{
    //1. move
    //2. eat

    int cur_row = getRow();
    int cur_col = getColumn();
    Color cur_color = getColor();

    //check if there is no moving
    if(cur_row == toRow && cur_col == toColumn)
    {
        
        return false;
    }

    //check out of bound
    if(toRow > c_board.getNumRows() || toRow < 0 || toColumn > c_board.getNumCols() || toColumn < 0)
    {
        return false;
    }

    //want to move straigt but there is something
    if((c_board.getPiece(toRow, toColumn) != NULL) && (cur_col - toColumn) == 0)
    {
        return false;
    }

    //horizontal move
    if((cur_row - toRow) == 0 && (cur_col - toColumn) != 0)
    {
        return false;
    }

    //printf("cur_row%d, cur_col%d\n", cur_row, cur_col);
    //printf("toRow%d, toColumn%d\n", toRow, toColumn);

    if(c_board.getPiece(toRow, toColumn) == NULL)
    {
        return checkmove(cur_row, cur_col, toRow, toColumn, cur_color, c_board);
    }

    //check eat colour
    if((c_board.getPiece(toRow, toColumn) != NULL) && (cur_color == c_board.getPiece(toRow, toColumn)->getColor()) && (cur_row - toRow == 1 || cur_row - toRow == -1) && (cur_col - toColumn == 1 || cur_col - toColumn  == -1))
    {
        return false;
    }

    if((c_board.getPiece(toRow, toColumn) != NULL) && (cur_color != c_board.getPiece(toRow, toColumn)->getColor()) && (cur_row - toRow == 1 || cur_row - toRow == -1) && (cur_col - toColumn == 1 || cur_col - toColumn  == -1))
    {
        checkeat(cur_row, cur_col, toRow, toColumn, cur_color, c_board);
    }

    if((cur_row - toRow != 1 && cur_row - toRow != -1) || (cur_col - toColumn != 1 && cur_col - toColumn  != -1))
    {
        return false;
    }

    return checkmove(cur_row, cur_col, toRow, toColumn, cur_color, c_board) || checkeat(cur_row, cur_col, toRow, toColumn, cur_color, c_board);
}

