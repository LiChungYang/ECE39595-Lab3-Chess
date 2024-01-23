#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include <stdio.h>
using Student::ChessBoard;

bool ChessBoard :: is_king_nochecked(Color king_color, int from_row, int from_col, int to_row, int to_col)
{
    //if we are moving king, just return true
    if(getPiece(from_row, from_col)->getType() == King)
    {
        return true;
    }

    

    //find the position of the king first
    int kingrow = -1;
    int kingcol = -1;

    for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
			if(getPiece(i, j) != nullptr && getPiece(i, j)->getColor() == king_color && getPiece(i,j)->getType() ==  King) {
                kingrow = i;
                kingcol = j;
                break;

			}
		}
	}
    
    if(kingrow == -1 && kingcol == -1)
    {
        return true;
    }

    //let the from piece be null, tempory store the from piece, and scan through the board to check if the king safe
    ChessPiece * temp_pp = getPiece(from_row, from_col);
    ChessPiece * temp_pp2 = getPiece(to_row, to_col);

    board.at(to_row).at(to_col) = temp_pp;
    board.at(from_row).at(from_col) = NULL;

    //movePiece(from_row, from_col, to_row, to_col);

    for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
			if(getPiece(i, j) != nullptr && getPiece(i, j)->getColor() != king_color && getPiece(i, j)->canMoveToLocation(kingrow, kingcol)) 
            {
                board.at(from_row).at(from_col) = temp_pp;
                board.at(to_row).at(to_col) = temp_pp2;
				return false;
			}
		}
	}
    board.at(from_row).at(from_col) = temp_pp;
    board.at(to_row).at(to_col) = temp_pp2;
    return true;
}

ChessBoard :: ChessBoard(int numRow, int numCol)
{
    numRows = numRow;
    numCols = numCol;
    board = std :: vector<std::vector<ChessPiece *>> (numRows, std::vector<ChessPiece*> (numCols, nullptr));

}

void ChessBoard :: createChessPiece(Color col, Type ty, int startRow, int startColumn)
{
    if(getPiece(startRow, startColumn) != nullptr)
    {
        delete getPiece(startRow, startColumn);
    }
    
    if(startRow < numRows || startColumn < numCols || startRow >= 0 || startColumn >= 0)
    {
        if(ty == Pawn)
        {
            board.at(startRow).at(startColumn) = new PawnPiece(*this, col, startRow, startColumn);
        }
        else if (ty == Rook)
        {
            board.at(startRow).at(startColumn) = new RookPiece(*this, col, startRow, startColumn);
        }
        else if (ty == Bishop)
        {
            board.at(startRow).at(startColumn) = new BishopPiece(*this, col, startRow, startColumn);
        }
        else if (ty == King)
        {
            if(col == Black)
            {
                num_blackking += 1;
            }
            else if(col == White)
            {
                num_whiteking += 1;
            }

            if(col == Black && num_blackking < 2)
            {
                board.at(startRow).at(startColumn) = new KingPiece(*this, col, startRow, startColumn);
            }

            if(col == White && num_whiteking < 2)
            {
                board.at(startRow).at(startColumn) = new KingPiece(*this, col, startRow, startColumn);
            }
            
        }
    }
}

bool ChessBoard :: movePiece(int fromRow, int fromColumn, int toRow, int toColumn)
{
    //make sure the current position is correct
    //set the current position to the torow, tocol
    //update the location for board
    ChessPiece *cur_piece = board.at(fromRow).at(fromColumn);
    if (board.at(fromRow).at(fromColumn) == nullptr)
    {
        return false;
    }

    if(turn == White && cur_piece->getColor() == turn)
    {

        if(isValidMove(fromRow, fromColumn, toRow, toColumn) == true)
        {
            cur_piece->setPosition(toRow,toColumn);
            //board.at(fromRow).at(fromColumn) = board.at(toRow).at(toColumn);

            board.at(fromRow).at(fromColumn) = nullptr;
            ChessPiece *dest_piece = board.at(toRow).at(toColumn);
            if(dest_piece)
            {
                delete dest_piece;
            }
            board.at(toRow).at(toColumn) = cur_piece;
            turn = Black;
            return true;
        }
    }

    if(turn == Black && cur_piece->getColor() == turn)
    {

        if(isValidMove(fromRow, fromColumn, toRow, toColumn) == true)
        {
            cur_piece->setPosition(toRow,toColumn);
            //board.at(fromRow).at(fromColumn) = board.at(toRow).at(toColumn);
            board.at(fromRow).at(fromColumn) = nullptr;
            ChessPiece *dest_piece = board.at(toRow).at(toColumn);
            if(dest_piece)
            {
                delete dest_piece;
            }
            board.at(toRow).at(toColumn) = cur_piece;
            turn = White;
            return true;
        }
    }

    return false;
    
}

bool ChessBoard :: isValidMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
    //if king is in check, move the king or other to block

    //check bound
    //check from piece is existed
    if(toRow > numRows || toRow < 0 || toColumn > numCols || toColumn < 0)
    {
        return false;
    }

    if(board.at(fromRow).at(fromColumn) == NULL)
    {
        return false;
    }
    
    // printf("board.at(%d).at(%d) == %p\n", fromRow, fromColumn, board.at(fromRow).at(fromColumn));
    ChessPiece *currPiece = board.at(fromRow).at(fromColumn);
    return currPiece -> canMoveToLocation(toRow, toColumn) && is_king_nochecked(currPiece -> getColor(), fromRow, fromColumn, toRow, toColumn);
}

bool ChessBoard :: isPieceUnderThreat(int row, int column)
{
    ChessPiece *cur_piece = board[row][column];

    //check from piece is existed
    if(row > numRows || row < 0 || column > numCols || column < 0)
    {
        return false;
    }

    if (board.at(row).at(column) == nullptr)
    {
        return false;
    }

    for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
            if(board.at(i).at(j))
            {
                ChessPiece *temp_piece = board.at(i).at(j);
                if(temp_piece->getColor() != cur_piece->getColor() && temp_piece->getType() == King && (row - i == 0 || row - i == 1 || row - i == -1) && (column-j == 0 ||column-j == 1 || column-j == -1))
                {
                    //printf("here");
                    return true;
                }
               
                if(temp_piece->getColor() != cur_piece->getColor() && temp_piece->canMoveToLocation(row, column))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}
