/****************
Odelya Yakowich
207346784
*****************/

#include "Rook.h"

bool Rook::isLegalMove(int myRowDst, int dstCol) const
{

	int sameRow = myRowDst - row;
	int sameCol = dstCol - col;

	if ((sameRow != 0) && (sameCol != 0)) // check if the destinition has same row or same col
	{
		return false;
	}
	else //if Dst slote is free
	{
		return Piece::isWayFree(myRowDst, dstCol);
	}
}