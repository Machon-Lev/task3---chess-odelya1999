/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include "Player.h"
#include "Board.h"
#include <string>

class Manager
{
	Player* firstPlayer;
	Player* seconedPlayer;
	Player* currentPlayer;
	Player* otherPlayer;
	Board* board;

	void changeTurn();//change the turn from the current player to the other player in the game

public:
	Manager(); //ctor
	~Manager(); //dctor
	int moveOnBoard(string move);//moving the player from source to dest
};

