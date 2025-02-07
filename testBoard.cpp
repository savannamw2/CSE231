/***********************************************************************
 * Source File:
 *    TEST BOARD
 * Author:
 *    Savanna & Isabel
 * Summary:
 *    The unit tests for board
 ************************************************************************/


#include "board.h"
#include "move.h"
#include "piece.h"
#include "piecePawn.h"
#include "pieceType.h"
#include "position.h"
#include "testBoard.h"
#include "unitTest.h"


 /***********************************************
  * CREATE DUMMY BOARD : Constructor for DummyBoard
  * Setup:
  * VERIFY: all squares have the null pointer
  ***********************************************/
void TestBoard::construct_dummyBoard()
{  // SETUP
   // EXERCISE
   BoardDummy board;
   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(nullptr == board.board[0][0]);
   assertUnit(nullptr == board.board[1][0]);
   assertUnit(nullptr == board.board[2][0]);
   assertUnit(nullptr == board.board[3][0]);
   assertUnit(nullptr == board.board[4][0]);
   assertUnit(nullptr == board.board[5][0]);
   assertUnit(nullptr == board.board[6][0]);
   assertUnit(nullptr == board.board[7][0]);
   assertUnit(nullptr == board.board[0][1]);
   assertUnit(nullptr == board.board[1][1]);
   assertUnit(nullptr == board.board[2][1]);
   assertUnit(nullptr == board.board[3][1]);
   assertUnit(nullptr == board.board[4][1]);
   assertUnit(nullptr == board.board[5][1]);
   assertUnit(nullptr == board.board[6][1]);
   assertUnit(nullptr == board.board[7][1]);
   assertUnit(nullptr == board.board[0][2]);
   assertUnit(nullptr == board.board[1][2]);
   assertUnit(nullptr == board.board[2][2]);
   assertUnit(nullptr == board.board[3][2]);
   assertUnit(nullptr == board.board[4][2]);
   assertUnit(nullptr == board.board[5][2]);
   assertUnit(nullptr == board.board[6][2]);
   assertUnit(nullptr == board.board[7][2]);
   assertUnit(nullptr == board.board[0][3]);
   assertUnit(nullptr == board.board[1][3]);
   assertUnit(nullptr == board.board[2][3]);
   assertUnit(nullptr == board.board[3][3]);
   assertUnit(nullptr == board.board[4][3]);
   assertUnit(nullptr == board.board[5][3]);
   assertUnit(nullptr == board.board[6][3]);
   assertUnit(nullptr == board.board[7][3]);
   assertUnit(nullptr == board.board[0][4]);
   assertUnit(nullptr == board.board[1][4]);
   assertUnit(nullptr == board.board[2][4]);
   assertUnit(nullptr == board.board[3][4]);
   assertUnit(nullptr == board.board[4][4]);
   assertUnit(nullptr == board.board[5][4]);
   assertUnit(nullptr == board.board[6][4]);
   assertUnit(nullptr == board.board[7][4]);
   assertUnit(nullptr == board.board[0][5]);
   assertUnit(nullptr == board.board[1][5]);
   assertUnit(nullptr == board.board[2][5]);
   assertUnit(nullptr == board.board[3][5]);
   assertUnit(nullptr == board.board[4][5]);
   assertUnit(nullptr == board.board[5][5]);
   assertUnit(nullptr == board.board[6][5]);
   assertUnit(nullptr == board.board[7][5]);
   assertUnit(nullptr == board.board[0][6]);
   assertUnit(nullptr == board.board[1][6]);
   assertUnit(nullptr == board.board[2][6]);
   assertUnit(nullptr == board.board[3][6]);
   assertUnit(nullptr == board.board[4][6]);
   assertUnit(nullptr == board.board[5][6]);
   assertUnit(nullptr == board.board[6][6]);
   assertUnit(nullptr == board.board[7][6]);
   assertUnit(nullptr == board.board[0][7]);
   assertUnit(nullptr == board.board[1][7]);
   assertUnit(nullptr == board.board[2][7]);
   assertUnit(nullptr == board.board[3][7]);
   assertUnit(nullptr == board.board[4][7]);
   assertUnit(nullptr == board.board[5][7]);
   assertUnit(nullptr == board.board[6][7]);
   assertUnit(nullptr == board.board[7][7]);
}  // TEARDOWN

 /***********************************************
  * CREATE EMPTY BOARD : Constructor for BoardEmpty
  * Setup:
  * VERIFY: all squares have the null pointer
  ***********************************************/
