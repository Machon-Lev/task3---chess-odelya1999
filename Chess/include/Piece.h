/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Player.h"
#include "Board.h"

using namespace std;

class Player;
class Board;

class Piece
{
private:
	char signPlayer;

protected:
	Player* player; // first\seconed\none player
	int startRow;
	int startCol;
	Board* board;
	//if we need to return the player to his previous location 
	int row;
	int col;

	bool isWayFree(int dstRow, int dstCol) const;

public:
	Piece(Player*, char sign, int myRow, int myCol, Board* myBoard); //ctor
	virtual ~Piece(); //dctor
	void setPosition(int myRow, int myCol); //set the privious position of the player
	char getSign() const; //what is the kind of the player
	Player* getPlayer() const;
	virtual bool isLegalMove(int myRow, int myCol) const = 0;

};