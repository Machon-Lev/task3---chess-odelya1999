/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:

	Knight(Player* myPlayer, int myRow, int myCol, Board* myBoard) : Piece(myPlayer, 'n', myRow, myCol, myBoard) {}; //ctor
	virtual bool isLegalMove(int myRowDst, int myColDst) const;
};