void TestBoard::construct_emptyBoard()
{  // SETUP
   // EXERCISE
   BoardEmpty board;
   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(nullptr == board.board[0][0]);
   assertUnit(nullptr == board.board[1][0]);
   assertUnit(nullptr == board.board[2][0]);
   assertUnit(nullptr == board.board[3][0]);
   assertUnit(nullptr == board.board[4][0]);
   assertUnit(nullptr == board.board[5][0]);
   assertUnit(nullptr == board.board[6][0]);
   assertUnit(nullptr == board.board[7][0]);
   assertUnit(nullptr == board.board[0][1]);
   assertUnit(nullptr == board.board[1][1]);
   assertUnit(nullptr == board.board[2][1]);
   assertUnit(nullptr == board.board[3][1]);
   assertUnit(nullptr == board.board[4][1]);
   assertUnit(nullptr == board.board[5][1]);
   assertUnit(nullptr == board.board[6][1]);
   assertUnit(nullptr == board.board[7][1]);
   assertUnit(nullptr == board.board[0][2]);
   assertUnit(nullptr == board.board[1][2]);
   assertUnit(nullptr == board.board[2][2]);
   assertUnit(nullptr == board.board[3][2]);
   assertUnit(nullptr == board.board[4][2]);
   assertUnit(nullptr == board.board[5][2]);
   assertUnit(nullptr == board.board[6][2]);
   assertUnit(nullptr == board.board[7][2]);
   assertUnit(nullptr == board.board[0][3]);
   assertUnit(nullptr == board.board[1][3]);
   assertUnit(nullptr == board.board[2][3]);
   assertUnit(nullptr == board.board[3][3]);
   assertUnit(nullptr == board.board[4][3]);
   assertUnit(nullptr == board.board[5][3]);
   assertUnit(nullptr == board.board[6][3]);
   assertUnit(nullptr == board.board[7][3]);
   assertUnit(nullptr == board.board[0][4]);
   assertUnit(nullptr == board.board[1][4]);
   assertUnit(nullptr == board.board[2][4]);
   assertUnit(nullptr == board.board[3][4]);
   assertUnit(nullptr == board.board[4][4]);
   assertUnit(nullptr == board.board[5][4]);
   assertUnit(nullptr == board.board[6][4]);
   assertUnit(nullptr == board.board[7][4]);
   assertUnit(nullptr == board.board[0][5]);
   assertUnit(nullptr == board.board[1][5]);
   assertUnit(nullptr == board.board[2][5]);
   assertUnit(nullptr == board.board[3][5]);
   assertUnit(nullptr == board.board[4][5]);
   assertUnit(nullptr == board.board[5][5]);
   assertUnit(nullptr == board.board[6][5]);
   assertUnit(nullptr == board.board[7][5]);
   assertUnit(nullptr == board.board[0][6]);
   assertUnit(nullptr == board.board[1][6]);
   assertUnit(nullptr == board.board[2][6]);
   assertUnit(nullptr == board.board[3][6]);
   assertUnit(nullptr == board.board[4][6]);
   assertUnit(nullptr == board.board[5][6]);
   assertUnit(nullptr == board.board[6][6]);
   assertUnit(nullptr == board.board[7][6]);
   assertUnit(nullptr == board.board[0][7]);
   assertUnit(nullptr == board.board[1][7]);
   assertUnit(nullptr == board.board[2][7]);
   assertUnit(nullptr == board.board[3][7]);
   assertUnit(nullptr == board.board[4][7]);
   assertUnit(nullptr == board.board[5][7]);
   assertUnit(nullptr == board.board[6][7]);
   assertUnit(nullptr == board.board[7][7]);
}  // TEARDOWN


