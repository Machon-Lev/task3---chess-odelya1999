/****************
Odelya Yakowich
207346784
*****************/

#include "Piece.h"
#include <string>
#include <iostream>

using namespace std;

Piece::Piece(Player* pl, char sign, int myRow, int myCol, Board* myBoard) :player(pl), row(myRow), col(myCol), board(myBoard), startRow(myRow), startCol(myCol)
{
	if (pl != NULL && pl->isWhite())
	{
		signPlayer = toupper(sign);
	}
	else
	{
		signPlayer = tolower(sign);
	}
}

Piece::~Piece()
{

}

char Piece::getSign() const
{
	return signPlayer;
}

Player* Piece::getPlayer() const
{
	return player;
}

void Piece::setPosition(int myRow, int myCol)
{
	row = myRow;
	col = myCol;
}
bool Piece::isWayFree(int dstRow, int dstCol) const
{
	Piece** matBoard = board->getBoard();
	Piece* currPiece = NULL;
	int  i,j;
	// move on the col only
	if (row == dstRow)
	{
		int startCol = col < dstCol ? col : dstCol;
		int endCol = col < dstCol ? dstCol : col;

		for (j = startCol + 1; j < endCol ; ++j)
		{
			currPiece = *(matBoard  + row * BOARD_SIZE + j);

			// if there is player that own the piece
			if (currPiece->getPlayer() != NULL)
			{
				return false;
			}
		}

		return true;
	}
	
	// move on the rows only
	if (col == dstCol)
	{
		int startRow = row < dstRow ? row : dstRow;
		int endRow = row < dstRow ? dstRow : row;

		for (i = startRow + 1; i < endRow; ++i)
		{
			currPiece = *(matBoard + i * BOARD_SIZE + col);

			// if there is player that own the piece
			if (currPiece->getPlayer() != NULL)
			{
				return false;
			}
		}

		return true;
	}


	// check diagonal move
	int startRow = dstRow < row ? dstRow : row;
	int endRow = dstRow < row ? row : dstRow;
	int startCol;

	int num = 1;
	if (row < dstRow)

	{
		startCol = col;
		if (col > dstCol)
		{
			num = -1;
		}
	}
	else 
	{
		startCol = dstCol;
		if (col < dstCol)
		{
			num = -1;
		}
	}

	for (i = startRow + 1, j = startCol+num; i < endRow ; ++i)
	{
		currPiece = *(matBoard + i * 8 + j);

		// check if the board in the place contains null piece
		if (currPiece->getPlayer() != NULL)
		{
			return false;
		}
		j += num;
	}

	return true;
}

