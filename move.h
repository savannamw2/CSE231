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
#include <iostream>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type
#include <set>


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
    Move(const Move & rhs) : promote(SPACE), capture(SPACE), isWhite(true), moveType(MOVE)
    {
        *this = rhs;
    }

    Move(const char* s, bool isW = true)  : promote(SPACE), capture(SPACE), isWhite(isW), moveType(MOVE)
    {
        *this = s;
    }
    
    Move(const Position& source, const Position& dest, const std::set<Move> & possible);
    Move(const Position& source, const Position& dest, PieceType promote, PieceType capture, MoveType moveType, bool isWhite);

    
    string getText() const {return text;}
    
    Position getSrc()const          {return source;}
    Position getDes()const          {return dest;}
    
    PieceType getPromoted() const   {return promote;}
    PieceType getCapture()const     {return capture;}
    
    bool getEnPassant()const        {return moveType== ENPASSANT;}
    bool getCastleK()const          {return moveType == CASTLE_KING;}
    bool getCastleQ()const          {return moveType == CASTLE_QUEEN;}
    bool getWhiteMove()const        {return isWhite;}
    Move :: MoveType getMoveType() const {return moveType; }
    
    bool operator == (const Move & rhs ) const
    {
        return source == rhs.source && dest == rhs.dest &&
                promote == rhs.promote && capture == rhs.capture &&
                moveType == rhs.moveType && isWhite == rhs.isWhite &&
                text == rhs.text;
    };
    bool operator == (const string & rhs ) const {return getText() == rhs;}
    bool operator != (const string & rhs ) const {return getText() != rhs;}
    bool operator != (const Move & rhs ) const {return !(*this == rhs);}
    bool operator < (const Move & rhs ) const {
        std::cout << "Comparing " << dest.getLocation() << " < " << rhs.dest.getLocation() << std::endl;
        return dest.getLocation() < rhs.dest.getLocation();
    };

    void update() {text = getText();}
    void setCapture(PieceType pt) {capture = pt; update();}
    void setWhiteMove(bool f) {isWhite = f; update(); }
    void setSRC(const Position & src) {source = src; update(); }
    void setDes(const Position & des) {dest = des; update(); }
    void setEnpassant(){moveType = ENPASSANT; update(); }
    void setPromote(PieceType pt) {promote = pt; update(); }
    void setCastle(bool isKing){ moveType = (isKing ? CASTLE_KING : CASTLE_QUEEN); update();}
    
    friend ostream & operator << (ostream & out , Move & rhs);
    friend ostream& operator <<(ostream& out, Move& move);
    friend iostream& operator >>(iostream & in, Move& move);
    
    const Move operator = (const Move& rhs)
    {
        if (this != &rhs) // Check for self-assignment
            {
                source = rhs.source;
                dest = rhs.dest;
                promote = rhs.promote;
                capture = rhs.capture;
                moveType = rhs.moveType;
                isWhite = rhs.isWhite;
                text = rhs.text;
            }
            return *this;
    };
    
    const Move operator = (const string & s)
    {
        read(s);
        return *this;
    }
    
    const Move operator =(const char * s)
    {
        read(string(s));
        return *this;
    }
    

    // Operator <= to compare moves
    bool operator <= (const Move& move)
    {
        if (source.getLocation() < move.source.getLocation()) {
            return true;
        }
        if (source.getLocation() > move.source.getLocation()) {
            return false;
        }

        // If sources are the same, compare destinations
        return dest.getLocation() <= move.dest.getLocation();
    }
    
    

    char letterFromPieceType(PieceType piece) const
    {
        switch (piece)
        {
            case KING:   return 'K';
            case QUEEN:  return 'Q';
            case ROOK:   return 'R';
            case BISHOP: return 'B';
            case KNIGHT: return 'N';
            case PAWN:   return 'P';
            case SPACE:  return ' ';  // This handles the SPACE case
            default:     return '?';  // For invalid types
        }
    }
    
    PieceType pieceTypeFromLetter(char letter) const
    {
        switch (tolower(letter)) // Convert to lowercase for uniformity
        {
            case 'k': return KING;
            case 'q': return QUEEN;
            case 'r': return ROOK;
            case 'b': return BISHOP;
            case 'n': return KNIGHT;
            case 'p': return PAWN;
            case ' ': return SPACE;  // Handles space character
            default:  return INVALID; // Invalid input case
        }
    }
    
private:
    void read(const std::string & s);

    Position  source;    // where the move originated from
    Position  dest;      // where the move finished
    PieceType promote;   // piece to be promoted to
    PieceType capture;   // did a capture happen this move?
    MoveType  moveType;  // what type of move is this?
    bool      isWhite;   // whose turn is it anyway?
    string    text;      // what is the textual version of the move?
};
