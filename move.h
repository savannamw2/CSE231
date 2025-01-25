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
    string getText() const{
        
        return text;
    }
    
    Position getSrc()const{
        return source;
    }
    
    Position getDes()const{
        return dest;
    }
    
    PieceType getPromoted() const{
        return promote;
    }
    
    PieceType getCapture()const{
        return capture;
    }
    
    bool getEnPassant()const{
        return enpassant;
    }
    
    bool getCastleK()const{
        return castleK;
    }
    
    bool getCastleQ()const{
        return castleQ;
    }
    
    bool getWhiteMove()const{
        return isWhite;
    }
    
    void setEnpassant(){
        enpassant = true;
        moveType = ENPASSANT;
    }
    
    void setCastle(bool isKing){
        if(isKing){
            castleK = true;
            moveType = CASTLE_KING;
        }else{
            castleQ = true;
            moveType = CASTLE_QUEEN;
        }
    }
    
    void setCastleQ(){
        castleQ = true;
        moveType = CASTLE_QUEEN;
    }
    
    void setWhiteMove(){
        isWhite = !isWhite;
    }
    
    void assign(Move move){
        source = move.source;
        dest = move.dest;
        promote = move.promote;
        capture = move.capture;
        moveType = move.moveType;
        isWhite = move.isWhite;
        text = move.text;
        enpassant = move.enpassant;
        castleK = move.castleK;
        castleQ = move.castleQ;
        error = move.error;
    }
    
    void assignString(const char* s){

        Move move(s);
        source = move.source;
        dest = move.dest;
        promote = move.promote;
        capture = move.capture;
        moveType = move.moveType;
        isWhite = move.isWhite;
        text = move.text;
    }
    

    friend std:: ostream& operator <<(std::ostream& os, const Move& move) {
        os << "Source: (" << move.getSrc() << ", " << move.getSrc() << ")"
        << ", Dest: (" << move.getDes() << ", " << move.getDes() << ")";
        return os;
    }
    
//    friend std::istream& operator>>(std::istream& is, Move& move) {
//        std::string notation;
//        is >> notation;  // Read the move notation (e.g., "e2e4")
//        move.assign(notation);  // Assign the parsed move to the Move object
//        return is;
//    }
    
    bool operator ==(const Move& move) const {
            return source == move.source && dest == move.dest;
        }
    
    bool operator < (const Move& move) {
        if (source.getLocation() < move.source.getLocation()) {
            return true;
        }
        if (source.getLocation() > move.source.getLocation()) {
            return false;
        }

        // If sources are the same, compare destinations
        return dest.getLocation() < move.dest.getLocation();
    }

    // Operator <= to compare moves
    bool operator <= (const Move& move) {
        if (source.getLocation() < move.source.getLocation()) {
            return true;
        }
        if (source.getLocation() > move.source.getLocation()) {
            return false;
        }

        // If sources are the same, compare destinations
        return dest.getLocation() <= move.dest.getLocation();
    }
    
    
    char letterFromPieceType(PieceType pt)     const {
        switch (pt) {
            case KING:    return 'k';
            case QUEEN:   return 'q';
            case ROOK:    return 'r';
            case BISHOP:  return 'b';
            case KNIGHT:  return 'n';
            case PAWN:    return 'p';
            default:      return ' ';
        }
    }
    PieceType pieceTypeFromLetter(char letter) const {
        switch (letter) {
            case 'k': return KING;
            case 'q': return QUEEN;
            case 'r': return ROOK;
            case 'b': return BISHOP;
            case 'n': return KNIGHT;
            case 'p': return PAWN;
            default:  return SPACE;
        }
    }
    
    MoveType getMoveType(char moveTypeChar) {
        switch (moveTypeChar) {
            case 'c': return CASTLE_KING;
            case 'C': return CASTLE_QUEEN;
            case 'E': return ENPASSANT;
            default: return MOVE;
        }
    }
    
private:

    Position  source;    // where the move originated from
    Position  dest;      // where the move finished
    PieceType promote;   // piece to be promoted to
    PieceType capture;   // did a capture happen this move?
    MoveType  moveType;  // what type of move is this?
    bool      isWhite;   // whose turn is it anyway?
    string    text;      // what is the textual version of the move?
    bool enpassant;
    bool castleK;
    bool castleQ;
    string error;
};



