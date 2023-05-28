/****************
Odelya Yakowich
207346784
*****************/

#pragma once

#include <vector>
#include "Piece.h"
using namespace std;

class Piece;
class King;

class Player
{
	King* kingPlayer;
	bool isWhitePlayer;
	bool playerIsGoingUp;
public:
	Player(bool isWhite):Player(isWhite, isWhite ? false : true) {}; //ctor
	Player(bool isWhite, bool isUp); //ctor
	~Player() {}; //d-ctor
	void setKing(King* myKing) { kingPlayer = myKing; };
	King* getKing() const { return kingPlayer; };
	bool isWhite() const { return isWhitePlayer; };
	bool isGoingUp() const { return playerIsGoingUp; };
};

