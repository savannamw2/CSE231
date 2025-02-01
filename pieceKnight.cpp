/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
    pgout->drawKnight(position, fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/

struct possMoves
{
    int col;
    int row;
};

void Knight::getMoves(set <Move>& moves, const Board& board) const
{
       int row = position.getRow();
       int col = position.getCol();
        
    possMoves move[8]
       {
           {-1,  2}, { 1,  2},
           {-2,  1}, { 2,  1},
           {-2, -1}, { 2, -1},
           {-1, -2}, { 1, -2}
       };
    
       int r, c;
       for (int i = 0; i < 8; i++)
       {
          r = row + move[i].row;
          c = col + move[i].col;
          Position newPos(c, r);

          if (0 <= r && r <= 7 && 0 <= c && c <= 7)
             if (board[newPos].getType() == SPACE || (fWhite != board[newPos].isWhite()))
                 moves.insert(Move(position, Position(c, r), PieceType::INVALID, board[Position(c, r)].getType(), Move::MoveType::MOVE, isWhite()));
       }
}