/***********************************************
 * GET CURRENT MOVE : initially the board is empty
 * Setup:  board.numMoves=0
 * VERIFY: moveNumber=0
 ***********************************************/
void TestBoard::getCurrentMove_initial()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 0;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(moveNumber == 0);
}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : second move
 * Setup:  board.numMoves=1
 * VERIFY: moveNumber=1
 ***********************************************/
void TestBoard::getCurrentMove_second()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 1;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(moveNumber == 1);
}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : white turn in the middle of the game
 * Setup:  board.numMoves=4
 * VERIFY: moveNumber=4
 ***********************************************/
void TestBoard::getCurrentMove_middleWhite()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 4;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(4 == board.numMoves);
   assertUnit(moveNumber == 4);
}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : black turn in the middle of the game
 * Setup:  board.numMoves=5
 * VERIFY: moveNumber=5
 ***********************************************/
void TestBoard::getCurrentMove_middleBlack()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 5;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(5 == board.numMoves);
   assertUnit(moveNumber == 5);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : initially the board is empty
 * Setup:  board.numMoves=0
 * VERIFY: isWhiteTurn=true
 ***********************************************/
void TestBoard::whiteTurn_initial()
{  // SETUP
   Board board;
   board.numMoves = 0;
   createDummyBoard(board);
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(isWhiteTurn == true);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : second move
 * Setup:  board.numMoves=1
 * VERIFY: isWhiteTurn=false
 ***********************************************/
void TestBoard::whiteTurn_second()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 1;
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(isWhiteTurn == false);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : white turn in the middle of the game
 * Setup:  board.numMoves=4
 * VERIFY: isWhiteTurn=true
 ***********************************************/
void TestBoard::whiteTurn_middleWhite()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 4;
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(4 == board.numMoves);
   assertUnit(isWhiteTurn == true);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : black turn in the middle of the game
 * Setup:  board.numMoves=5
 * VERIFY: isWhiteTurn=false
 ***********************************************/
void TestBoard::whiteTurn_middleBlack()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 5;
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(5 == board.numMoves);
   assertUnit(isWhiteTurn == false);
}  // TEARDOWN

class Position00 : public Position
{
public:
   int getRow() const { return 0; }
   int getCol() const { return 0; }
};

/***********************************************
 * FETCH : a1
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1  (x)                1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_a1()
{  // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[0][0];
   board.board[0][0] = &piece;
   Position00 pos;
   Piece* p = nullptr;
   // exercise
   p = &(board[pos]);
   // verify
   assertUnit(p == &piece);
   // teardown
   board.board[0][0] = pSave;
}

void TestBoard::set_a1()
{  // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[0][0];
   board.board[0][0] = &piece;
   Position00 pos;
   Piece* p = nullptr;
   // exercise
   board[pos].fWhite = false;
   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[0][0]->fWhite == false);
   // teardown
   board.board[0][0] = pSave;
}

class Position77 : public Position
{
public:
   int getRow() const { return 7; }
   int getCol() const { return 7; }
};

/***********************************************
 * FETCH : h8
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                (x)  8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_h8()
{  // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[7][7];
   board.board[7][7] = &piece;
   Position77 pos;
   Piece* p = nullptr;
   // exercise
   p = &(board[pos]);
   // verify
   assertUnit(p == &piece);
   // teardown
   board.board[7][7] = pSave;
}

void TestBoard::set_h8()
{  // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[7][7];
   board.board[7][7] = &piece;
   Position77 pos;
   Piece* p = nullptr;
   // exercise
   board[pos].fWhite = false;
   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[7][7]->fWhite == false);
   // teardown
   board.board[7][7] = pSave;
}

class Position07 : public Position
{
public:
   int getRow() const { return 7; }
   int getCol() const { return 0; }
};

/***********************************************
 * FETCH : a8
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8  (x)                8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_a8()
{  // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[0][7];
   board.board[0][7] = &piece;
   Position07 pos;
   Piece* p = nullptr;
   // exercise
   p = &(board[pos]);
   // verify
   assertUnit(p == &piece);
   // teardown
   board.board[0][7] = pSave;
}

void TestBoard::set_a8()
{  // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[0][7];
   board.board[0][7] = &piece;
   Position07 pos;
   Piece* p = nullptr;
   // exercise
   board[pos].fWhite = false;
   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[0][7]->fWhite == false);
   // teardown
   board.board[0][7] = pSave;
}

/********************************************************
 *    e5c6
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6       .             6       6       n             6
 * 5          (n)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_knightMove()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(2, 5);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;
}

/********************************************************
*    e5c6r
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
* |                     |       |                     |
* 8                     8       8                     8
* 7       R             7       7                     7
* 6                     6       6       n             6
* 5          (n)        5       5           .         5
* 4                     4  -->  4                     4
* 3                     3       3                     3
* 2                     2       2                     2
* 1                     1       1                     1
* |                     |       |                     |
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_knightAttack()
{
   // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(2, 5);
   move.capture = ROOK;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, ROOK);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;
}



/***********************************************
 * CREATE DUMMY BOARD
 * Utility function - not a unit test
 * Just fill the board with the known pieces
 ***********************************************/
