/***********************************************************************
 * Source File:
 *    PIECE
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "board.h"     // for BOARD
#include "move.h"
#include "piece.h"     // for all the PIECE class definitions
#include "pieceType.h"
#include "position.h"  // for POSITION
#include <set>
using namespace std;


Piece::Piece(const Piece& piece)
{
   this->nMoves = piece.nMoves;
   this->fWhite = piece.fWhite;
   this->position = piece.position;
   this->lastMove = piece.lastMove;
}

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   this->nMoves = rhs.nMoves;
   this->fWhite = rhs.fWhite;
   this->position = rhs.position;
   this->lastMove = rhs.lastMove;
   return *this;
}

bool Piece::operator==(PieceType pt) const
{
   return this->getType() == pt;
}

bool Piece::operator!=(PieceType pt) const
{
   return this->getType() != pt;
}

Move Piece::createNewMove(const Position& newPos, const Board& board) const
{
   return Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, fWhite);
}

void Piece::setLastMove(int currentMove)
{
   lastMove = currentMove;
   nMoves++;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}
