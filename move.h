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
    
    void assign(string notation){
        // Ensure the notation is valid
        if (notation.length() < 4) {
            moveType = MOVE_ERROR;
            error = "Invalid notation: " + notation;
            return;
        }

        // Parse source square (first two characters)
        source = Position(notation[0] - 'a', notation[1] - '1'); // e.g., 'e5' -> (4, 4)

        // Parse destination square (next two characters)
        dest = Position(notation[2] - 'a', notation[3] - '1'); // e.g., 'e6' -> (4, 5)

        // Check for additional characters (capture, promotion, en passant, or castling)
        if (notation.length() > 4) {
            char lastChar = notation[4];

            if (lastChar >= 'a' && lastChar <= 'z' || lastChar >= 'A' && lastChar <= 'Z') {
                // Check for castling
                if (lastChar == 'c') {
                    castleK = true;
                    moveType = CASTLE_KING;
                } else if (lastChar == 'C') {
                    castleQ = true;
                    moveType = CASTLE_QUEEN;
                }
                // Check for en passant
                else if (lastChar == 'E') {
                    enpassant = true;
                    moveType = ENPASSANT;
                }
                // Handle capture
                else {
                    capture = pieceTypeFromLetter(lastChar); // e.g., 'r' -> ROOK
                    moveType = MOVE; // Still a normal move but includes capture
                }
            }
        }

        // Store the textual representation
        text = notation;
    }
    

    friend std:: ostream& operator <<(std::ostream& os, const Move& move) {
        os << "Source: (" << move.getSrc() << ", " << move.getSrc() << ")"
        << ", Dest: (" << move.getDes() << ", " << move.getDes() << ")";
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Move& move) {
        std::string notation;
        is >> notation;  // Read the move notation (e.g., "e2e4")
        move.assign(notation);  // Assign the parsed move to the Move object
        return is;
    }
    
    bool operator == (Move move1){
        if(source != move1.source){
            return false;
        }
        
        if(dest != move1.dest){
            return false;
        }
        
        return true;
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



