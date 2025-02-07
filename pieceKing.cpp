/**
 
 
 
 
 KING
 
 **/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"
#include <iostream>

/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void King::display(ogstream* pgout) const
{
  pgout->drawKing(position, fWhite);
}



void King::getMoves(set<Move>& moves, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();
   Relative possible[8] =
   {
      {-1,  1},
       {0,  1},
       {1,  1},
      {-1,  0},
       {1,  0},
      {-1, -1},
       {0, -1},
       {1, -1}
   };
    
    
   int r, c;
   for (int i = 0; i < 8; i++)
   {
       r = row + possible[i].row;
      c = col + possible[i].col;
      Position newPos(c, r);

      if (newPos.isValid() && (fWhite != board[newPos].isWhite() || board[newPos].getType() == SPACE))
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
   }

   // King-side Castle
   Position ksRookPos(col + 3, row);
   Position ksCastleMovePos(col + 2, row);
   Position rightOfKingPos(col + 1, row);
    
    
   if (nMoves == 0 &&
       ksRookPos.isValid() &&
       ksCastleMovePos.isValid() &&
       rightOfKingPos.isValid() &&
       board[ksRookPos].getType() == PieceType::ROOK &&
       board[ksRookPos].getNMoves() == 0 &&
       board[rightOfKingPos].getType() == PieceType::SPACE &&
       board[ksCastleMovePos].getType() == PieceType::SPACE)
       moves.insert(Move(position, ksCastleMovePos, PieceType::INVALID, board[ksCastleMovePos].getType(), Move::MoveType::CASTLE_KING, isWhite()));

   // Queen-side Castle
   Position qsRookPos(col - 4, row);
   Position rightOfRookPos(col - 3, row);
   Position qsCastleMovePos(col - 2, row);
   Position leftOfKingPos(col - 1, row);
   
    if (nMoves == 0 &&
       qsRookPos.isValid() &&
       qsCastleMovePos.isValid() &&
       board[qsRookPos].getType() == PieceType::ROOK &&
       board[qsRookPos].getNMoves() == 0 &&
       board[leftOfKingPos].getType() == PieceType::SPACE &&
       board[qsCastleMovePos].getType() == PieceType::SPACE &&
       board[rightOfRookPos].getType() == PieceType::SPACE)
       moves.insert(Move(position, qsCastleMovePos, PieceType::INVALID, board[qsCastleMovePos].getType(), Move::MoveType::CASTLE_QUEEN, isWhite()));

}

