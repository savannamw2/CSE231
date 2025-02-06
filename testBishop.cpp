/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3     p   p           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_blocked()
{
   //setup
    Bishop b(7, 7, true);
    
    b.fWhite = false;
    b.position.colRow = 0x21;
    
    BoardEmpty board;
    board.board[2][1] = &b;
    Black black1(PAWN);
    Black black2(PAWN);
    Black black3(PAWN);
    Black black4(PAWN);
    
    board.board[1][0] = &black1;
    board.board[3][0] = &black2;
    board.board[1][2] = &black3;
    board.board[3][2] = &black3;
    
    set <Move> moves;
    //exercise
    b.getMoves(moves, board);
    //verify
    assertEquals(moves.size(), 0);
    
    //teardown
    board.board[1][0] = nullptr;
    board.board[3][0] = nullptr;
    board.board[1][2] = nullptr;
    board.board[3][2] = nullptr;
    board.board[2][1] = nullptr;
    
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}
