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
    board.board[3][2] = &black4;
    
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
    Bishop b(7, 7, true);
    
    b.fWhite = false;
    b.position.colRow = 0x21;
    
    BoardEmpty board;
    board.board[2][1] = &b;

//    Black black1(BISHOP);
//    Black black2(BISHOP);
//    Black black3(BISHOP);
//    Black black4(BISHOP);
    
//    board.board[0][0] = &black1;
//    board.board[3][0] = &black2;
//    board.board[0][3] = &black3;
//    board.board[7][7] = &black3;
    
    set <Move> moves;
    
    //exercise
    b.getMoves(moves, board);
    
    //verify
    assertUnit(moves.size() == 9);  // many possible moves
    assertUnit(moves.find(Move("c2b1")) != moves.end());
    assertUnit(moves.find(Move("c2d1")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2a4")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2h7")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // black
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
    board.board[0][3] = &black3;
    board.board[7][6] = &black4;
    
    set <Move> moves;
    
    //exercise
    b.getMoves(moves, board);
    
    //verify
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // black
    board.board[1][0] = nullptr; // black1
    board.board[0][3] = nullptr; // black3
    board.board[3][0] = nullptr;
    board.board[7][6] = nullptr; // black4
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
    board.board[0][3] = &black3;
    board.board[7][6] = &black4;
    
    set <Move> moves;
    
    //exercise
    b.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 9);  // many possible moves
    assertUnit(moves.find(Move("c2b1p")) != moves.end());
    assertUnit(moves.find(Move("c2d1p")) != moves.end());
    assertUnit(moves.find(Move("c2a4p")) != moves.end());
    assertUnit(moves.find(Move("c2h7p")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());

    // TEARDOWN
    board.board[2][1] = nullptr; // black
    board.board[1][0] = nullptr; // black1
    board.board[0][3] = nullptr; // black3
    board.board[3][0] = nullptr;
    board.board[7][6] = nullptr; // black4
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
    //setup
    Bishop b(7, 7, true);
    b.fWhite = true;
    b.position.set(3, 4);
    
    //exercise
    PieceType pt = b.getType();
    
    //verify
    assertUnit(pt == PieceType::BISHOP);
    assertUnit(b.fWhite == true);
    assertUnit(b.position.getCol() == 3);
    assertUnit(b.position.getRow() == 4);
    
    
}
