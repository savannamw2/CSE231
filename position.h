/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;
using namespace std;

const int SIZE_SQUARE  = 32;   // number of pixels in a square by default

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0};
const Delta ADD_C = { 0,  1};
const Delta SUB_R = {-1,  0};
const Delta SUB_C = { 0, -1};


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
    friend class TestMove;
    friend class TestSpace;
    
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
    Position(const Position & rhs);
    Position();
    bool isInvalid() const         { return (bool) (colRow & 0x88);}
    bool isValid()   const         { return !isInvalid() ;}
    void setValid()                {   colRow = 0x77;      }
    void setInvalid()              {   colRow = 0x88;      }
    bool operator <  (const Position & rhs) const { return colRow < rhs.colRow;}
    bool operator == (const Position & rhs) const { return colRow == rhs.colRow; }
    bool operator != (const Position & rhs) const { return colRow != rhs.colRow; }
    const Position & operator =  (const Position & rhs) { this -> colRow = rhs.colRow; return *this;  }
   
   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
    Position(int location)  {colRow = ((location / 8) << 4) | (location % 8); }
    int getLocation() const { int r = (colRow & 0xf0) >> 4; int c = ((colRow & 0x0f) >> 0); return (c * 8) + r;};
    void setLocation(int location)        { colRow = ((location / 8) << 4) | (location % 8);    }

   
   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
    Position(int c, int r)  {  set(c, r)   ;      }
    virtual int getCol() const                     { if (isInvalid()) return -1; else return (int)((colRow & 0xf0) >> 4);}
    virtual int getRow() const                     { if (isInvalid()) return -1; else return (int)((colRow & 0x0f) >> 0);}
    void setRow(int r)                     { colRow = (colRow & 0xf0) | r;   if (isInvalid()) colRow = 0xff;}
    void setCol(int c)                     { colRow = (colRow & 0x0f) | (c << 4); if (isInvalid()) colRow = 0xff;        }
    void set(int c, int r)                 { if (c < 0 || c >= 8) { colRow = 0xff; return;} if (r < 0 || r >= 8)
                                                {colRow = 0x3f; return;} colRow = (c << 4) | r;}
    /* {  colRow = (colRow & 0xf0) | r; if (isInvalid()) colRow = 0xff;
     colRow = (colRow & 0x0f)| (c << 4); if (isInvalid()) colRow = 0x3f;   }*/

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"
   
    Position(const char * s) : colRow(0x00)
    {
        if (s && s[0] >= 'a' && s[0] <= 'h' && s[1] >= '1' && s[1] <= '8') {
                    int c = s[0] - 'a'; // column 'a' -> 0, 'b' -> 1, ..., 'h' -> 7
                    int r = s[1] - '1';  // row '1' -> 0, '2' -> 1, ..., '8' -> 7
                    colRow = (c << 4) | r; // Pack column and row together
                }
    }
    const Position & operator =  (const char     * rhs)
    {
        if (rhs && rhs[0] >= 'a' && rhs[0] <= 'h' && rhs[1] >= '1' && rhs[1] <= '8') {
            int c = rhs[0] - 'a';
            int r = rhs[1] - '1';
            colRow = (c << 4) | r;       }
            return *this;
    }
    const Position & operator =  (const string   & rhs)
    {
        if (!rhs.empty() && rhs[0] >= 'a' && rhs[0] <= 'h' && rhs[1] >= '1' && rhs[1] <= '8')
        {
            int c = rhs[0] - 'a';
            int r = rhs[1] - '1';
            colRow = (c << 4) | r;    }
        return *this;
    }

    string toString() const{
        char column = (colRow>>4) + 'a';
        char row = (colRow & 0x0f) + '1';
        return std::string(1,column) + std::string(1, row);
    }
   
   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const
   {
      return (int)((double)getCol() * getSquareWidth() + getSquareWidth());
   }
   int getY()   const
   {
      return (int)((double)getRow() * getSquareHeight() + getSquareHeight());
   }
   void setXY(double x, double y)
   {
      set(    (int)(x / getSquareWidth ()) - 1,
          8 - (int)(y / getSquareHeight())   );
   }
   double getSquareWidth()  const { return squareWidth;  }
   double getSquareHeight() const { return squareHeight; }
   void setBoardWidthHeight(int widthBoard, int heightBoard)
   {
      if (widthBoard < 0 || heightBoard < 0)
         return;
      squareWidth  = (double)widthBoard / 10.0; // 8 squares + 2 spaces
      squareHeight = (double)heightBoard / 10.0;
   }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position & rhs, const Delta & delta)  { adjustRow(delta.dRow);
       adjustCol(delta.dCol);  }
    void adjustRow(int dRow)   {
        int row = (colRow & 0x0f);
        row += dRow;

        if (row < 0 || row > 7) {
            colRow = 0xff;
        } else {
            colRow = (colRow & 0xf0) | row;
        }
    }
   void adjustCol(int dCol)   {
       int col = (colRow & 0xf0) >> 4;
       col += dCol;

       if (col < 0 || col > 7) {
           colRow = 0xff;
       } else {
           colRow = (colRow & 0x0f) | (col << 4);
       }
   }
    const Position & operator += (const Delta & rhs) {
        adjustRow(rhs.dRow);
        adjustCol(rhs.dCol);
        return *this;
    }
   Position operator + (const Delta & rhs) const {     Position newPos = *this;
       newPos.adjustCol(rhs.dCol);
       return newPos; }

private:
   void set(uint8_t colRowNew) { }
   
   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream & operator << (ostream & out, const Position & pos);
istream & operator >> (istream & in,  Position & pos);
      
