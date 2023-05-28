/****************
Odelya Yakowich
207346784
*****************/


#include "Chess.h"
#include "Manager.h"


/*
codeResponse value :
Illegal movements :
11 - there is not piece at the source
12 - the piece in the source is piece of your opponent
13 - there one of your pieces at the destination
21 - illegal movement of that piece
31 - this movement will cause you checkmate

legal movements :
41 - the last movement was legal and cause check
42 - the last movement was legal, next turn
*/

int main()
{
	string myBoard = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
	Chess chessboard(myBoard);
	Manager* gameManager = new Manager();
	int codeGame = 0;
	
	string inputPlayer = chessboard.getInput();

	while (inputPlayer != "exit")
	{
		codeGame = gameManager->moveOnBoard(inputPlayer);
		chessboard.setCodeGame(codeGame);
		inputPlayer = chessboard.getInput();
	}

	cout << endl << "Exit from program " << endl; 
	return 0;
}