/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Player* myPlayer, int myRow, int myCol, Board* myBoard) : Piece(myPlayer, 'p', myRow, myCol, myBoard) {}; //ctor
	virtual bool isLegalMove(int myRowDst, int myColDst) const;

};