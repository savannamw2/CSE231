/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p p p         6
 * 5       p(k)p         5
 * 4       p p p         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blocked()
{
    //setup
    King k(7, 7, true);
     
    k.fWhite = false;
     k.position.colRow = 0x24;
     
    BoardEmpty board;
    board.board[3][4] = &k;
   
    Black black1(PAWN);
    Black black2(PAWN);
    Black black3(PAWN);
    Black black4(PAWN);
    Black black5(PAWN);
    Black black6(PAWN);
    Black black7(PAWN);
    Black black8(PAWN);
     
    board.board[2][3] = &black1;
    board.board[3][3] = &black2;
    board.board[4][3] = &black3;
    board.board[2][4] = &black4;
    board.board[2][3] = &black5;
    board.board[3][3] = &black6;
    board.board[4][3] = &black7;
    board.board[2][4] = &black8;
     
     set <Move> moves;
     //exercise
     k.getMoves(moves, board);
     //verify
     assertEquals(moves.size(), 0);
     
    // TEARDOWN
    board.board[3][4] = nullptr; // king
    board.board[2][3] = nullptr; // black1
    board.board[3][3] = nullptr; // black2
    board.board[4][3] = nullptr; // black3
    board.board[2][4] = nullptr; // black4
    board.board[4][4] = nullptr; // black5
    board.board[2][5] = nullptr; // black6
    board.board[3][5] = nullptr; // black7
    board.board[4][5] = nullptr; // black8
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
    //setup
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x24;
     
    BoardEmpty board;
    board.board[3][4] = &k;
   
    White white1(PAWN);
    White white2(PAWN);
    White white3(PAWN);
    White white4(PAWN);
    White white5(PAWN);
    White white6(PAWN);
    White white7(PAWN);
    White white8(PAWN);
    
    board.board[2][3] = &white1;
    board.board[3][3] = &white2;
    board.board[4][3] = &white3;
    board.board[2][4] = &white4;
    board.board[2][3] = &white5;
    board.board[3][3] = &white6;
    board.board[4][3] = &white7;
    board.board[2][4] = &white8;
     
    set <Move> moves;
    
    //exercise
    k.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 8);  // no possible moves
    assertUnit(moves.find(Move("d5c4p")) != moves.end());
    assertUnit(moves.find(Move("d5d4p")) != moves.end());
    assertUnit(moves.find(Move("d5e4p")) != moves.end());
    assertUnit(moves.find(Move("d5c5p")) != moves.end());
    assertUnit(moves.find(Move("d5e5p")) != moves.end());
    assertUnit(moves.find(Move("d5c6p")) != moves.end());
    assertUnit(moves.find(Move("d5d6p")) != moves.end());
    assertUnit(moves.find(Move("d5e6p")) != moves.end());

    // TEARDOWN
    board.board[3][4] = nullptr; // king
    board.board[2][3] = nullptr; // white1
    board.board[3][3] = nullptr; // white2
    board.board[4][3] = nullptr; // white3
    board.board[2][4] = nullptr; // white4
    board.board[4][4] = nullptr; // white5
    board.board[2][5] = nullptr; // white6
    board.board[3][5] = nullptr; // white7
    board.board[4][5] = nullptr; // white8
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
    //setup
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x24;
     
    BoardEmpty board;
    board.board[3][4] = &k;
   
//    White white1(PAWN);
//    White white2(PAWN);
//    White white3(PAWN);
//    White white4(PAWN);
//    White white5(PAWN);
//    White white6(PAWN);
//    White white7(PAWN);
//    White white8(PAWN);
//    
//    board.board[2][3] = &white1;
//    board.board[3][3] = &white2;
//    board.board[4][3] = &white3;
//    board.board[2][4] = &white4;
//    board.board[2][3] = &white5;
//    board.board[3][3] = &white6;
//    board.board[4][3] = &white7;
//    board.board[2][4] = &white8;
     
    set <Move> moves;
    
    //exercise
    k.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 8);  // no possible moves
    assertUnit(moves.find(Move("d5c4")) != moves.end());
    assertUnit(moves.find(Move("d5d4")) != moves.end());
    assertUnit(moves.find(Move("d5e4")) != moves.end());
    assertUnit(moves.find(Move("d5c5")) != moves.end());
    assertUnit(moves.find(Move("d5e5")) != moves.end());
    assertUnit(moves.find(Move("d5c6")) != moves.end());
    assertUnit(moves.find(Move("d5d6")) != moves.end());
    assertUnit(moves.find(Move("d5e6")) != moves.end());

    // TEARDOWN
    board.board[3][4] = nullptr; // king
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
    //setup
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x00;
     
    BoardEmpty board;
    board.board[0][0] = &k;
   
//    White white1(PAWN);
//    White white2(PAWN);
//    White white3(PAWN);
//    White white4(PAWN);
//    White white5(PAWN);
//    White white6(PAWN);
//    White white7(PAWN);
//    White white8(PAWN);
//
//    board.board[2][3] = &white1;
//    board.board[3][3] = &white2;
//    board.board[4][3] = &white3;
//    board.board[2][4] = &white4;
//    board.board[2][3] = &white5;
//    board.board[3][3] = &white6;
//    board.board[4][3] = &white7;
//    board.board[2][4] = &white8;
     
    set <Move> moves;
    
    //exercise
    k.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 3);
    assertUnit(moves.find(Move("a1a2")) != moves.end());
    assertUnit(moves.find(Move("a1b2")) != moves.end());
    assertUnit(moves.find(Move("a1b1")) != moves.end());

    // TEARDOWN
    board.board[0][0] = nullptr; // king
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
    //setup
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x30;
     
    BoardEmpty board;
    board.board[3][0] = &k;
   
    White white1(PAWN);
    White white2(PAWN);
    White white3(PAWN);
    
    WhiteNotMoved qsRook(ROOK);
    WhiteNotMoved ksRook(ROOK);
