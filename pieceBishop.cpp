/**
 
 
 
 
 
 
 **/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"

/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void Bishop::display(ogstream* pgout) const
{
  pgout->drawKnight(position, fWhite);
}



void Bishop::getMoves(set <Move>& moves, const Board& board) const
{
    Relative possible [4] =
    {
        {1,  1},
        {-1,   -1},
        {-1,  1},
        {1,   -1},
        
    };
    
    int r;
    int c;
    for (int i = 0; i < 4; i++)
    {
        r = position.getRow() + possible[i].row;
        c = position.getCol() + possible[i].col;
        Position newPos(c, r);
        while (r >= 0 && r <= 7 && c >= 0 && c <= 7 && board[newPos].getType() == PieceType::SPACE)
        {
            moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
            newPos.set(position.getCol() + possible[i].col, position.getRow() + possible[i].row);
        }
        
        if (newPos.isValid() && this -> isWhite() != board[newPos].isWhite())
        {
            moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
        }
    }
}
