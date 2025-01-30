/***********************************************************************
 * Source File:
 *    TEST POSITION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The unit tests for Position
 ************************************************************************/


#include "testPosition.h" // for POSITION_TEST
#include "position.h"     // for POSITION
#include <cassert>        // for ASSERT


/***********************************************
 * GET  Zero
 * Default position: slot zero at a1
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1 (0x00)0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 ************************************************/
void PositionTest::getRow_zero()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assertUnit(row == 0);
   assertUnit(pos.colRow == 0x00);

}  // TEARDOWN
void PositionTest::getCol_zero()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assertUnit(col == 0);
   assertUnit(pos.colRow == 0x00);

}  // TEARDOWN
void PositionTest::getLocation_zero()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;
   int location;

   // EXERCISE
   location = pos.getLocation();

   // VERIFY
   assertUnit(location == 0);
   assertUnit(pos.colRow == 0x00);

}  // TEARDOWN
void PositionTest::isValid_zero()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assertUnit(f == true);
   assertUnit(pos.colRow == 0x00);

}  // TEARDOWN
void PositionTest::isInvalid_zero()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assertUnit(f == false);
   assertUnit(pos.colRow == 0x00);

}  // TEARDOWN


/*************************************
 * GET  Middle
 * Default position: slot in the middle at b5
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04(0x14)0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::getRow_middle()
{
   // SETUP
   Position pos;
   pos.colRow = 0x14;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assertUnit(row == 4);
   assertUnit(pos.colRow == 0x14);

}  // TEARDOWN
void PositionTest::getCol_middle()
{
   // SETUP
   Position pos;
   pos.colRow = 0x14;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assertUnit(col == 1);
   assertUnit(pos.colRow == 0x14);

}  // TEARDOWN
void PositionTest::getLocation_middle()
{
   // SETUP
   Position pos;
   pos.colRow = 0x14;
   int location;

   // EXERCISE
   location = pos.getLocation();

   // VERIFY
   assertUnit(location == 33);
   assertUnit(pos.colRow == 0x14);

}  // TEARDOWN
void PositionTest::isValid_middle()
{
   // SETUP
   Position pos;
   pos.colRow = 0x14;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assertUnit(f == true);
   assertUnit(pos.colRow == 0x14);

}  // TEARDOWN
void PositionTest::isInvalid_middle()
{
   // SETUP
   Position pos;
   pos.colRow = 0x14;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assertUnit(f == false);
   assertUnit(pos.colRow == 0x14);

}  // TEARDOWN

/*************************************
 * GET TEST End
 * End position: slot in the end at h8
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67(0x77) 8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::getRow_end()
{
   // SETUP
   Position pos;
   pos.colRow = 0x77;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assertUnit(row == 7);
   assertUnit(pos.colRow == 0x77);

}  // TEARDOWN
void PositionTest::getCol_end()
{
   // SETUP
   Position pos;
   pos.colRow = 0x77;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assertUnit(col == 7);
   assertUnit(pos.colRow == 0x77);

}  // TEARDOWN
void PositionTest::getLocation_end()
{
   // SETUP
   Position pos;
   pos.colRow = 0x77;
   int location;

   // EXERCISE
   location = pos.getLocation();

   // VERIFY
   assertUnit(location == 63);
   assertUnit(pos.colRow == 0x77);

}  // TEARDOWN
void PositionTest::isValid_end()
{
   // SETUP
   Position pos;
   pos.colRow = 0x77;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assertUnit(f == true);
   assertUnit(pos.colRow == 0x77);

}  // TEARDOWN
void PositionTest::isInvalid_end()
{
   // SETUP
   Position pos;
   pos.colRow = 0x77;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assertUnit(f == false);
   assertUnit(pos.colRow == 0x77);

}  // TEARDOWN

/*************************************
 * GET TEST Invalid
 * Default invalid position: -1
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                     (  )  |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::getRow_invalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0xff;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assertUnit(row == -1);
   assertUnit(pos.colRow == 0xff);

}  // TEARDOWN
void PositionTest::getCol_invalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0xff;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assertUnit(col == -1);
   assertUnit(pos.colRow == 0xff);

}  // TEARDOWN
void PositionTest::isValid_invalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0xff;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assertUnit(f == false);
   assertUnit(pos.colRow == 0xff);

}  // TEARDOWN
void PositionTest::isInvalid_invalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0xff;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assertUnit(f == true);
   assertUnit(pos.colRow == 0xff);

}  // TEARDOWN

/*************************************
 * GET TEST Row Invalid
 * The row is invalid (9) but the column is valid (5)
 * +---a----b----c----d----e----f----g----h----+
 * |                          (    )           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::getRow_rowInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x59;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assertUnit(row == -1);
   assertUnit(pos.colRow == 0x59);

}  // TEARDOWN
void PositionTest::getCol_rowInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x59;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assertUnit(col == -1);
   assertUnit(pos.colRow == 0x59);

}  // TEARDOWN
void PositionTest::isValid_rowInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x59;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assertUnit(f == false);
   assertUnit(pos.colRow == 0x59);

}  // TEARDOWN
void PositionTest::isInvalid_rowInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x59;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assertUnit(f == true);
   assertUnit(pos.colRow == 0x59);

}  // TEARDOWN

/*************************************
 * GET TEST Col Invalid
 * The col is invalid (9) but the row is valid (5)
 * +---a----b----c----d----e----f----g----h--------+
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77      8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76      7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75      6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74 (  ) 5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73      4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72      3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71      2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70      1
 * +---a----b----c----d----e----f----g----h--------+
 **************************************/
