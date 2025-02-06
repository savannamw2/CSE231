/***********************************************************************
 * Header File:
 *    TEST BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for Board
 ************************************************************************/

#pragma once

#include "unitTest.h"

class Board;

/***************************************************
 * BOARD TEST
 * Test the Board class
 ***************************************************/
class TestBoard : public UnitTest
{
public:
   void run()
   {
       // construct
//       construct_default();
//
//       // move
//       move_pawnSimple();
//       move_pawnCapture();
//       move_pawnDouble();
//       move_pawnEnpassant();
//       move_pawnPromotion();
//       move_rookSlide();
//       move_rookAttack();
//       move_bishopSlide();
//       move_bishopAttack();
//       move_knightMove();
//       move_knightAttack();
//       move_queenSlide();
//       move_queenAttack();
//       move_kingMove();
//       move_kingAttack();
//       move_kingShortCastle();
//       move_kingLongCastle();
//
//       // Get Current Move
//       getCurrentMove_initial();
//       getCurrentMove_second();
//       getCurrentMove_middleWhite();
//       getCurrentMove_middleBlack();
//
//       // Whites Turn?
//       whiteTurn_initial();
//       whiteTurn_second();
//       whiteTurn_middleWhite();
//       whiteTurn_middleBlack();
//
//       // fetch and get
//       fetch_a1();
//       fetch_h8();
//       fetch_a8();
//       set_a1();
//       set_h8();
//       set_a8();
      // move
      move_knightMove();
      move_knightAttack();
      report("Board");
   }
private:
   
   void move_knightMove();
   void move_knightAttack();
};

