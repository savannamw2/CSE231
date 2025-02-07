/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    Savanna & Isabel
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "move.h"
#include "piece.h"
#include "pieceBishop.h"
#include "pieceKing.h"
#include "pieceKnight.h"
#include "piecePawn.h"
#include "pieceQueen.h"
#include "pieceRook.h"
#include "pieceSpace.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"
#include <utility>
#include <iostream>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Fill the board with starting pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8   R N B Q K B N R   8
 *   7   P P P P P P P P   7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2   p p p p p p p p   2
 *   1   r n b q k b n r   1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything
   if (fFree)
      free();

   board[0][0] = new Rook(0, 0, true);
   board[7][0] = new Rook(7, 0, true);
   board[0][7] = new Rook(0, 7, false);
   board[7][7] = new Rook(7, 7, false);
   board[1][0] = new Knight(1, 0, true);
   board[6][0] = new Knight(6, 0, true);
   board[1][7] = new Knight(1, 7, false);
   board[6][7] = new Knight(6, 7, false);
   board[2][0] = new Bishop(2, 0, true);
   board[5][0] = new Bishop(5, 0, true);
   board[2][7] = new Bishop(2, 7, false);
   board[5][7] = new Bishop(5, 7, false);
   board[3][0] = new Queen(3, 0, true);
   board[3][7] = new Queen(3, 7, false);
   board[4][0] = new King(4, 0, true);
   board[4][7] = new King(4, 7, false);

   for (int c = 0; c < 8; c++)
   {
      board[c][1] = new Pawn(c, 1, true); // white pawns
      board[c][6] = new Pawn(c, 6, false); // black pawns
   }
   
   for (int r = 2; r < 6; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = new Space(c, r);
}

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   return *(board[pos.getCol()][pos.getRow()]);
}
Piece& Board::operator [] (const Position& pos)
{
   return *(board[pos.getCol()][pos.getRow()]);
}

/***********************************************
* BOARD : DISPLAY
*         Display the board
***********************************************/
void Board::display(const Position& posHover, const Position& posSelect) const
{
   // draw the checkerboard
   pgout->drawBoard();

   // draw any selections
   pgout->drawHover(posHover);
   pgout->drawSelected(posSelect);

   //// draw the possible moves
   //set <int> ::iterator it;
   //for (it = possible.begin(); it != possible.end(); ++it)
   //   gout.drawPossible(*it);

   // draw the pieces
   for (const auto& row : board)
      for (const auto& piece : row)
         if (piece != nullptr)
            piece->display(pgout);

}

/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   free();
   if (!noreset)
      reset();
}

/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   for (int col = 0; col < 8; col++)
   {
      for (int row = 0; row < 8; row++)
      {
         board[col][row] = nullptr;
      }
   }
}

/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}

/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move& move)
{
   numMoves++;

   Position source = move.getSource();
   Position dest = move.getDest();

   (*this)[source].incrementNMoves();
   (*this)[source].setLastMove(getCurrentMove());

   // Capture
   if (move.getCatpure() != SPACE)
   {
      board[dest.getCol()][dest.getRow()] = new Space(dest.getCol(), dest.getRow());
   }

   // En Passant
   if (move.getMoveType() == Move::MoveType::ENPASSANT)
   {
      board[dest.getCol()][dest.getRow() - 1] = new Space(dest.getCol(), dest.getRow());
   }

   // Pawn promition
   if ((board[source.getCol()][source.getRow()]->getType() == PieceType::PAWN) &&
       (dest.getRow() == 0 || dest.getRow() == 7))
   {
      board[source.getCol()][source.getRow()] = new Queen(source.getCol(), source.getRow());
   }

   // King-side Castle
   if ((board[source.getCol()][source.getRow()]->getType() == PieceType::KING) &&
       (move.getMoveType() == Move::MoveType::CASTLE_KING))
      std::swap(board[source.getCol() + 3][source.getRow()], board[source.getCol() + 1][source.getRow()]);

   // Queen-side Castle
   if ((board[source.getCol()][source.getRow()]->getType() == PieceType::KING) &&
         (move.getMoveType() == Move::MoveType::CASTLE_QUEEN))
      std::swap(board[source.getCol() - 4][source.getRow()], board[source.getCol() - 1][source.getRow()]);



   std::swap(board[source.getCol()][source.getRow()], board[dest.getCol()][dest.getRow()]);
}

/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty()
{
   delete pSpace;
}
