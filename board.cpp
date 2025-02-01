/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    Isabel &N Savnna
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "move.h"
#include "piece.h"
#include "pieceKnight.h"
#include "pieceSpace.h"
#include "position.h"
#include "uiDraw.h"
#include <set>
#include <cassert>
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


   board[1][0] = new Knight(1, 0, true);
   board[6][0] = new Knight(6, 0, true);
   board[1][7] = new Knight(1, 7, false);
   board[6][7] = new Knight(6, 7, false);

   
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
   return *(board[pos.getRow()][pos.getCol()]);
}

Piece& Board::operator [] (const Position& pos)
{
   return *(board[pos.getRow()][pos.getCol()]);
}


/***********************************************
* BOARD : DISPLAY
*         Display the board
***********************************************/
void Board::display(const Position& posHover, const Position& posSelect, const set<Move>& possible) const
{
   ogstream gout;

   // draw the checkerboard
   pgout->drawBoard();

   // draw any selections
   pgout->drawHover(posHover);
   pgout->drawSelected(posSelect);

   // draw the possible moves
   set <Move> ::iterator it;
   for (it = possible.begin(); it != possible.end(); ++it)
      gout.drawPossible(it->getDes());

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

    Position source = move.getSrc();
   Position dest = move.getDes();

   (*this)[source].setLastMove(getCurrentMove());


   // change source piece position
   std::swap(board[source.getCol()][source.getRow()], board[dest.getCol()][dest.getRow()]);
   board[dest.getCol()][dest.getRow()]->setPosition(dest);

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