void TestBoard::createDummyBoard(Board& board)
{
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
      {
         board.board[c][r] = new PieceDummy;
      }
}


/********************************************************
 *   a2a3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3   .                 3       3   p                 3
 * 2  (p)                2       2   .                 2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnSimple()
{
   // SETUP
   Move move;
   move.source.set(0, 1);
   move.dest.set(0, 2);
   move.capture = SPACE;
   move.promote = INVALID;
   move.isWhite = true;
   move.moveType = Move::MoveType::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.board[0][1] = new PieceSpy(0, 1, true  /*isWhite*/, PAWN);
   board.board[0][2] = new PieceSpy(0, 2);
   board.board[0][1]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(Move("a2a3"));

   // VERIFY
   assertUnit(board.board[0][1]->getType() == SPACE);
   assertUnit(board.board[0][2]->getType() == PAWN);
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][1];
   delete board.board[0][2];
   board.board[0][1] = nullptr;
   board.board[0][2] = nullptr;
}


/********************************************************
 *     a6b7r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7     R               7       7    (p)              7
 * 6  (p)                6       6   .                 6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnCapture()
{
   Move move;
   move.source.set(0, 5);
   move.dest.set(1, 6);
   move.capture = ROOK;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[0][5] = new PieceSpy(0, 5, true  /*isWhite*/, PAWN);
   board.board[1][6] = new PieceSpy(1, 6, false /*isWhite*/, ROOK);
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(SPACE == (board.board[0][5])->getType());
   assertUnit(PAWN == (board.board[1][6])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][5];
   delete board.board[1][6];
   board.board[0][5] = board.board[1][6] = nullptr;
}


/********************************************************
 *    e2e4
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4           .         4  -->  4          (p)        4
 * 3                     3       3                     3
 * 2          (p)        2       2           .         2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnDouble()
{
   // SETUP
   Board board;
   board.board[4][1] = new PieceSpy(4, 1, true, PAWN);
   board.board[4][1]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(Move("e2e4"));

   // VERIFY
   assertUnit(board.board[4][1]->getType() == SPACE);
   assertUnit(board.board[4][3]->getType() == PAWN);
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   board.board[0][1] = nullptr;
   board.board[0][3] = nullptr;
}


/********************************************************
*     a5b6E
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6     .               6       6     p               6
 * 5  (p)P               5       5   . .               5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnEnpassant()
{
   // SETUP
   Board board;
   board.numMoves = 1;
   board.board[0][4] = new PieceSpy(0, 4, true, PAWN); // white pawn
   board.board[0][4]->nMoves = 2;
   board.board[1][4] = new PieceSpy(1, 4, false, PAWN);
   board.board[1][4]->nMoves = 1;
   board.board[1][4]->lastMove = 4;
   board.numMoves = 4;
   Move move;
   move.source.colRow = 0x04;
   move.dest.colRow = 0x15;
   move.isWhite = true;
   move.moveType = Move::MoveType::ENPASSANT;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(board.board[0][4]->getType() == SPACE);
   assertUnit(board.board[1][4]->getType() == SPACE);
   assertUnit(board.board[1][5]->getType() == PAWN);
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   board.board[0][4] = nullptr;
   board.board[1][4] = nullptr;
   delete board.board[1][5];
   board.board[1][5] = nullptr;
}


/********************************************************
 *    a7a8Q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8   .                 8       8  (q)                8
 * 7  (p)                7       7   .                 7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnPromotion()
{
   // SETUP
   Move move;
   move.source.set(0, 6);
   move.dest.set(0, 7);
   move.promote = QUEEN;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[0][6] = new PieceSpy(0, 6, true  /*isWhite*/, PAWN);
   board.board[0][6]->nMoves = 1;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(QUEEN == (board.board[0][7])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][6];
   delete board.board[0][7];
   board.board[0][6] = board.board[0][7] = nullptr;
}


