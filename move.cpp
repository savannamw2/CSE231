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

Move::Move(const char * s)   : source(Position(s)), dest(Position()), promote(SPACE), capture(SPACE), moveType(MOVE), isWhite(true), text("")
{
    dest = source + ADD_C;
}
