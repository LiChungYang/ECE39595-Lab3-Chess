#include "BishopPiece.hh"
#include "stdio.h"
using Student :: BishopPiece;
using Student :: ChessBoard;

static bool check_x(int start_row, int start_column, int to_row, int to_column)
{
    int check_rowpn = to_row - start_row;
    int check_colpn = to_column - start_column;

    //change them to positive
    if(check_rowpn < 0)
    {
        check_rowpn = check_rowpn * (-1);
    }
    if(check_colpn < 0)
    {
        check_colpn = check_colpn * (-1);
    }

    if(check_rowpn != check_colpn)
    {
        return false;
    }
    else
    {
        return true;
    }
}

static bool check_hit(int start_row, int start_column, int to_row, int to_column, Color cur_color, ChessBoard &Rboard)
{
    int check_rowpn = to_row - start_row;
    int check_colpn = to_column - start_column;
    int plus_rowin;
    int plus_colin;

    //printf("here\n");
    //check the colour are different
    if((Rboard.getPiece(to_row, to_column) != NULL) && (Rboard.getPiece(to_row, to_column))->getColor() == cur_color)
    {
        return false;
    }

    if(check_rowpn > 0)
    {
        plus_rowin = 1;
    }
    else
    {
        plus_rowin = -1;
    }

    if(check_colpn > 0)
    {
        plus_colin = 1;
    }
    else
    {
        plus_colin = -1;
    }
    
    start_row = start_row + plus_rowin;
    start_column = start_column + plus_colin;

    if(start_row == to_row && start_column == to_column)
    {
        return true;
    }
    while(to_row != start_row && to_column != start_column)
    {
        if(Rboard.getPiece(start_row, start_column) != NULL)
        {
            return false;
        }
        start_row = start_row + plus_rowin;
        start_column = start_column + plus_colin;
    }
    return true;
}


bool BishopPiece :: canMoveToLocation(int toRow, int toColumn)
{
    int cur_row = getRow();
    int cur_col = getColumn();
    Color cur_color = getColor();

    if(toRow > c_board.getNumRows() || toRow < 0 || toColumn > c_board.getNumCols() || toColumn < 0)
    {
        return false;
    }

    if(cur_row == toRow && cur_col == toColumn)
    {
        return false;
    }
    return (check_x(cur_row, cur_col, toRow, toColumn) && check_hit(cur_row, cur_col, toRow, toColumn, cur_color, c_board));

}