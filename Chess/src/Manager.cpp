/****************
Odelya Yakowich
207346784
*****************/


#include "Manager.h"
#include "King.h"
#include <iostream>
#include <exception>

using namespace std;

#define VALID_MOVE 42
#define INVALID_EMPTY_POSIRION 11
#define VALID_CHESS_MOVE 41
#define INVALID_NOT_YOUR_PLAYER 12
#define INVALID_DEST_NOT_FREE 13
#define INVALID_CHESS_WILL_OCCURE 31
#define INVALID_OUT_OF_BOUNDS 21
#define INVALID_ILLEGAL_MOVE 21
#define INVALID_SRC_AND_DEST_EQUAL 21


Manager::Manager()
{
	firstPlayer = new Player(true);
	seconedPlayer = new Player(false);
	currentPlayer = firstPlayer;
	otherPlayer = seconedPlayer;
	board = new Board(firstPlayer, seconedPlayer);
}


Manager::~Manager()
{
	delete firstPlayer;
	delete seconedPlayer;
	delete board;
}


void Manager::changeTurn()
{
	Player* temp = currentPlayer;
	currentPlayer = otherPlayer;
	otherPlayer = temp;
}


int Manager::moveOnBoard(string move)
{   
	//finding the src and dst of the current player
	int srcCol = BOARD_SIZE - (move[1] - '0');
	int srcRow = move[0] - 'a';
	int dstCol = BOARD_SIZE -  (move[3] - '0');
	int dstRow = move[2] - 'a';
	
	//checking that src and dst isn't out of ranhe of the board
	if (srcRow < 0 || srcRow >= BOARD_SIZE ||
		srcCol < 0 || srcCol >= BOARD_SIZE ||
		dstRow < 0 || dstRow >= BOARD_SIZE ||
		dstCol < 0 || dstCol >= BOARD_SIZE)
	{
		return INVALID_OUT_OF_BOUNDS;
	}
	else if (board->isEmpty(srcRow, srcCol)) //if the src is an empty slote - incorrect operation
	{
		return INVALID_EMPTY_POSIRION;
	}
	else if (!board->isPieceOfPlayer(srcRow, srcCol, currentPlayer))//if the player that you want to move isn't from your team
	{
		return INVALID_NOT_YOUR_PLAYER;
	}
	else if (board->isPieceOfPlayer(dstRow, dstCol, currentPlayer))//in the slote dst that you chose - there is a player from your team
	{
		return INVALID_DEST_NOT_FREE;
	}
    else if (srcRow == dstRow && srcCol == dstCol)
	{
		return INVALID_SRC_AND_DEST_EQUAL;
	}
	else if (!board->tryMove(srcRow, srcCol, dstRow, dstCol))//this operation isn't legal
	{
		return INVALID_ILLEGAL_MOVE;
	}

	board->Move(srcRow, srcCol, dstRow, dstCol);//move the player on the board
	int codeOperation;
	
	if (currentPlayer->getKing()->isChess())// if we have chess and our king is in danger after the last move
	{
		board->undoLastMove();//cancel the last move
		return INVALID_CHESS_WILL_OCCURE;
	}
	else if (otherPlayer->getKing()->isChess()) // if the other team have chess and their king is in danger after the last move
	{
		
		codeOperation =  VALID_CHESS_MOVE;
	}
	else
	{
		codeOperation = VALID_MOVE;
	}
	changeTurn();
	return codeOperation;

} 

