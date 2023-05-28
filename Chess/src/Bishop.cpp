/****************
Odelya Yakowich
207346784
*****************/

#include "Bishop.h"


bool Bishop::isLegalMove(int myRowDst, int myColDst) const
{
	int rowSteps = abs(myRowDst - this->row);
	int colSteps = abs(myColDst - this->col);
	bool isDiagonal = rowSteps == colSteps;

	if (!isDiagonal) // check if it's diagonal movement
		return false;

	bool res = Piece::isWayFree(myRowDst, myColDst);  // check if Dst is free

	return res;
}