/********************************************************
 *    e5a5
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   .      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookSlide()
{
   // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(0, 4);
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, ROOK);
   board.board[4][4]->nMoves = 1;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(ROOK == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}

/********************************************************
 *    e5a5b
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   B      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookAttack()
{
   Move move;
   move.source.set(4, 4);
   move.dest.set(0, 4);
   move.capture = BISHOP;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, ROOK);
   board.board[0][4] = new PieceSpy(0, 4, false /*isWhite*/, BISHOP);
   board.board[4][4]->nMoves = 1;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(ROOK == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][4];
   delete board.board[4][4];
   board.board[0][4] = board.board[4][4] = nullptr;
}


/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               .     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopSlide()
{
   // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(6, 2);
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, BISHOP);
   board.board[4][4]->nMoves = 1;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(BISHOP == (board.board[6][2])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[6][2];
   delete board.board[4][4];
   board.board[6][2] = board.board[4][4] = nullptr;
}


/********************************************************
 *    e5g3q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               Q     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopAttack()
{
   Move move;
   move.source.set(4, 4);
   move.dest.set(6, 2);
   move.capture = QUEEN;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, BISHOP);
   board.board[6][2] = new PieceSpy(6, 2, false /*isWhite*/, QUEEN);
   board.board[4][4]->nMoves = 1;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(BISHOP == (board.board[6][2])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[6][2];
   board.board[4][4] = board.board[6][2] = nullptr;
}

/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (q)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               .     3       3               q     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_queenSlide()
{
      // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(6, 2);
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 2;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, QUEEN);
   board.board[4][4]->nMoves = 2;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(board.numMoves == 3);
   assertUnit(PieceType::QUEEN == board.board[6][2]->getType());
   assertUnit(PieceType::SPACE == board.board[4][4]->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[6][2];
   board.board[6][2] = board.board[4][4] = nullptr;
}


/********************************************************
*    e5a5b
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
* |                     |       |                     |
* 8                     8       8                     8
* 7                     7       7                     7
* 6                     6       6                     6
* 5   B      (q)        5       5  (q)      .         5
* 4                     4  -->  4                     4
* 3                     3       3                     3
* 2                     2       2                     2
* 1                     1       1                     1
* |                     |       |                     |
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
********************************************************/
void TestBoard::move_queenAttack()
{
   Move move;
   move.source.set(4, 4);
   move.dest.set(0, 4);
   move.capture = BISHOP;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, QUEEN);
   board.board[0][4] = new PieceSpy(0, 4, false /*isWhite*/, BISHOP);
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(QUEEN == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}


