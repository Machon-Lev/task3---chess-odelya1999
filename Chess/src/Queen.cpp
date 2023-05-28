/****************
Odelya Yakowich
207346784
*****************/

#include "Queen.h"

bool Queen::isLegalMove(int myRowDst, int myColDst) const
{
	int rowSteps = abs(myRowDst - this->row);
	int colSteps = abs(myColDst - this->col);
	bool isDiagonal = rowSteps == colSteps;
	bool isNotStraight = rowSteps != 0 && colSteps != 0; 

	if (!isDiagonal && isNotStraight) //if the movement of the queen isn't diagonal - she need to move right or left
		return false;

	bool res = Piece::isWayFree(myRowDst, myColDst); // check if the Dst is free
	return res;
}