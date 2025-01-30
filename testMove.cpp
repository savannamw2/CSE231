/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>
/*************************************
 * Constructor : default
 * Input:
 * Output: source=INVALID
 *         dest  =INVALID
 **************************************/
void TestMove::constructor_default()
{
 //Setup
   Move m;
   Position p;
   
   // Exercise
   Position s = m.source;
   Position d = m.dest;
   double source = s.colRow;
   double dest = d.colRow;
   // verify
   assertEquals(source, 0x99);
   assertEquals(dest, 0x99);

}

   /*************************************
    * CONSTRUCTOR : standard string move
    * Input:  e5e6
    * Output: source=4,4
    *         dest  =4,5
    *         type  =MOVE
    **************************************/
  void TestMove::constructString_simple()
  {
      //setup

      
      //Exersise
      Move move("e5e6");
      //verify
      assertUnit(0x44 == move.source.getLocation());  // Source should be e5 (4,4)
      assertUnit(0x45 == move.dest.getLocation());    // Destination should be e6 (4,5)
      assertUnit(SPACE == move.promote);              // No promotion expected
      assertUnit(SPACE == move.capture);              // No capture expected
      assertUnit(Move::MOVE == move.moveType);        // Should be a normal move
      assertUnit(true == move.isWhite);
  }

   /*************************************
    * READ simple move
    * Input:  e5e6
    * Output: source=4,4
    *         dest  =4,5
    *         type  =MOVE
    **************************************/
  void TestMove::read_simple()
  {
      // Setup: Expected values
      Move move;
      move.source.colRow = 0xff;
      move.dest.colRow = 0xff;
      move.promote = KNIGHT;
      move.capture = BISHOP;
      move.isWhite = false;
      move.text = "Error";
      
      //exercise
      move.read(string("e5e6"));
      
      //verify
      assertUnit(0x44 == move.source.colRow);
      assertUnit(0x45 == move.dest.colRow);
      assertUnit(SPACE == move.promote);
      assertUnit(SPACE == move.capture);
      assertUnit(Move::MOVE == move.moveType);
      assertUnit(true == move.isWhite);
      
  }

   /*************************************
    * READ capture move
    * Input:  e5d6r
    * Output: source=4,4
    *         dest  =3,5
    *         type  =MOVE
    *         capture=ROOK
    **************************************/
  void TestMove::read_capture()
  {
      // Setup: Expected values
      Move move;
      move.source.colRow = 0xff;
      move.dest.colRow = 0xff;
      move.promote = KNIGHT;
      move.capture = BISHOP;
      move.isWhite = false;
      move.text = "Error";
      
      //exercise
      move.read(string("e5e6r"));
      
      //verify
      assertUnit(0x44 == move.source.colRow);
      assertUnit(0x45 == move.dest.colRow);
      assertUnit(SPACE == move.promote);
      assertUnit(ROOK == move.capture);
      assertUnit(Move::MOVE == move.moveType);
      assertUnit(true == move.isWhite);
  }

   /*************************************
    * READ enpassant move
    * Input:  e5f6E
    * Output: source=4,4
    *         dest  =5,5
    *         type  =ENPASSANT
    **************************************/
  void TestMove::read_enpassant()
  {
      // Setup: Expected values
      Move move;
      move.source.colRow = 0xff;
      move.dest.colRow = 0xff;
      move.promote = KNIGHT;
      move.capture = BISHOP;
      move.isWhite = false;
      move.text = "Error";
      
      //exercise
      move.read(string("e5e6E"));
      
      //verify
      assertUnit(0x44 == move.source.colRow);
      assertUnit(0x45 == move.dest.colRow);
      assertUnit(SPACE == move.promote);
      assertUnit(SPACE == move.capture);
      assertUnit(Move::ENPASSANT == move.moveType);
      assertUnit(true == move.isWhite);
  }

   /*************************************
    * READ king side castle
    * Input:  e1g1c
    * Output: source=4,0
    *         dest  =6,0
    *         type  =CASTLE_KING
    **************************************/
  void TestMove::read_castleKing()
  {
      // Setup: Expected values
      Move move;
      move.source.colRow = 0xff;
      move.dest.colRow = 0xff;
      move.promote = KNIGHT;
      move.capture = BISHOP;
      move.isWhite = false;
      move.text = "Error";
      
      //exercise
      move.read(string("e5e6c"));
      
      //verify
      assertUnit(0x44 == move.source.colRow);
      assertUnit(0x45 == move.dest.colRow);
      assertUnit(SPACE == move.promote);
      assertUnit(SPACE == move.capture);
      assertUnit(Move::ENPASSANT == move.moveType);
      assertUnit(true == move.isWhite);
  }

   /*************************************
    * READ queen side castle
    * Input:  e1c1C
    * Output: source=4,0
    *         dest  =2,0
    *         type  =CASTLE_QUEEN
    **************************************/
  void TestMove::read_castleQueen()
  {
      // Setup: Expected values
      Move move;
      move.source.colRow = 0xff;
      move.dest.colRow = 0xff;
      move.promote = KNIGHT;
      move.capture = BISHOP;
      move.isWhite = false;
      move.text = "Error";
      
      //exercise
      move.read(string("e5c1C"));
      
      //verify
      assertUnit(0x40 == move.source.colRow);
      assertUnit(0x20 == move.dest.colRow);
      assertUnit(SPACE == move.promote);
      assertUnit(SPACE == move.capture);
      assertUnit(Move::CASTLE_QUEEN == move.moveType);
      assertUnit(true == move.isWhite);
  }

/*************************************
 * ASSIGN simple move
 * Input:  e5e6
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_simple()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN enpassant move
 * Input:  e5d6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN queen side castle
 * Input:  e1g1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Input:  e5e6
 **************************************/
void TestMove::getText_simple()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Input:  e5e6r
 **************************************/
void TestMove::getText_capture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =4,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Input:  e5f6E
 **************************************/
void TestMove::getText_enpassant()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Input:  e1g1c
 **************************************/
void TestMove::getText_castleKing()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Input:  e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 **************************************/
void TestMove::letterFromPieceType_space()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Input:  KNIGHT
 **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Input:  ROOK
 **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Input:  QUEEN
 **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Input:  KING
 **************************************/
void TestMove::pieceTypeFromLetter_king()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}
