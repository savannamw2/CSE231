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
    Position s("e5");
    Position d("e6");
    double srowcol = s.colRow;
    double drowcol = d.colRow;
    Move::MoveType tmovetype = Move::MOVE;
    
    //Exersise
    Move move("e5e6");
    Position msource = move.source;
    Position mdest = move.dest;
    double msrowcol = msource.colRow;
    double mdrowcol = mdest.colRow;
    Move::MoveType mMoveType = move.moveType;
    
    //verify
    assertEquals(msrowcol, srowcol);
    assertEquals(mdrowcol, drowcol);
    assertEquals(mMoveType, tmovetype);

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
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::MOVE;

    // Exercise: Create Move object from "e5e6" (e.g., a simple move from e5 to e6)
    Move move("e5e6");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
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
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::MOVE;
    PieceType expectedPieceCapture = ROOK;

    // Exercise: Create Move object from "e5e6" (e.g., a simple move from e5 to e6)
    Move move("e5e6r");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
    assertEquals(move.capture, expectedPieceCapture);
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
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::ENPASSANT;
    

    // Exercise: Create Move object from "e5e6" (e.g., a simple move from e5 to e6)
    Move move("e5e6E");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
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
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::CASTLE_KING;
    

    // Exercise: Create Move object from "e5e6" (e.g., a simple move from e5 to e6)
    Move move("e5e6c");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
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
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::CASTLE_QUEEN;
    

    // Exercise: Create Move object from "e5e6" (e.g., a simple move from e5 to e6)
    Move move("e5e6C");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
}

 /*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::assign_simple()
{
    // Setup: Expected values
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::MOVE;  // Expecting a simple move

    // Exercise: Create Move object using the "e5e6" notation
    Move move;
    move.assignString("e5e6");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
}

 /*************************************
  * ASSIGN capture move
  * Input:  e5d6r
  * Output: source=4,4
  *         dest  =3,5
  *         type  =MOVE
  *         capture=ROOK
  **************************************/
void TestMove::assign_capture()
{
    // Setup: Expected values
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::MOVE;  // Expecting a simple move
    PieceType expectedCature = ROOK;
    
    // Exercise: Create Move object using the "e5e6" notation
    Move move;
    move.assignString("e5e6r");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
    assertEquals(move.capture, expectedCature);
}

 /*************************************
  * ASSIGN enpassant move
  * Input:  e5f6E
  * Output: source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  **************************************/
void TestMove::assign_enpassant()
{
    // Setup: Expected values
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::ENPASSANT;  // Expecting a simple move

    // Exercise: Create Move object using the "e5e6" notation
    Move move;
    move.assignString("e5e6E");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
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
    // Setup: Expected values
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move:: CASTLE_KING;  // Expecting a simple move

    // Exercise: Create Move object using the "e5e6" notation
    Move move;
    move.assignString("e5e6C");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
}

 /*************************************
  * ASSIGN queen side castle
  * Input:  e1c1C
  * Output: source=4,0
  *         dest  =2,0
  *         type  =CASTLE_QUEEN
  **************************************/
void TestMove::assign_castleQueen()
{
    // Setup: Expected values
    Position expectedSource("e5");  // e5 corresponds to position (4,4)
    Position expectedDest("e6");    // e6 corresponds to position (4,5)
    Move::MoveType expectedMoveType = Move::CASTLE_QUEEN;  // Expecting a simple move

    // Exercise: Create Move object using the "e5e6" notation
    Move move;
    move.assignString("e5e6C");

    // Verify: Ensure the source, destination, and move type are correct
    assertEquals(move.source.getLocation(), expectedSource.getLocation());
    assertEquals(move.dest.getLocation(), expectedDest.getLocation());
    assertEquals(move.moveType, expectedMoveType);
}

 /*************************************
  * GET TEXT simple move
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  * Output:  e5e6
  **************************************/
