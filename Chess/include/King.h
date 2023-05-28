/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Piece.h"

class Piece;
class Player;
class Board;

class King : public Piece
{
public:
	King(Player* myPlayer, int myRow, int myCol, Board* myBoard);//ctor
	virtual bool isLegalMove(int myRowDst, int myColDst) const;
	bool isChess();//if there is chess to the king
};