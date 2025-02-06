/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
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
 * 3     p p p           3
 * 2     p(q)p           2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_blocked()
{
    //setup
     Queen q(7, 7, true);
     
     q.fWhite = false;
     q.position.colRow = 0x21;
     
     BoardEmpty board;
     board.board[2][1] = &q;
     Black black1(PAWN);
     Black black2(PAWN);
     Black black3(PAWN);
     Black black4(PAWN);
    Black black5(PAWN);
    Black black6(PAWN);
    Black black7(PAWN);
    Black black8(PAWN);
     
     board.board[1][0] = &black1;
     board.board[2][0] = &black2;
     board.board[3][0] = &black3;
     board.board[1][1] = &black4;
    board.board[3][1] = &black5;
    board.board[1][2] = &black6;
    board.board[2][2] = &black7;
    board.board[3][2] = &black8;
    
     set <Move> moves;
     //exercise
     q.getMoves(moves, board);
    
     //verify
     assertEquals(moves.size(), 0);
     
     //teardown
    board.board[1][0] = nullptr;
    board.board[2][0] = nullptr;
    board.board[3][0] = nullptr;
    board.board[1][1] = nullptr;
    board.board[3][1] = nullptr;
    board.board[1][2] = nullptr;
    board.board[2][2] = nullptr;
    board.board[3][2] = nullptr;
    board.board[2][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
    //setup
    Queen q(7, 7, true);
     
    q.fWhite = false;
    q.position.colRow = 0x21;
     
    BoardEmpty board;
    board.board[2][1] = &q;
    
    set <Move> moves;
    //exercise
    q.getMoves(moves, board);
   
    // verify
    assertUnit(moves.size() == 23);  // many possible moves
    assertUnit(moves.find(Move("c2b1")) != moves.end());
    assertUnit(moves.find(Move("c2c1")) != moves.end());
    assertUnit(moves.find(Move("c2d1")) != moves.end());
    assertUnit(moves.find(Move("c2a2")) != moves.end());
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2h2")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2a4")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2h7")) != moves.end());
    assertUnit(moves.find(Move("c2c8")) != moves.end());
    
    //teardown
    board.board[2][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
    //setup
    Queen q(7, 7, true);
     
    q.fWhite = false;
    q.position.colRow = 0x21;
     
    BoardEmpty board;
    board.board[2][1] = &q;
    Black black1(PAWN);
    Black black2(PAWN);
    Black black3(PAWN);
    Black black4(PAWN);
    Black black5(PAWN);
    Black black6(PAWN);
    Black black7(PAWN);
    Black black8(PAWN);
     
    board.board[1][0] = &black1;
    board.board[2][0] = &black2;
    board.board[3][0] = &black3;
    board.board[0][1] = &black4;
    board.board[7][1] = &black5;
    board.board[7][6] = &black6;
    board.board[2][7] = &black7;
    board.board[0][3] = &black8;
    
    set <Move> moves;
     //exercise
    q.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 15);  // many possible moves
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    
    //teardown
    board.board[2][1] = nullptr;
    board.board[1][0] = nullptr;
    board.board[2][0] = nullptr;
    board.board[3][0] = nullptr;
    board.board[0][1] = nullptr;
    board.board[7][1] = nullptr;
    board.board[7][6] = nullptr;
    board.board[2][7] = nullptr;
    board.board[0][3] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
    //setup
    Queen q(7, 7, true);
     
    q.fWhite = true;
    q.position.colRow = 0x21;
     
    BoardEmpty board;
    board.board[2][1] = &q;
    Black black1(PAWN);
    Black black2(PAWN);
    Black black3(PAWN);
    Black black4(PAWN);
    Black black5(PAWN);
    Black black6(PAWN);
    Black black7(PAWN);
    Black black8(PAWN);
     
    board.board[1][0] = &black1;
    board.board[2][0] = &black2;
    board.board[3][0] = &black3;
    board.board[0][1] = &black4;
    board.board[7][1] = &black5;
    board.board[7][6] = &black6;
    board.board[2][7] = &black7;
    board.board[0][3] = &black8;
    
    set <Move> moves;
     //exercise
    q.getMoves(moves, board);
    
    // verify
    assertUnit(moves.size() == 23);  // many possible moves
    assertUnit(moves.find(Move("c2b1p")) != moves.end());
    assertUnit(moves.find(Move("c2c1p")) != moves.end());
    assertUnit(moves.find(Move("c2d1p")) != moves.end());
    assertUnit(moves.find(Move("c2a2p")) != moves.end());
    assertUnit(moves.find(Move("c2b2")) != moves.end());
    assertUnit(moves.find(Move("c2d2")) != moves.end());
    assertUnit(moves.find(Move("c2e2")) != moves.end());
    assertUnit(moves.find(Move("c2f2")) != moves.end());
    assertUnit(moves.find(Move("c2g2")) != moves.end());
    assertUnit(moves.find(Move("c2h2p")) != moves.end());
    assertUnit(moves.find(Move("c2b3")) != moves.end());
    assertUnit(moves.find(Move("c2c3")) != moves.end());
    assertUnit(moves.find(Move("c2d3")) != moves.end());
    assertUnit(moves.find(Move("c2a4p")) != moves.end());
    assertUnit(moves.find(Move("c2c4")) != moves.end());
    assertUnit(moves.find(Move("c2e4")) != moves.end());
    assertUnit(moves.find(Move("c2c5")) != moves.end());
    assertUnit(moves.find(Move("c2f5")) != moves.end());
    assertUnit(moves.find(Move("c2c6")) != moves.end());
    assertUnit(moves.find(Move("c2g6")) != moves.end());
    assertUnit(moves.find(Move("c2c7")) != moves.end());
    assertUnit(moves.find(Move("c2h7p")) != moves.end());
    assertUnit(moves.find(Move("c2c8p")) != moves.end());
    
    //teardown
    board.board[2][1] = nullptr;
    board.board[1][0] = nullptr;
    board.board[2][0] = nullptr;
    board.board[3][0] = nullptr;
    board.board[0][1] = nullptr;
    board.board[7][1] = nullptr;
    board.board[7][6] = nullptr;
    board.board[2][7] = nullptr;
    board.board[0][3] = nullptr;
}


/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
    // SETUP
    const Queen queen(7, 7, false /*white*/);
    PieceType pt = SPACE;

    // EXERCISE
    pt = queen.getType();

    // VERIFY
    assertUnit(pt == QUEEN);
}