/********************************************************
 *  e1f1
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k).       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingMove()
{
   // SETUP
   Move move;
   move.source.set(4, 0);
   move.dest.set(5, 0);
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   PieceSpy::reset();
   board.board[4][0]->nMoves = 1;

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(KING == (board.board[5][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[5][0];
   board.board[4][0] = board.board[5][0] = nullptr;
}


/********************************************************
 *    e1f1r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k)R       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingAttack()
{
   Move move;
   move.source.set(4, 0);
   move.dest.set(5, 0);
   move.capture = ROOK;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 1;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   board.board[5][0] = new PieceSpy(5, 0, false /*isWhite*/, ROOK);
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(2 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(KING == (board.board[5][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[5][0];
   board.board[4][0] = board.board[5][0] = nullptr;
}

/********************************************************
 *    e1g1c
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k). . r   1       1           . r k .   1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingShortCastle()
{
   Move move;
   move.source.set(4, 0);
   move.dest.set(6, 0);
   move.isWhite = true;
   move.moveType = Move::CASTLE_KING;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   board.board[5][0] = new PieceSpy(5, 0);
   board.board[6][0] = new PieceSpy(6, 0);
   board.board[7][0] = new PieceSpy(7, 0, false /*isWhite*/, ROOK);
   board.board[4][0]->nMoves = 0;
   board.board[7][0]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(KING == (board.board[6][0])->getType());
   assertUnit(ROOK == (board.board[5][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[6][0]; // Delete king
   delete board.board[5][0]; // Delete rook
   delete board.board[4][0]; // Delete space
   delete board.board[7][0]; // Delete space
   board.board[7][0] = board.board[6][0] = board.board[5][0] = board.board[4][0] = nullptr;
}



/********************************************************
 *    e1c1C
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1   r . . .(k)        1       1   . . k r .         1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingLongCastle()
{
   Move move;
   move.source.set(4, 0);
   move.dest.set(2, 0);
   move.isWhite = true;
   move.moveType = Move::CASTLE_QUEEN;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 0;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   board.board[3][0] = new PieceSpy(3, 0);
   board.board[2][0] = new PieceSpy(2, 0);
   board.board[1][0] = new PieceSpy(1, 0);
   board.board[0][0] = new PieceSpy(0, 0, true /*isWhite*/, ROOK);
   board.board[4][0]->nMoves = 0;
   board.board[0][0]->nMoves = 0;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(KING == (board.board[2][0])->getType());
   assertUnit(ROOK == (board.board[3][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][0]; // Delete space
   delete board.board[1][0]; // Delete space
   delete board.board[2][0]; // Delete king
   delete board.board[3][0]; // Delete rook
   delete board.board[4][0]; // Delete space
   board.board[0][0] = board.board[1][0] = board.board[2][0] = board.board[3][0] = board.board[4][0] = nullptr;
}




/********************************************************
 *        +---a-b-c-d-e-f-g-h---+
 *        |                     |
 *        8   R N B Q K B N R   8
 *        7   P P P P P P P P   7
 *        6                     6
 *        5                     5
 *   -->  4                     4
 *        3                     3
 *        2   p p p p p p p p   2
 *        1   r n b q k b n r   1
 *        |                     |
 *        +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::construct_default()
{
   // SETUP
   // EXERCISE
   Board board;

   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(ROOK == (board.board[0][0])->getType());
   assertUnit(KNIGHT == (board.board[1][0])->getType());
   assertUnit(BISHOP == (board.board[2][0])->getType());
   assertUnit(QUEEN == (board.board[3][0])->getType());
   assertUnit(KING == (board.board[4][0])->getType());
   assertUnit(BISHOP == (board.board[5][0])->getType());
   assertUnit(KNIGHT == (board.board[6][0])->getType());
   assertUnit(ROOK == (board.board[7][0])->getType());
   assertUnit(PAWN == (board.board[0][1])->getType());
   assertUnit(PAWN == (board.board[1][1])->getType());
   assertUnit(PAWN == (board.board[2][1])->getType());
   assertUnit(PAWN == (board.board[3][1])->getType());
   assertUnit(PAWN == (board.board[4][1])->getType());
   assertUnit(PAWN == (board.board[5][1])->getType());
   assertUnit(PAWN == (board.board[6][1])->getType());
   assertUnit(PAWN == (board.board[7][1])->getType());
   assertUnit(SPACE == (board.board[0][2])->getType());
   assertUnit(SPACE == (board.board[1][2])->getType());
   assertUnit(SPACE == (board.board[2][2])->getType());
   assertUnit(SPACE == (board.board[3][2])->getType());
   assertUnit(SPACE == (board.board[4][2])->getType());
   assertUnit(SPACE == (board.board[5][2])->getType());
   assertUnit(SPACE == (board.board[6][2])->getType());
   assertUnit(SPACE == (board.board[7][2])->getType());
   assertUnit(SPACE == (board.board[0][3])->getType());
   assertUnit(SPACE == (board.board[1][3])->getType());
   assertUnit(SPACE == (board.board[2][3])->getType());
   assertUnit(SPACE == (board.board[3][3])->getType());
   assertUnit(SPACE == (board.board[4][3])->getType());
   assertUnit(SPACE == (board.board[5][3])->getType());
   assertUnit(SPACE == (board.board[6][3])->getType());
   assertUnit(SPACE == (board.board[7][3])->getType());
   assertUnit(SPACE == (board.board[0][4])->getType());
   assertUnit(SPACE == (board.board[1][4])->getType());
   assertUnit(SPACE == (board.board[2][4])->getType());
   assertUnit(SPACE == (board.board[3][4])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(SPACE == (board.board[5][4])->getType());
   assertUnit(SPACE == (board.board[6][4])->getType());
   assertUnit(SPACE == (board.board[7][4])->getType());
   assertUnit(SPACE == (board.board[0][5])->getType());
   assertUnit(SPACE == (board.board[1][5])->getType());
   assertUnit(SPACE == (board.board[2][5])->getType());
   assertUnit(SPACE == (board.board[3][5])->getType());
   assertUnit(SPACE == (board.board[4][5])->getType());
   assertUnit(SPACE == (board.board[5][5])->getType());
   assertUnit(SPACE == (board.board[6][5])->getType());
   assertUnit(SPACE == (board.board[7][5])->getType());
   assertUnit(PAWN == (board.board[0][6])->getType());
   assertUnit(PAWN == (board.board[1][6])->getType());
   assertUnit(PAWN == (board.board[2][6])->getType());
   assertUnit(PAWN == (board.board[3][6])->getType());
   assertUnit(PAWN == (board.board[4][6])->getType());
   assertUnit(PAWN == (board.board[5][6])->getType());
   assertUnit(PAWN == (board.board[6][6])->getType());
   assertUnit(PAWN == (board.board[7][6])->getType());
   assertUnit(ROOK == (board.board[0][7])->getType());
   assertUnit(KNIGHT == (board.board[1][7])->getType());
   assertUnit(BISHOP == (board.board[2][7])->getType());
   assertUnit(QUEEN == (board.board[3][7])->getType());
   assertUnit(KING == (board.board[4][7])->getType());
   assertUnit(BISHOP == (board.board[5][7])->getType());
   assertUnit(KNIGHT == (board.board[6][7])->getType());
   assertUnit(ROOK == (board.board[7][7])->getType());
   
   // TEARDOWN
   board.board[0][0] = nullptr;
   board.board[1][0] = nullptr;
   board.board[2][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[4][0] = nullptr;
   board.board[5][0] = nullptr;
   board.board[6][0] = nullptr;
   board.board[7][0] = nullptr;
   board.board[0][1] = nullptr;
   board.board[1][1] = nullptr;
   board.board[2][1] = nullptr;
   board.board[3][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[5][1] = nullptr;
   board.board[6][1] = nullptr;
   board.board[7][1] = nullptr;
   board.board[0][6] = nullptr;
   board.board[1][6] = nullptr;
   board.board[2][6] = nullptr;
   board.board[3][6] = nullptr;
   board.board[4][6] = nullptr;
   board.board[5][6] = nullptr;
   board.board[6][6] = nullptr;
   board.board[7][6] = nullptr;
   board.board[0][7] = nullptr;
   board.board[1][7] = nullptr;
   board.board[2][7] = nullptr;
   board.board[3][7] = nullptr;
   board.board[4][7] = nullptr;
   board.board[5][7] = nullptr;
   board.board[6][7] = nullptr;
   board.board[7][7] = nullptr;
}
