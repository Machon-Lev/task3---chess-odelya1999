/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Piece.h"

class NullPiece : public Piece
{
public:
	NullPiece(int myRow, int myCol) : Piece(NULL, '-', myRow, myCol, NULL) {};
	virtual bool isLegalMove(int myRowDst, int myColDst) const;
};