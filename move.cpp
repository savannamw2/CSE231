/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()   : source(Position()), dest(Position()), promote(SPACE), capture(SPACE), moveType(MOVE_ERROR), isWhite(true), text("")
{
}


Move::Move(const char* s) : source(Position()), dest(Position()), promote(SPACE), capture(SPACE), moveType(MOVE), isWhite(true), text("") {
    // If the move is a castling move (ends with 'C')
    if (s[4] == 'C') {
        // Parse the source and destination positions
        source = Position(s[0] - 'a', 8 - (s[1] - '0'));  // Starting position (e1)
        dest = Position(s[2] - 'a', 8 - (s[3] - '0'));    // Ending position (c1)

        
    } else {
        // Handle regular moves here (not castling)
        source = Position(s[0] - 'a', 8 - (s[1] - '0'));
        dest = Position(s[2] - 'a', 8 - (s[3] - '0'));
        moveType = MOVE;  // Regular move
    }
}
