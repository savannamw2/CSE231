/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    Savanna & Isabel 
 * Summary:
 *    The Pawn class
 ************************************************************************/

#include "board.h"
#include "move.h"
#include "piecePawn.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"
#include <set>

 /**********************************************
  * PAWN : GET POSITIONS
  *********************************************/
void Pawn::getMoves(set<Move>& moves, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();
   int r, c;
   Position newPos;

   if (!fWhite)
   {
      c = col;
      r = row - 2;
      newPos.set(c, r);
      if (row == 6 && board[newPos].getType() == PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      r = row - 1;
      newPos.set(c, r);
      if (r >= 1 && board[newPos].getType() == PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col - 1;
      newPos.set(c, r);
      if (r >= 1 && board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col + 1;
      newPos.set(c, r);
      if (r >= 1 && board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));

      // Black En Passant
      c = col - 1;
      r = row;
      newPos.set(c, r);
      if ((c >= 0) &&
          (r == 3) &&
          (board[newPos].getType() == PieceType::PAWN) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getLastMove() == board.getCurrentMove() - 1))
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col + 1;
      r = row;
      newPos.set(c, r);
      if ((c <  8) &&
          (r == 3) &&
          (board[newPos].getType() == PieceType::PAWN) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getLastMove() == board.getCurrentMove() - 1))
          moves.insert(Move(position, Position(c, r - 1), PieceType::INVALID, board[Position(c, r - 1)].getType(), Move::MoveType::ENPASSANT, isWhite()));

      // Black Promote
      c = col;
      r = row - 1;
      newPos.set(c, r);
      if (r == 0 &&
          board[newPos].getType() == PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::QUEEN, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col - 1;
      newPos.set(c, r);
      if ((c >= 0) &&
          (r == 0) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getType() != PieceType::SPACE))
          moves.insert(Move(position, newPos, PieceType::QUEEN, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col + 1;
      newPos.set(c, r);
      if ((c < 8) &&
          (r == 0) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getType() != PieceType::SPACE))
          moves.insert(Move(position, newPos, PieceType::QUEEN, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
   }
   if (fWhite)
   {
      c = col;
      r = row + 2;
      newPos.set(c, r);
      if (row == 1 && board[newPos].getType() == PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      r = row + 1;
      newPos.set(c, r);
      if (r < 7 && board[newPos].getType() == PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col - 1;
      newPos.set(c, r);
      if (r < 7 && !board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col + 1;
      newPos.set(c, r);
      if (r < 7 && !board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));

      // En Passant
      c = col - 1;
      r = row;
      newPos.set(c, r);
      if ((c >= 0) &&
          (r == 4) &&
          (board[newPos].getType() == PieceType::PAWN) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getLastMove() == board.getCurrentMove() - 1))
          moves.insert(Move(position, Position(c, r+1), PieceType::INVALID, board[Position(c, r+1)].getType(), Move::MoveType::ENPASSANT, isWhite()));
      c = col + 1;
      r = row;
      newPos.set(c, r);
      if ((c <  8) &&
          (r == 4) &&
          (board[newPos].getType() == PieceType::PAWN) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getLastMove() == board.getCurrentMove() - 1))
          moves.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));

      // White Promote
      c = col;
      r = row + 1;
      newPos.set(c, r);
      if (r == 7 &&
          board[newPos].getType() == PieceType::SPACE)
          moves.insert(Move(position, newPos, PieceType::QUEEN, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col - 1;
      newPos.set(c, r);
      if ((c >= 0) &&
          (r == 7) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getType() != PieceType::SPACE))
          moves.insert(Move(position, newPos, PieceType::QUEEN, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
      c = col + 1;
      newPos.set(c, r);
      if ((c < 8) &&
          (r == 7) &&
          (board[newPos].isWhite() != fWhite) &&
          (board[newPos].getType() != PieceType::SPACE))
          moves.insert(Move(position, newPos, PieceType::QUEEN, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
   }
}

/***************************************************
 * PAWN : DRAW
 * Draw the pawn.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}

