#include "KingPiece.hh"
using Student :: KingPiece;
using Student :: ChessBoard;
#include <iostream>


static bool check_xT(int start_row, int start_column, int to_row, int to_column)
{
    int check_rowpn = to_row - start_row;
    int check_colpn = to_column - start_column;

    //check T
    //horizontal
    if((check_rowpn == 0 && check_colpn == 1) || (check_rowpn == 0 && check_colpn == -1))
    {
        return true;
    }

    //straight
    if((check_colpn == 0 && check_rowpn == 1) || (check_colpn == 0 && check_rowpn == -1))
    {
        return true;
    }

    //check x
    if((check_rowpn == 1 && check_colpn == 1) || (check_rowpn == -1 && check_colpn == -1) || (check_rowpn == -1 && check_colpn == 1) || (check_rowpn == 1 && check_colpn == -1))
    {
        return true;
    }

    return false;
}


static bool check_hit(int start_row, int start_column, int to_row, int to_column, Color cur_color, ChessBoard &Rboard)
{
    //check the colour are different
    if((Rboard.getPiece(to_row, to_column) != NULL) && (Rboard.getPiece(to_row, to_column))->getColor() == cur_color)
    {
        return false;
    }

    return true;

}

static bool check_checkT(int now_row, int now_col, int to_row, int to_column, Color cur_color, ChessBoard &Rboard, int numRows, int numCols)
{
    int temp_row = to_row;
    int temp_column = to_column;
    bool check_right = false;
    bool check_left = false;
    bool check_down = false;
    bool check_up = false;
    int is_first_encounter = 1;

    //if the destination is the king, you can move there
    if(Rboard.getPiece(to_row, temp_column) && Rboard.getPiece(to_row, to_column) -> getType() == King)
    {
        return true;
    }


    //check_checkT
    //horizontal
    //check right
    //if(now_row == to_row)
    //{
    while(temp_column + 1 < numCols && is_first_encounter)
    {
        temp_column = temp_column + 1;
        if(Rboard.getPiece(to_row, temp_column) && (Rboard.getPiece(to_row, temp_column) != Rboard.getPiece(now_row, now_col)))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(to_row, temp_column);
            if(temp_piece == nullptr) {
                std::cout<< "temp_piece == nullptr at (" << to_row << "," << temp_column << ")\n";
            }
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_right = true;
                break;
            }

            //if king and rook
            if(temp_piece->getColor() != cur_color && (temp_column - to_column == 1) && (temp_piece->getType() == Rook || temp_piece->getType() == King))
            {
                return false;
            }

            //only rook
            if(temp_piece->getColor() != cur_color && (temp_column - to_column != 1) && (temp_piece->getType() == Rook))
            {
                //check if there is no piece between the king and the rook
                for(int i = to_column + 1; i < temp_column; i++)
                {
                    if(Rboard.getPiece(to_row, i) != NULL && Rboard.getPiece(to_row, i) != Rboard.getPiece(now_row, now_col))
                    {
                        check_right = true;
                        break;
                    }
                }
                if(check_right != true)
                {
                    return false;
                }
            }

        }
    }

    //go through all the right and no piece at all
    check_right = true;

    temp_row = to_row;
    temp_column = to_column;
    is_first_encounter = 1;

    //check left
    while(temp_column - 1 > -1 && is_first_encounter)
    {
        temp_column = temp_column - 1;
        if(Rboard.getPiece(to_row, temp_column) && Rboard.getPiece(to_row, temp_column) != Rboard.getPiece(now_row, now_col))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(to_row, temp_column);
            if(temp_piece == nullptr) {
                std::cout<< "temp_piece == nullptr at (" << to_row << "," << temp_column << ")\n";
            }
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_left = true;
                break;
            }

            //if king and rook
            if(temp_piece->getColor() != cur_color && (temp_column - to_column == -1) && (temp_piece->getType() == Rook || temp_piece->getType() == King))
            {
                return false;
            }

            //only rook
            if(temp_piece->getColor() != cur_color && (temp_column - to_column != -1) && (temp_piece->getType() == Rook))
            {
                //check if there is no piece between the king and the rook
                for(int i = to_column - 1; i > temp_column; i--)
                {
                    if(Rboard.getPiece(to_row, i) != NULL && Rboard.getPiece(to_row, i) != Rboard.getPiece(now_row, now_col))
                    {
                        check_left = true;
                        break;
                    }
                }
                if(check_left != true)
                {
                    return false;
                }
            }

        }
    }

    //go through all the left and no piece at all
    check_left = true;

    temp_row = to_row;
    temp_column = to_column;
    is_first_encounter = 1;
    //}

    //check_checkT
    //up down
    //if(now_col == to_column)
    //{
    //check down

    while(temp_row + 1 < numRows && is_first_encounter)
    {
        temp_row = temp_row + 1;
        if(Rboard.getPiece(temp_row, to_column) && (Rboard.getPiece(temp_row, to_column) != Rboard.getPiece(now_row, now_col)))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(temp_row, to_column);
            if(temp_piece == nullptr) {
                std::cout<< "temp_piece == nullptr at (" << temp_row << "," << to_column << ")\n";
            }
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_down = true;
                break;
            }

            //if king and rook
            if(temp_piece->getColor() != cur_color && (temp_row - to_row == 1) && (temp_piece->getType() == Rook || temp_piece->getType() == King))
            {
                return false;
            }

            //only rook
            if(temp_piece->getColor() != cur_color && (temp_row - to_row != 1) && (temp_piece->getType() == Rook))
            {
                //check if there is no piece between the king and the rook
                for(int i = to_row + 1; i < temp_row; i++)
                {
                    if(Rboard.getPiece(i, to_column) != NULL && Rboard.getPiece(i, to_column) != Rboard.getPiece(now_row, now_col))
                    {
                        check_down = true;
                        break;
                    }
                }
                if(check_down != true)
                {
                    return false;
                }

            }

        }
    }

    //go through all the right and no piece at all
    check_down = true;

    temp_row = to_row;
    temp_column = to_column;
    is_first_encounter = 1;


    //check_checkT
    //up down
    //check up
    while(temp_row - 1 > -1 && is_first_encounter)
    {
        temp_row = temp_row - 1;
        if(Rboard.getPiece(temp_row, to_column) && (Rboard.getPiece(temp_row, to_column) != Rboard.getPiece(now_row, now_col)))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(temp_row, to_column);
            if(temp_piece == nullptr) {
                std::cout<< "temp_piece == nullptr at (" << temp_row << "," << to_column << ")\n";
            }
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_up = true;
                break;
            }

            //if king and rook
            if(temp_piece->getColor() != cur_color && (temp_row - to_row == -1) && (temp_piece->getType() == Rook || temp_piece->getType() == King))
            {
                return false;
            }

            //only rook
            if(temp_piece->getColor() != cur_color && (temp_row - to_row != -1) && (temp_piece->getType() == Rook))
            {
                //check if there is no piece between the king and the rook
                for(int i = to_row - 1; i > temp_row; i--)
                {
                    if(Rboard.getPiece(i, to_column) != NULL && Rboard.getPiece(i, to_column) != Rboard.getPiece(now_row, now_col))
                    {
                        check_up = true;
                        break;
                    }
                }
                if(check_up != true)
                {
                    return false;
                }

            }

        }
    }

    //go through all the right and no piece at all
    check_up = true;
    //}

    return(check_right || check_left || check_down || check_up);
    
}

