/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:

	Rook(Player* myPlayer, int myRow, int myCol, Board* myBoard) : Piece(myPlayer, 'r', myRow, myCol, myBoard) {};//ctor
	virtual bool isLegalMove(int myRowDst, int myColDst) const;

};