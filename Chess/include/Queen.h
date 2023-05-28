/****************
Odelya Yakowich
207346784
*****************/

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Player* myPlayer, int myRow, int myCol, Board* myBoard) : Piece(myPlayer, 'q', myRow, myCol, myBoard) {};//ctor
	virtual bool isLegalMove(int myRowDst, int myColDst) const;
};