void TestMove::getText_simple()
{
    // Setup: Create a Move object with source (4,4) and destination (4,5)
     Position source("e5");  // source position (4,4)
     Position dest("e6");    // destination position (4,5)
     Move::MoveType moveType = Move::MOVE;

     Move move;
     move.source = source;
     move.dest = dest;
     move.moveType = moveType;

     // Exercise: Retrieve the text representation of the move
     string moveText = move.getText();

     // Verify: Ensure the text is "e5e6"
     //assertEquals(moveText, "e5e6");
    assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT capture
  * Input : source=4,4
  *         dest  =4,5
  *         type  =MOVE
  *         capture=ROOK
  * Output:  e5e6r
  **************************************/
void TestMove::getText_capture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

 /*************************************
  * GET TEXT en passant
  * Input : source=4,4
  *         dest  =5,5
  *         type  =ENPASSANT
  *         capture=PAWN
  * Output:  e5f6E
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
  * Output:  e1g1c
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
  * Output:  e1c1C
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
    // Setup
    Move move;
    move.promote = SPACE;  // Set promote to SPACE
    
    // Exercise
    char value1 = 'h';  // Initialize with some value
    value1 = move.letterFromPieceType(move.promote);  // Call function with SPACE
    
    char test = ' ';  // The expected result is a space character
    
    // Verify
    assertEquals(value1, test);  // Assert that the result is a space
}

 /*************************************
  * LETTER FROM PIECE TYPE pawn
  * Input : PAWN
  * Output:  'p'
  **************************************/
void TestMove::letterFromPieceType_pawn()
{
    // Setup
    Move move;
    move.promote = PAWN;
    
    // Exercise
    char value1 = 'h';
    value1 = move.letterFromPieceType(move.promote);
    
    char test = 'p';
    
    // Verify
    assertEquals(value1, test);
}

 /*************************************
  * LETTER FROM PIECE TYPE bishop
  * Input : BISHOP
  * Output:  'b'
  **************************************/
void TestMove::letterFromPieceType_bishop()
{
    // Setup
    Move move;
    move.promote = BISHOP;
    
    // Exercise
    char value1 = 'h';
    value1 = move.letterFromPieceType(move.promote);
    
    char test = 'b';
    
    // Verify
    assertEquals(value1, test);
}

 /*************************************
  * LETTER FROM PIECE TYPE knight
  * Input : KNIGHT
  * Output:  'n'
  **************************************/
void TestMove::letterFromPieceType_knight()
{
    // Setup
    Move move;
    move.promote = KNIGHT;
    
    // Exercise
    char value1 = 'h';
    value1 = move.letterFromPieceType(move.promote);
    
    char test = 'n';
    
    // Verify
    assertEquals(value1, test);
}

 /*************************************
  * LETTER FROM PIECE TYPE rook
  * Input : ROOK
  * Output:  'r'
  **************************************/
void TestMove::letterFromPieceType_rook()
{
    // Setup
    Move move;
    move.promote = ROOK;
    
    // Exercise
    char value1 = 'h';
    value1 = move.letterFromPieceType(move.promote);
    
    char test = 'r';
    
    // Verify
    assertEquals(value1, test);
}

 /*************************************
  * LETTER FROM PIECE TYPE queen
  * Input : QUEEN
  * Output:  'q'
  **************************************/
void TestMove::letterFromPieceType_queen()
{
    // Setup
    Move move;
    move.promote = QUEEN;
    
    // Exercise
    char value1 = 'h';
    value1 = move.letterFromPieceType(move.promote);
    
    char test = 'q';
    
    // Verify
    assertEquals(value1, test);
}

 /*************************************
  * LETTER FROM PIECE TYPE king
  * Input : KING
  * Output:  'k'
  **************************************/
void TestMove::letterFromPieceType_king()
{
    // Setup
    Move move;
    move.promote = KING;
    
    // Exercise
    char value1 = 'h';
    value1 = move.letterFromPieceType(move.promote);
    
    char test = 'k';
    
    // Verify
    assertEquals(value1, test);
}

 /*************************************
  * PIECE TYPE FROM LETTER pawn
  * Input : 'p'
  * Output:  PAWN
  **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
    // Setup
    Move move;
    PieceType piece = SPACE;
    
    // Exercise
    piece = move.pieceTypeFromLetter('p');
    
    
    PieceType test = PAWN;
    
    // Verify
    assertEquals(piece, test);
}

 /*************************************
  * PIECE TYPE FROM LETTER bishop
  * Input : 'b'
  * Output:  BISHOP
  **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
    // Setup
    Move move;
    PieceType piece = SPACE;
    
    // Exercise
    piece = move.pieceTypeFromLetter('b');
    
    
    PieceType test = BISHOP;
    
    // Verify
    assertEquals(piece, test);
}

 /*************************************
  * PIECE TYPE FROM LETTER knight
  * Input : 'n'
  * Output:  KNIGHT
  **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
    // Setup
    Move move;
    PieceType piece = SPACE;
    
    // Exercise
    piece = move.pieceTypeFromLetter('n');
    
    
    PieceType test = KNIGHT;
    
    // Verify
    assertEquals(piece, test);
}

 /*************************************
  * PIECE TYPE FROM LETTER rook
  * Input : 'r'
  * Output:  ROOK
  **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
    // Setup
    Move move;
    PieceType piece = SPACE;
    
    // Exercise
    piece = move.pieceTypeFromLetter('r');
    
    
    PieceType test = ROOK;
    
    // Verify
    assertEquals(piece, test);
}

 /*************************************
  * PIECE TYPE FROM LETTER queen
  * Input : 'q'
  * Output:  QUEEN
  **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
    // Setup
    Move move;
    PieceType piece = SPACE;
    
    // Exercise
    piece = move.pieceTypeFromLetter('q');
    
    
    PieceType test = QUEEN;
    
    // Verify
    assertEquals(piece, test);
}

 /*************************************
  * PIECE TYPE FROM LETTER king
  * Input : 'k'
  * Output:  KING
  **************************************/
void TestMove::pieceTypeFromLetter_king() 
{
    // Setup
    Move move;
    PieceType piece = SPACE;
    
    // Exercise
    piece = move.pieceTypeFromLetter('k');
    
    
    PieceType test = KING;
    
    // Verify
    assertEquals(piece, test);
}


/*************************************
 * EQUAL - NOT
 * Input : b2b4 == b2b5
 * Output: false
 **************************************/
void TestMove::equal_not()
{
   Move move1("b2b4");
   Move move2("b2b5");

   bool result = (move1 == move2);

   assertEquals(result, false);
}

/*************************************
 * EQUAL - EQUALS
 * Input : b2b4 == b2b4
 * Output: true
 **************************************/
void TestMove::equal_equals()
{
   Move move1("b2b4");
   Move move2("b2b4");

   bool result = (move1 == move2);

   assertEquals(result, true);
}

/*************************************
 * LESS THAN - LESS THAN
 * Input : b2b2 < b2b4
 * Output: false
 *    Note that the less-than operator is needed
 *    so std::set<T> can sort the elements. Thus,
 *    any T in a set must define less-than. In this
 *    case, I defined it according to the
 *     destination's Position's location.
 **************************************/
void TestMove::lessthan_lessthan()
{
   Move move1("b2b2");
   Move move2("b2b4");

   bool result = (move1 < move2);

   assertEquals(result, false);
}

/*************************************
 * LESS THAN - EQUALS
 * Input : b2b4 < b2b4
 * Output: false
 **************************************/
void TestMove::lessthan_equals()
{
   Move move1("b2b4");
   Move move2("b2b4");

   bool result = (move1 <= move2);

   assertEquals(result, false);
}

/*************************************
 * LESS THAN - GREATAER THAN
 * Input : b2b4 < b2b2
 * Output: false
 **************************************/
void TestMove::lessthan_greaterthan()
{
   Move move1("b2b4");
   Move move2("b2b2");

   bool result = (move1 < move2);

   assertEquals(result, false);
}
