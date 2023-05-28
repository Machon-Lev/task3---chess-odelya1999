/****************
Odelya Yakowich
207346784
*****************/


#include "King.h"

King::King(Player* myPlayer, int myRow, int myCol, Board* myBoard) : Piece(myPlayer, 'k', myRow, myCol, myBoard)
{
	myPlayer->setKing(this);
}


bool King::isLegalMove(int myRowDst, int myColDst) const
{
	bool isLessOne = (abs(myRowDst - row) <= 1) && (abs(myColDst - col) <= 1); // checking diagonal movement
	return isLessOne;
}


bool King::isChess()
{
	Piece* currPiece;
	Player* playerGame;
	Piece** boardGame = board->getBoard();
	int i, j;


	for (i = 0; i < BOARD_SIZE; i++) //chek if there is a chess from all the ways
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			currPiece = boardGame[i * BOARD_SIZE + j];
			playerGame = currPiece->getPlayer();

			if (playerGame != NULL && playerGame != player)
			{
				if (currPiece->isLegalMove(row, col)) //if the other player has an access to my slote
				{
					return true;
				}
			}
		}
	}
	
	return false;
}