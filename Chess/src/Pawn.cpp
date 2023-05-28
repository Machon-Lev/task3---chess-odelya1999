/****************
Odelya Yakowich
207346784
*****************/

#include "Pawn.h"


 bool Pawn::isLegalMove(int myRowDst, int myColDst) const
{
	Piece* destPiece = board->getBoard()[myRowDst * BOARD_SIZE + myColDst];
	Player* playerDstPosition = destPiece->getPlayer();
	bool gameOperation;
	int num = 1;


	if (playerDstPosition != NULL  && playerDstPosition != player)
	{
		if (player->isGoingUp())
			gameOperation = (row - myRowDst) == 1;
		else
			gameOperation = (row - myRowDst) == -1;

		gameOperation = gameOperation && abs(col - myColDst) == 1;
		return gameOperation;
	}
	
	if (playerDstPosition != NULL) // check if Dst is free
		return false;

	if (row == startRow && col == startCol) // check if didn't move frome his current place
		num = 2;

	if (player->isGoingUp())
		gameOperation = col == myColDst && (myRowDst - row) < 0 && (myRowDst - row) >= num * -1;
	else
		gameOperation = col == myColDst && (myRowDst - row) > 0 && (myRowDst - row) <= num;

	if (gameOperation && num == 2)
		gameOperation = this->isWayFree(myRowDst, myColDst);
	
	return gameOperation;
}