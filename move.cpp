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
Move::Move()
: source(INVALID), dest(INVALID), promote(SPACE), capture(SPACE), moveType(MOVE), isWhite(true), text("") {}


void Move::read(const string & s)
{
    text = s;

    char sourceTxt[3] = {s[0], s[1], '\0'};
    source = sourceTxt;
    
    char destTxt[3] = {s[2], s[3], '\0'};
       dest = destTxt;
    
    
    capture = SPACE;
    promote = SPACE;
    moveType = MOVE;
    isWhite = true;  // Default to white's move (adjust if needed)

    for (size_t i = 4; i < s.size(); ++i)
        {
            switch (s[i])
            {
                case 'p': capture = PAWN; break;
                case 'n': capture = KNIGHT; break;
                case 'b': capture = BISHOP; break;
                case 'r': capture = ROOK; break;
                case 'q': capture = QUEEN; break;

                case 'c': moveType = CASTLE_KING; break;
                case 'C': moveType = CASTLE_QUEEN; break;
                case 'E': moveType = ENPASSANT; break;

                case 'N': promote = KNIGHT; break;
                case 'B': promote = BISHOP; break;
                case 'R': promote = ROOK; break;
                case 'Q': promote = QUEEN; break;
            }
        }

        // Ensure moveType is correctly set if a capture occurred
        if (capture != SPACE && moveType == MOVE) {
            moveType = MOVE; // Standard move with capture
        }
    
}
