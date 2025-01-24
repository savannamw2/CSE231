/***********************************************************************
 * Header File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
    friend class TestMove;
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // constructor
    Move();
    Move(const char * s);
    
    void setText(const string& moveText) {text = moveText;}
    MoveType getMoveType() const {return moveType;}
    Position getSource() const{return source;}
    Position getDestination() const{ return dest;}
    bool isCapture() {return capture != SPACE;}
    void setCapture(PieceType capturedPiece) {capture = capturedPiece;}
    void setMoveType(MoveType type) {moveType = type;}
    
    

private:
    char letterFromPieceType(PieceType pt)     const {
        switch (pt) {
            case KING:    return 'K';
            case QUEEN:   return 'Q';
            case ROOK:    return 'R';
            case BISHOP:  return 'B';
            case KNIGHT:  return 'N';
            case PAWN:    return 'P';
            default:      return 'z';
        }
    }
    PieceType pieceTypeFromLetter(char letter) const {
        switch (letter) {
            case 'K': return KING;
            case 'Q': return QUEEN;
            case 'R': return ROOK;
            case 'B': return BISHOP;
            case 'N': return KNIGHT;
            case 'P': return PAWN;
            default:  return SPACE;
        }
    }


   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};


