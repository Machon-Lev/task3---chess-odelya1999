/****************
Odelya Yakowich
207346784
*****************/

#include "Board.h"
#include "Pawn.h"
#include "NullPiece.h"
#include "Player.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

#include <iostream>

Board::Board(Player* pl1, Player* pl2) : lastPieceGame(NULL)
{


	// -------------------------Queens----------------------
	boardChess[0][4] = new Queen(pl1, 0, 4, this);
	boardChess[BOARD_SIZE - 1][4] = new Queen(pl2, BOARD_SIZE - 1, 4, this);

	//--------------------------Pawns------------------------
	for (int j = 0; j < BOARD_SIZE; j++)
	{
		boardChess[1][j] = new Pawn(pl1, 1, j, this);
		boardChess[BOARD_SIZE - 2][j] = new Pawn(pl2, BOARD_SIZE - 2, j, this);
	}

	// -------------------------Knights---------------------
	boardChess[0][1] = new Knight(pl1, 0, 1, this);
	boardChess[0][BOARD_SIZE - 2] = new Knight(pl1, 0, BOARD_SIZE - 2, this);
	boardChess[BOARD_SIZE - 1][1] = new Knight(pl2, BOARD_SIZE - 1, 1, this);
	boardChess[BOARD_SIZE - 1][BOARD_SIZE - 2] = new Knight(pl2, BOARD_SIZE - 1, BOARD_SIZE - 2, this);


	// --------------------------Rooks--------------------
	boardChess[0][0] = new Rook(pl1, 0, 0, this);
	boardChess[0][BOARD_SIZE - 1] = new Rook(pl1, 0, BOARD_SIZE - 1, this);
	boardChess[BOARD_SIZE - 1][0] = new Rook(pl2, BOARD_SIZE - 1, 0, this);
	boardChess[BOARD_SIZE - 1][BOARD_SIZE - 1] = new Rook(pl2, BOARD_SIZE - 1, BOARD_SIZE - 1, this);

	//--------------------------Bishops--------------------
	boardChess[0][2] = new Bishop(pl1, 0, 2, this);
	boardChess[0][BOARD_SIZE - 3] = new Bishop(pl1, 0, BOARD_SIZE - 3, this);
	boardChess[BOARD_SIZE - 1][2] = new Bishop(pl2, BOARD_SIZE - 1, 2, this);
	boardChess[BOARD_SIZE - 1][BOARD_SIZE - 3] = new Bishop(pl2, BOARD_SIZE - 1, BOARD_SIZE - 3, this);

	// -------------------------Kings----------------------
	boardChess[0][3] = new King(pl1, 0, 3, this);
	boardChess[BOARD_SIZE - 1][3] = new King(pl2, BOARD_SIZE - 1, 3, this);


	//------------------- Null pieces----------------------------

	for (int i = 2; i < BOARD_SIZE - 2; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			boardChess[i][j] = new NullPiece(i, j);
	}
	
}


Board::~Board()
{
	for ( int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			delete boardChess[i][j];
	}
}


void Board::print() const
{

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << i  << j << ":";
			cout << boardChess[i][j]->getSign() << " ";
		}
		cout << endl;
	}
}

void Board::getString(char res[]) const
{
	int index=0;
	
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			res[index++] = boardChess[i][j]->getSign();
	}
	res[index] = 0;
}


bool Board::isPieceOfPlayer(int row, int col, Player* pl) const
{
	
	return boardChess[row][col]->getPlayer() == pl;
}


void Board::Move(int srcRow, int srcCol, int dstRow, int dstCol) 
{
	if (lastPieceGame != NULL)
		delete lastPieceGame;

	lastPieceGame = boardChess[dstRow][dstCol];
	srcRowGame = srcRow;
	srcColGame = srcCol;
	dstRowGame = dstRow;
	dstColGame = dstCol;
	boardChess[dstRow][dstCol] = boardChess[srcRow][srcCol];
	boardChess[dstRow][dstCol]->setPosition(dstRow, dstCol);
	boardChess[srcRow][srcCol] = new NullPiece(srcRow, srcCol);
}


void Board::undoLastMove()
{
	// unable to do undo
	if (lastPieceGame == NULL)
	{
		return;
	}
	delete boardChess[srcRowGame][srcColGame];
	boardChess[srcRowGame][srcColGame] = boardChess[dstRowGame][dstColGame];
	boardChess[srcRowGame][srcColGame]->setPosition(srcRowGame, srcColGame);
	boardChess[dstRowGame][dstColGame] = lastPieceGame;
	lastPieceGame = NULL;
}


bool Board::isEmpty(int row, int col)
{
	cout << boardChess[row][col]->getSign();
	return boardChess[row][col]->getSign() == '-';
}


bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const
{
	return boardChess[srcRow][srcCol]->isLegalMove(dstRow, dstCol);
}