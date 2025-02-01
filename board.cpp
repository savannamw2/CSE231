/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    Savanna & Isabel
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include <cassert>
using namespace std;


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
   // free everything
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;
   board[1][0] = new Knight(1, 0, false);
   board[6][0] = new Knight(6, 0, false);
   board[1][7] = new Knight(1, 7, true);
   board[6][7] = new Knight(6, 7, true);
}


// we really REALLY need to delete this.
Space space(0,0);

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
void Board::display(const Position & posHover, const Position & posSelect) const
{
    pgout->drawBoard();
    
    
    // draw any selections
    pgout->drawHover(posHover);
    pgout->drawSelected(posSelect);
    
    
    // draw the pieces
    for (const auto& row : board)
    {
        for (const auto& piece : row)
        {
            if (piece != nullptr)
            {
                piece->display(pgout);
            }
        }
        
    }
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
void Board::move(const Move & move)
{
    numMoves++;

    Position source = move.getSrc();
    Position dest = move.getDes();
    
    (*this)[source].setLastMove(getCurrentMove());
    
    if (move.getCapture() != SPACE)
    {
        board[dest.getCol()][dest.getRow()] = new Space(dest.getCol(), dest.getRow());
    }

    std::swap(board[source.getCol()][source.getRow()], board[dest.getCol()][dest.getRow()]);

}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), numMoves(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty()
{
   delete pSpace;
}
