/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
*   Savanna and Isabel
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "pieceKing.h"
#include "piecePawn.h"
#include "pieceQueen.h"
#include "pieceBishop.h"
#include "pieceRook.h"
#include "piecePawn.h"
using namespace std;


//// we really REALLY need to delete this.
//Space space;

/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
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

// we really REALLY need to delete this.
Space space(0, 0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   return *(board[pos.getCol()][pos.getRow()]);
   //return space;
}
Piece& Board::operator [] (const Position& pos)
{
   return *(board[pos.getCol()][pos.getRow()]);
   //return space;
}

// Ticket 5
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
   for (int col = 0; col < 8; col++)
   {
      for (int row = 0; row < 8; row++)
         board[col][row] = nullptr;
   }
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
         delete board[col][row];
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

    // King-side Castle
    if ((board[source.getCol()][source.getRow()]->getType() == PieceType::KING) && (move.getMoveType() == Move::MoveType::CASTLE_KING)){
        std::swap(board[source.getCol() + 3][source.getRow()], board[source.getCol() + 1][source.getRow()]);
    }
    
    // Queen-side Castle
    if ((board[source.getCol()][source.getRow()]->getType() == PieceType::KING) &&(move.getMoveType() == Move::MoveType::CASTLE_QUEEN))
       std::swap(board[source.getCol() - 4][source.getRow()], board[source.getCol() - 1][source.getRow()]);

    
    // Pawn promition
    if ((board[source.getCol()][source.getRow()]->getType() == PieceType::PAWN) && (dest.getRow() == 0 || dest.getRow() == 7))
    {
       board[source.getCol()][source.getRow()] = new Queen(source.getCol(), source.getRow());
    }
    
    // En Passant
    if (move.getMoveType() == Move::MoveType::ENPASSANT)
    {
       board[dest.getCol()][dest.getRow() - 1] = new Space(dest.getCol(), dest.getRow());
    }

    std::swap(board[source.getCol()][source.getRow()], board[dest.getCol()][dest.getRow()]);
}

/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty()
{
   delete pSpace;
}