void PositionTest::getRow_colInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x95;
   int row;

   // EXERCISE
   row = pos.getRow();

   // VERIFY
   assertUnit(row == -1);
   assertUnit(pos.colRow == 0x95);

}  // TEARDOWN
void PositionTest::getCol_colInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x95;
   int col;

   // EXERCISE
   col = pos.getCol();

   // VERIFY
   assertUnit(col == -1);
   assertUnit(pos.colRow == 0x95);

}  // TEARDOWN
void PositionTest::isValid_colInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x95;
   bool f;

   // EXERCISE
   f = pos.isValid();

   // VERIFY
   assertUnit(f == false);
   assertUnit(pos.colRow == 0x95);

}  // TEARDOWN
void PositionTest::isInvalid_colInvalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0x95;
   bool f;

   // EXERCISE
   f = pos.isInvalid();

   // VERIFY
   assertUnit(f == true);
   assertUnit(pos.colRow == 0x95);

}  // TEARDOWN

/*************************************
 * SET TEST Col
 * Set to f1 using setCol
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40(0x50)0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::set_col()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;

   // EXERCISE
   pos.setCol(5);

   // VERIFY
   assertUnit(pos.colRow == 0x50);

   // TEARDOWN
}

/*************************************
 * SET TEST Row
 * Set to a5 user setRow
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5 (0x04)0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::set_row()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;

   // EXERCISE
   pos.setRow(4);

   // VERIFY
   assertUnit(pos.colRow == 0x04);

   // TEARDOWN
}

/*************************************
 * SET TEST Both
 * Set to h5
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64(0x74) 5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::set_both()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;

   // EXERCISE
   pos.set(7 /*col*/, 4 /*row*/);

   // VERIFY
   assertUnit(pos.colRow == 0x74);

   // TEARDOWN
}


