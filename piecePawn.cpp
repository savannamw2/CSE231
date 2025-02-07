/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    <your name here>
 * Summary:
 *    The Pawn class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{
    pgout->drawPawn(position, fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{
    Position pos;
    int row = position.getRow();
    int col = position.getCol();
    int r, c;
    
    if(fWhite){
        c = col;
        //Move one space
       r = row + 1;
        pos.set(c, r);
        if(row < 7 && board[pos].getType() == PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        //move 2 space
        r = row +2;
        pos.set(c, r);
        if(row == 1 && board[pos].getType() == PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        //Attacking right?
        r = row;
        c = col + 1;
        pos.set(c, r);
        if (r < 7 && !board[pos].isWhite() && board[pos].getType() != PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        //attacking left
        r = row;
        c = col - 1;
        pos.set(c, r);
        if (r < 7 && !board[pos].isWhite() && board[pos].getType() != PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        //promote going straight
        r = row + 1;
        c = col;
        pos.set(c, r);
        if (r == 7 && board[pos].getType() == PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::QUEEN, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        //
        c = col - 1;
        pos.set(c, r);
        if ((c >= 0) && (r == 7) && (board[pos].isWhite() != fWhite) && (board[pos].getType() != PieceType::SPACE)) {
            moves.insert(Move(position, pos, PieceType::QUEEN, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        c = col + 1;
        pos.set(c, r);
        if ((c < 8) && (r == 7) && (board[pos].isWhite() != fWhite) && (board[pos].getType() != PieceType::SPACE)){
            moves.insert(Move(position, pos, PieceType::QUEEN, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        
        //Enpasant
        c = col - 1;
        r = row;
        pos.set(c, r);
        if(col >= 0 && row == 4 && board[pos].getType() == PieceType ::PAWN && board[pos].getLastMove() == board.getCurrentMove() - 1 && (board[pos].isWhite() != fWhite)){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType:: ENPASSANT, isWhite()));
        }
        c = col + 1;
        pos.set(c, r);
        if(col < 8 && row == 4 && board[pos].getType() == PieceType ::PAWN && board[pos].getLastMove() == board.getCurrentMove() - 1 && (board[pos].isWhite() != fWhite)){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType:: ENPASSANT, isWhite()));
        }
    }
    
    if(!fWhite){
        c = col;
        
        //Move one space
        r = row - 1;
        pos.set(c, r);
        if(row < 7 && board[pos].getType() == PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        //move 2 space
        r = row - 2;
        pos.set(c, r);
        if(row == 6 && board[pos].getType() == PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        //Attacking right?
        c = col + 1;
        pos.set(c, r);
        if(r < 7 && !board[pos].isWhite() && board[pos].getType() != PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        //attacking left
        c = col - 1;
        pos.set(c, r);
        if(r < 1 && board[pos].isWhite() && board[pos].getType() != PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        
        
        //PROMOTE
        r = row - 1;
        c = col;
        pos.set(c, r);
        if (r == 0 && board[pos].getType() == PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::QUEEN, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        c = col - 1;
        pos.set(c, r);
        if ((c >= 0) && (r == 0) && (board[pos].isWhite() != fWhite) && board[pos].getType() != PieceType::SPACE){
            moves.insert(Move(position, pos, PieceType::QUEEN, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        c = col + 1;
        pos.set(r, c);
        if ((c < 8) && (r == 0) && (board[pos].isWhite() != fWhite) && (board[pos].getType() != PieceType::SPACE)){
            moves.insert(Move(position, pos, PieceType::QUEEN, board[pos].getType(), Move::MoveType::MOVE, isWhite()));
        }
        
        
        //ENPASSANT
        c = col - 1;
        r = row;
        pos.set(c, r);
        if(col >= 0 && row == 3 && board[pos].getType() == PieceType ::PAWN && board[pos].getLastMove() == board.getCurrentMove() - 1 && (board[pos].isWhite() != fWhite)){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType:: ENPASSANT, isWhite()));
        }
        c = col + 1;
        pos.set(c, r);
        if(col < 8 && row == 3 && board[pos].getType() == PieceType ::PAWN && board[pos].getLastMove() == board.getCurrentMove() - 1 && (board[pos].isWhite() != fWhite)){
            moves.insert(Move(position, pos, PieceType::INVALID, board[pos].getType(), Move::MoveType:: ENPASSANT, isWhite()));
        }
    }
}