static bool check_checkx(int now_row, int now_col, int to_row, int to_column, Color cur_color, ChessBoard &Rboard, int numRows, int numCols)
{
    int temp_row = to_row;
    int temp_column = to_column;
    bool check_leftdown = false;
    bool check_leftup = false;
    bool check_rightup = false;
    bool check_rightdown = false;

    int check_rowpn;
    int check_colpn;
    int is_first_encounter = 1;

    //if the destination is the king, you can move there
    if(Rboard.getPiece(to_row, temp_column) && Rboard.getPiece(to_row, to_column) -> getType() == King)
    {
        return true;
    }

    //check left down
    while(temp_column - 1 > -1 && temp_row + 1 < numRows && is_first_encounter)
    {
        temp_row = temp_row + 1;
        temp_column = temp_column - 1;
        if(Rboard.getPiece(temp_row, temp_column) && Rboard.getPiece(temp_row, temp_column) != Rboard.getPiece(now_row, now_col))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(temp_row, temp_column);
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_leftdown = true;
                break;
            }

            //for the case of pawn
            if(temp_piece->getColor() != cur_color && temp_piece->getColor() == White &&((temp_row - to_row == 1) && (temp_column - to_column == -1)) &&temp_piece->getType() == Pawn)
            {
                return false;
            }        

            //if king and bishop
            if(temp_piece->getColor() != cur_color && ((temp_row - to_row == 1) && (temp_column - to_column == -1)) && (temp_piece->getType() == Bishop || temp_piece->getType() == King))
            {
                return false;
            }

            //only bishop
            if(temp_piece->getColor() != cur_color && (temp_piece->getType() == Bishop))
            {
                //check if there is no piece between the king and the bishop
                check_rowpn = to_row + 1;
                check_colpn = to_column - 1;

                while(temp_row != check_rowpn && to_row != check_colpn)
                {
                    if(Rboard.getPiece(check_rowpn, check_colpn) != NULL && Rboard.getPiece(check_rowpn, check_colpn) != Rboard.getPiece(now_row, now_col))
                    {
                        check_leftdown = true;
                        break;
                    }
                    check_rowpn = check_rowpn + 1;
                    check_colpn = check_colpn - 1;
                }

                if (check_leftdown != true)
                {
                    return false;
                }
            }
        }
    }

    //go through all the left down and no piece at all
    check_leftdown = true;

    temp_row = to_row;
    temp_column = to_column;
    is_first_encounter = 1;


    //check left up
    while(temp_column - 1 > -1 && temp_row - 1 > -1 && is_first_encounter)
    {
        temp_row = temp_row - 1;
        temp_column = temp_column - 1;
        if(Rboard.getPiece(temp_row, temp_column) && Rboard.getPiece(temp_row, temp_column) != Rboard.getPiece(now_row, now_col))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(temp_row, temp_column);
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_leftup = true;
                break;
            }

            //for the case of pawn
            if(temp_piece->getColor() != cur_color && temp_piece->getColor() == Black &&((temp_row - to_row == -1) && (temp_column - to_column == -1)) &&temp_piece->getType() == Pawn)
            {
                return false;
            }

            //if king and bishop
            if(temp_piece->getColor() != cur_color && ((temp_row - to_row == -1) && (temp_column - to_column == -1)) && (temp_piece->getType() == Bishop || temp_piece->getType() == King))
            {
                return false;
            }

            //only bishop
            if(temp_piece->getColor() != cur_color && (temp_piece->getType() == Bishop))
            {
                //check if there is no piece between the king and the bishop
                check_rowpn = to_row - 1;
                check_colpn = to_column - 1;

                while(temp_row != check_rowpn && to_row != check_colpn)
                {
                    if(Rboard.getPiece(check_rowpn, check_colpn) != NULL && Rboard.getPiece(check_rowpn, check_colpn) != Rboard.getPiece(now_row, now_col))
                    {
                        check_leftup = true;
                        break;
                    }
                    check_rowpn = check_rowpn - 1;
                    check_colpn = check_colpn - 1;
                }

                if (check_leftup != true)
                {
                    return false;
                }

            }
        }
    }

    //go through all the left up and no piece at all
    check_leftup = true;

    temp_row = to_row;
    temp_column = to_column;
    is_first_encounter = 1;


    //check right down
    while(temp_column + 1 < numCols && temp_row + 1 < numRows && is_first_encounter)
    {
        temp_row = temp_row + 1;
        temp_column = temp_column + 1;
        if(Rboard.getPiece(temp_row, temp_column) && Rboard.getPiece(temp_row, temp_column) != Rboard.getPiece(now_row, now_col))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(temp_row, temp_column);
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_rightdown = true;
                break;
            }

            //for the case of pawn
            if(temp_piece->getColor() != cur_color && temp_piece->getColor() == White &&((temp_row - to_row == 1) && (temp_column - to_column == 1)) &&temp_piece->getType() == Pawn)
            {
                return false;
            }

            //if king and bishop and king
            if(temp_piece->getColor() != cur_color && ((temp_row - to_row == 1) && (temp_column - to_column == 1)) && (temp_piece->getType() == Bishop || temp_piece->getType() == King))
            {
                return false;
            }

            //only bishop
            if(temp_piece->getColor() != cur_color && (temp_piece->getType() == Bishop))
            {
                //check if there is no piece between the king and the bishop
                check_rowpn = to_row + 1;
                check_colpn = to_column + 1;

                while(temp_row != check_rowpn && to_row != check_colpn)
                {
                    if(Rboard.getPiece(check_rowpn, check_colpn) != NULL && Rboard.getPiece(check_rowpn, check_colpn) != Rboard.getPiece(now_row, now_col))
                    {
                        check_rightdown = true;
                        break;
                    }
                    check_rowpn = check_rowpn + 1;
                    check_colpn = check_colpn + 1;
                }

                if (check_rightdown != true)
                {
                    return false;
                }

            }
        }
    }

    //go through all the right up and no piece at all
    check_rightdown = true;

    temp_row = to_row;
    temp_column = to_column;
    is_first_encounter = 1;


    //check right up
    while(temp_column + 1 < numCols && temp_row - 1 > -1 && is_first_encounter && is_first_encounter)
    {
        temp_row = temp_row - 1;
        temp_column = temp_column + 1;
        if(Rboard.getPiece(temp_row, temp_column) && Rboard.getPiece(temp_row, temp_column) != Rboard.getPiece(now_row, now_col))
        {
            is_first_encounter = 0;
            Student::ChessPiece *temp_piece = Rboard.getPiece(temp_row, temp_column);
            //when the first reach piece is same colour, safe
            if(temp_piece->getColor() == cur_color)
            {
                check_rightup = true;
                break;
            }

            //for the case of pawn
            if(temp_piece->getColor() != cur_color && temp_piece->getColor() == Black &&((temp_row - to_row == -1) && (temp_column - to_column == 1)) &&temp_piece->getType() == Pawn)
            {
                return false;
            }

            //if king and bishop
            if(temp_piece->getColor() != cur_color && ((temp_row - to_row == -1) && (temp_column - to_column == 1)) && (temp_piece->getType() == Bishop || temp_piece->getType() == King))
            {
                return false;
            }

            //only bishop
            if(temp_piece->getColor() != cur_color && (temp_piece->getType() == Bishop))
            {
                //check if there is no piece between the king and the bishop
                check_rowpn = to_row - 1;
                check_colpn = to_column + 1;

                while(temp_row != check_rowpn && to_row != check_colpn)
                {
                    if(Rboard.getPiece(check_rowpn, check_colpn) != NULL && Rboard.getPiece(check_rowpn, check_colpn) != Rboard.getPiece(now_row, now_col))
                    {
                        check_rightup = true;
                        break;
                    }
                    check_rowpn = check_rowpn - 1;
                    check_colpn = check_colpn + 1;
                }

                if (check_rightup != true)
                {
                    return false;
                }

            }
        }
    }

    //go through all the right up and no piece at all
    check_rightup = true;

    return(check_leftup || check_leftdown || check_rightdown || check_rightup);

}


bool KingPiece :: canMoveToLocation(int toRow, int toColumn)
{
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
    bool correct_path = check_xT(cur_row, cur_col, toRow, toColumn);
    bool not_hit = check_hit(cur_row, cur_col, toRow, toColumn, cur_color, c_board);
    bool not_threatened_T = check_checkT(cur_row, cur_col, toRow, toColumn, cur_color, c_board, c_board.getNumRows(), c_board.getNumCols());
    bool not_threatened_X = check_checkx(cur_row, cur_col, toRow, toColumn, cur_color, c_board, c_board.getNumRows(), c_board.getNumCols());
    return (correct_path && not_hit && not_threatened_T && not_threatened_X);

}