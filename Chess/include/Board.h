/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Piece.h"
#include "Player.h"


#define BOARD_SIZE 8

using namespace std;

class Player;
class Piece;

class Board
{
	Piece* boardChess[BOARD_SIZE][BOARD_SIZE];//board size = 8*8
	int srcRowGame;
	int srcColGame;
	int dstRowGame;
	int dstColGame;
	Piece* lastPieceGame;

public:

	Board(Player*, Player*); //ctor
	~Board(); //d-ctor
	void getString(char res[]) const;
	Piece** getBoard() const { return (Piece**)boardChess; };
	bool isPieceOfPlayer(int row, int col, Player* pl) const; //if the player is from our team
	bool isEmpty(int row, int col); //if current slote is empty
	bool tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const;
	void Move(int srcRow, int srcCol, int dstRow, int dstCol);
	void print() const;
	void undoLastMove();
};