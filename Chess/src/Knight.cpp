/****************
Odelya Yakowich
207346784
*****************/


#include "Knight.h"

bool Knight::isLegalMove(int myRowDst, int myColDst) const
{
	int culcRow = abs(myRowDst - this->row);
	int culcCol = abs(myColDst - this->col);

	bool gameOperation = (culcRow == 2 && culcCol == 1) || (culcRow == 1 && culcCol == 2);
	
	return gameOperation;
}