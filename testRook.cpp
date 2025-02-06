/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
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
 * 3       p             3
 * 2     p(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_blocked()
{
    //setup
     Rook r(7, 7, true);
     
     r.fWhite = false;
     r.position.colRow = 0x21;
     
     BoardEmpty board;
     board.board[2][1] = &r;
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
     r.getMoves(moves, board);
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
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
    //setup
     Rook r(7, 7, true);
     
     r.fWhite = false;
     r.position.colRow = 0x21;
     
     BoardEmpty board;
     board.board[2][1] = &r;
     
     set <Move> moves;
     //exercise
     r.getMoves(moves, board);
     //verify
    // VERIFY
    assertUnit(moves.size() == 14);  // many possible moves
    assertUnit(moves.find(Move("c2c1")) != moves.end());
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2a2")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2h2")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2c8")) != moves.end());
     
     //teardown
     board.board[2][1] = nullptr;

}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p                      1
 * |                                |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
    //setup
     Rook r(7, 7, true);
     
     r.fWhite = false;
     r.position.colRow = 0x21;
     
     BoardEmpty board;
     board.board[2][1] = &r;
     Black black1(PAWN);
     Black black2(PAWN);
     Black black3(PAWN);
     Black black4(PAWN);
     
     board.board[7][1] = &black1;
     board.board[0][1] = &black2;
     board.board[2][7] = &black3;
     board.board[2][0] = &black3;
     
     set <Move> moves;
     //exercise
     r.getMoves(moves, board);
    
     //verify
    assertUnit(moves.size() == 10);  // many possible moves
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());

     //teardown
    board.board[7][1] = nullptr;
    board.board[0][1] = nullptr;
    board.board[2][7] = nullptr;
    board.board[2][0] = nullptr;
    board.board[2][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
    //setup
     Rook r(7, 7, true);
     
    r.fWhite = true;
    r.position.colRow = 0x21;
     
     BoardEmpty board;
     board.board[2][1] = &r;
     Black black1(PAWN);
     Black black2(PAWN);
     Black black3(PAWN);
     Black black4(PAWN);
     
     board.board[7][1] = &black1;
     board.board[0][1] = &black2;
     board.board[2][7] = &black3;
     board.board[2][0] = &black3;
     
     set <Move> moves;
     //exercise
     r.getMoves(moves, board);
    
    //verify
    assertUnit(moves.size() == 14);  // many possible moves
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2c8p")) != moves.end());
    assertUnit(moves.find(Move("c2h2p")) != moves.end());
    assertUnit(moves.find(Move("c2a2p")) != moves.end());
    assertUnit(moves.find(Move("c2c1p")) != moves.end());
    
    //teardown
   board.board[7][1] = nullptr;
   board.board[0][1] = nullptr;
   board.board[2][7] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][1] = nullptr;
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
    // SETUP
    const Rook rook(7, 7, false /*white*/);
    PieceType pt = SPACE;

    // EXERCISE
    pt = rook.getType();

    // VERIFY
    assertUnit(pt == ROOK);
}
