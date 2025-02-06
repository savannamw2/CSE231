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
  pgout->drawBishop(position, fWhite);
}



void Bishop::getMoves(set <Move>& moves, const Board& board) const
{
    int row = position.getRow();
    int col = position.getCol();
    
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
        r = row + possible[i].row;
        c = col + possible[i].col;
        Position newPos(c, r);

        while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[newPos].getType() == PieceType::SPACE)
        {
           moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
            r += possible[i].row;
            c += possible[i].col;
           newPos = Position(c, r);
        }
        
        if (newPos.isValid() && this-> isWhite() != board[newPos].isWhite())
        {
            moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
        }
    }
}