/*************************************
 * SET TEST Text
 * Set to "c6" 
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15(0x25)0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::set_text()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;

   // EXERCISE
   pos = "c6";

   // VERIFY
   assertUnit(pos.colRow == 0x25);

   // TEARDOWN
}

void PositionTest::set_string()
{
   // SETUP
   Position pos;
   pos.colRow = 0x00;

   // EXERCISE
   pos = string("c6");

   // VERIFY
   assertUnit(pos.colRow == 0x25);

   // TEARDOWN
}

void PositionTest::set_copy()
{
   // SETUP
   Position pos;
   Position posRHS;
   posRHS.colRow = 0x25;

   // EXERCISE
   pos = posRHS;

   // VERIFY
   assertUnit(pos.colRow == 0x25);
   assertUnit(posRHS.colRow == 0x25);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST AddColumn
 * add one column to the middle: g3
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52(0x62)0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::adjust_addColumn()
{
   // SETUP
   Position pos;
   pos.colRow = 0x62;

   // EXERCISE
   pos += ADD_C;

   // VERIFY
   assertUnit(pos.colRow == 0x72);

   // TEARDOWN
}

void PositionTest::adjust_addRow()
{
   // SETUP
   Position pos;
   pos.colRow = 0x62;

   // EXERCISE
   pos += ADD_R;

   // VERIFY
   assertUnit(pos.colRow == 0x63);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffRight
 * go of the end to the right H4
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63(0x73) 4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+

 **************************************/
void PositionTest::adjust_offRight()
{
   // SETUP
   Position pos;
   pos.colRow = 0x73;

   // EXERCISE
   pos += ADD_C;

   // VERIFY
   assertUnit(pos.colRow == 0xff);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffTop
 * go of the end to the top e8
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37(0x47)0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::adjust_offTop()
{
   // SETUP
   Position pos;
   pos.colRow = 0x47;

   // EXERCISE
   pos += ADD_R;

   // VERIFY
   assertUnit(pos.colRow == 0xff);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffLeft
 * go off the end to the right a5
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5 (0x04)0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::adjust_offLeft()
{
   // SETUP
   Position pos;
   pos.colRow = 0x04;

   // EXERCISE
   pos += SUB_C;

   // VERIFY
   assertUnit(pos.colRow == 0xff);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST OffBottom
 * go off the end to the bottom e1
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30(0x40)0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::adjust_offBottom()
{
   // SETUP
   Position pos;
   pos.colRow = 0x40;

   // EXERCISE
   pos += SUB_R;

   // VERIFY
   assertUnit(pos.colRow == 0xff);

   // TEARDOWN
}

/*************************************
 * ADJUST TEST Invalid
 * Start off invalid
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                     (  )  |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::adjust_invalid()
{
   // SETUP
   Position pos;
   pos.colRow = 0xff;

   // EXERCISE
   pos += ADD_R;

   // VERIFY
   assertUnit(pos.colRow == 0xff);

   // TEARDOWN
}



/*************************************
 * GET_X  A1
 * Bottom Left
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1 (0x00)0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::getX_a1()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x00;
   pos.squareWidth = 17;
   pos.squareHeight = 19;
   int x = -99;

   // EXERCISE
   x = pos.getX();

   // VERIFY
   assertUnit(x == 17);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

void PositionTest::getY_a1()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x00;
   pos.squareWidth = 17;
   pos.squareHeight = 19;
   int y = -99;

   // EXERCISE
   y = pos.getY();

   // VERIFY
   assertUnit(y == 19);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * GET_X  E7
 * In the middle somewhere
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36(0x46)0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::getX_e7()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 19;
   int x = -99;

   // EXERCISE
   x = pos.getX();

   // VERIFY
   assertUnit(x == 17 * 5);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

void PositionTest::getY_e7()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 19;
   int y = -99;

   // EXERCISE
   y = pos.getY();

   // VERIFY
   assertUnit(y == 19 * 7);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * GET WIDTH  10
 * Size of a single square where the board size is 10
 *************************************/
void PositionTest::getWidth_10()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.squareWidth = 10;
   pos.squareHeight = 99;
   int w = -99;

   // EXERCISE
   w = pos.getSquareWidth();

   // VERIFY
   assertUnit(w == 10);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

void PositionTest::getHeight_10()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.squareWidth = 99;
   pos.squareHeight = 10;
   int h = -99;

   // EXERCISE
   h = pos.getSquareHeight();

   // VERIFY
   assertUnit(h == 10);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET BOARD WIDTH HEIGHT
 * Set the size of a square based on the size of the board
 *************************************/
void PositionTest::setBoardWidthHeight_10()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.squareWidth = 88;
   pos.squareHeight = 99;
   int w = 10;
   int h = 10;

   // EXERCISE
   pos.setBoardWidthHeight(w, h);

   // VERIFY
   assertUnit(pos.squareWidth == 1.0);
   assertUnit(pos.squareHeight == 1.0);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

void PositionTest::setBoardWidthHeight_420x830()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.squareWidth = 88;
   pos.squareHeight = 99;
   int w = 420;
   int h = 830;

   // EXERCISE
   pos.setBoardWidthHeight(w, h);

   // VERIFY
   assertUnit(pos.squareWidth == 42.0);
   assertUnit(pos.squareHeight == 83.0);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   a8
 * Top left
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8 (0x07)0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_a8()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 35;
   int x = 18;
   int y = 37;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0x07);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   a1
 * Bottom left
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1 (0x00)0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_a1()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 37;
   int x = 18;
   int y = 37 + (37 * 7) + 24;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0x00);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   h8
 * Top Right
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67(0x77) 8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_h8()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 37;
   int x = 17 + (17 * 7) + 12;
   int y = 43;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0x77);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   h1
 * Bottom right
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60(0x70)  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_h1()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 37;
   int x = 17 + (17 * 7) + 12;
   int y = 37 + (37 * 7) + 24;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0x70);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   invalid xmin
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3()0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_invalidXMin()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 37;
   int x = 12;
   int y = 37 + (37 * 5) + 24;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0xff);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   invalid xmax
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72()3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_invalidXMax()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 37;
   int x = 17 + (17 * 8) + 2;
   int y = 37 + (37 * 5) + 24;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0xff);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   invalid ymin
 * +---a----b----c----d----e----f----g----h----+
 * |                 ( )                       |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                                           |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_invalidYMin()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 37;
   int x = 17 + (17 * 3) + 15;
   int y = 25;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0x3f);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}