//    White white4(PAWN);
//    White white5(PAWN);
//    White white6(PAWN);
//    White white7(PAWN);
//    White white8(PAWN);
//
    board.board[3][1] = &white1;
    board.board[4][1] = &white2;
    board.board[5][1] = &white3;
    board.board[0][0] = &qsRook;
    board.board[7][0] = &ksRook;
//    board.board[2][3] = &white5;
//    board.board[3][3] = &white6;
//    board.board[4][3] = &white7;
//    board.board[2][4] = &white8;
     
    set <Move> moves;
    
    //exercise
    k.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 4);
    assertUnit(moves.find(Move("e1c1C")) != moves.end());
    assertUnit(moves.find(Move("e1d1")) != moves.end());
    assertUnit(moves.find(Move("e1f1")) != moves.end());
    assertUnit(moves.find(Move("e1g1c")) != moves.end());

    // TEARDOWN
    board.board[4][0] = nullptr;
    board.board[3][1] = nullptr;
    board.board[4][1] = nullptr;
    board.board[5][1] = nullptr;
    board.board[0][0] = nullptr;
    board.board[7][0] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x46;
     
    BoardEmpty board;
    board.board[3][0] = &k;
   
    White white1(PAWN);
    White white2(PAWN);
    White white3(PAWN);
    
    WhiteNotMoved qsRook(ROOK);
    WhiteNotMoved ksRook(ROOK);
//    White white4(PAWN);
//    White white5(PAWN);
//    White white6(PAWN);
//    White white7(PAWN);
//    White white8(PAWN);
//
    board.board[3][6] = &white1;
    board.board[4][6] = &white2;
    board.board[5][6] = &white3;
    board.board[0][7] = &qsRook;
    board.board[7][7] = &ksRook;
//    board.board[2][3] = &white5;
//    board.board[3][3] = &white6;
//    board.board[4][3] = &white7;
//    board.board[2][4] = &white8;
     
    set <Move> moves;
    
    //exercise
    k.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 4);
    assertUnit(moves.find(Move("e8c8C")) != moves.end());
    assertUnit(moves.find(Move("e8d8")) != moves.end());
    assertUnit(moves.find(Move("e8f8")) != moves.end());
    assertUnit(moves.find(Move("e8g8c")) != moves.end());

    // TEARDOWN
    board.board[4][7] = nullptr; // king
    board.board[3][6] = nullptr; // pawn1
    board.board[4][6] = nullptr; // pawn2
    board.board[5][6] = nullptr; // pawn3
    board.board[0][7] = nullptr; // qkRook
    board.board[7][7] = nullptr; // ksRook
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x40;
    k.nMoves = 1;
     
    BoardEmpty board;
    board.board[4][0] = &k;
   
    White white1(PAWN);
    White white2(PAWN);
    White white3(PAWN);
    
    WhiteNotMoved qsRook(ROOK);
    WhiteNotMoved ksRook(ROOK);
//    White white4(PAWN);
//    White white5(PAWN);
//    White white6(PAWN);
//    White white7(PAWN);
//    White white8(PAWN);
//
    board.board[3][1] = &white1;
    board.board[4][1] = &white2;
    board.board[5][1] = &white3;
    board.board[0][0] = &qsRook;
    board.board[7][0] = &ksRook;
//    board.board[2][3] = &white5;
//    board.board[3][3] = &white6;
//    board.board[4][3] = &white7;
//    board.board[2][4] = &white8;
     
    set <Move> moves;
    
    //exercise
    k.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 2);
    assertUnit(moves.find(Move("e1d1")) != moves.end());
    assertUnit(moves.find(Move("e1f1")) != moves.end());

    // TEARDOWN
    board.board[4][0] = nullptr; // king
    board.board[3][1] = nullptr; // pawn1
    board.board[4][1] = nullptr; // pawn2
    board.board[5][1] = nullptr; // pawn3
    board.board[0][0] = nullptr; // qsrook
    board.board[7][0] = nullptr; // ksrook
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x40;
     
    BoardEmpty board;
    board.board[4][0] = &k;
   
    White white1(PAWN);
    White white2(PAWN);
    White white3(PAWN);
    
    WhiteNotMoved qsRook(ROOK);
    WhiteNotMoved ksRook(ROOK);
//    White white4(PAWN);
//    White white5(PAWN);
//    White white6(PAWN);
//    White white7(PAWN);
//    White white8(PAWN);
//
    board.board[3][1] = &white1;
    board.board[4][1] = &white2;
    board.board[5][1] = &white3;
    board.board[0][0] = &qsRook;
    board.board[7][0] = &ksRook;
//    board.board[2][3] = &white5;
//    board.board[3][3] = &white6;
//    board.board[4][3] = &white7;
//    board.board[2][4] = &white8;
     
    set <Move> moves;
    
    //exercise
    k.getMoves(moves, board);
    
    // VERIFY
    assertUnit(moves.size() == 2);
    assertUnit(moves.find(Move("e1d1")) != moves.end());
    assertUnit(moves.find(Move("e1f1")) != moves.end());

    // TEARDOWN
    board.board[4][0] = nullptr; // king
    board.board[3][1] = nullptr; // pawn1
    board.board[4][1] = nullptr; // pawn2
    board.board[5][1] = nullptr; // pawn3
    board.board[0][0] = nullptr; // qsrook
    board.board[7][0] = nullptr; // ksrook
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
    King k(7, 7, true);
     
    k.fWhite = false;
    k.position.colRow = 0x00;
     
    PieceType pt;
    
    pt = k.getType();
    
    assertUnit(pt == PieceType::KING);
}


