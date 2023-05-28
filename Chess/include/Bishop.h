/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Player* myPlayer, int myRow, int myCol, Board* myBoard) : Piece(myPlayer, 'b', myRow, myCol, myBoard) {};//ctor
	virtual bool isLegalMove(int myRowDst, int myColDst) const;
};