/*************************************
 * SET X Y   invalid ymax
 * +---a----b----c----d----e----f----g----h----+
 * |                                           |
 * 8  0x07 0x17 0x27 0x37 0x47 0x57 0x67 0x77  8
 * 7  0x06 0x16 0x26 0x36 0x46 0x56 0x66 0x76  7
 * 6  0x05 0x15 0x25 0x35 0x45 0x55 0x65 0x75  6
 * 5  0x04 0x14 0x24 0x34 0x44 0x54 0x64 0x74  5
 * 4  0x03 0x13 0x23 0x33 0x43 0x53 0x63 0x73  4
 * 3  0x02 0x12 0x22 0x32 0x42 0x52 0x62 0x72  3
 * 2  0x01 0x11 0x21 0x31 0x41 0x51 0x61 0x71  2
 * 1  0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70  1
 * |                  ()                       |
 * +---a----b----c----d----e----f----g----h----+
 **************************************/
void PositionTest::setXY_invalidYMax()
{
   // SETUP
   Position pos;
   double squareWidth = pos.squareWidth;
   double squareHeight = pos.squareHeight;

   pos.colRow = 0x46;
   pos.squareWidth = 17;
   pos.squareHeight = 37;
   int x = 17 + (17 * 3) + 15;
   int y = 37 + (37 * 8) + 2;

   // EXERCISE
   pos.setXY(x, y);

   // VERIFY
   assertUnit(pos.colRow == 0x3f);

   // TEARDOWN
   pos.squareWidth = squareWidth;
   pos.squareHeight = squareHeight;
}