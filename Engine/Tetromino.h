#pragma once

#include "Board.h"
#include "Location.h"
#include "Field.h"

class Tetromino
{
public:
	Tetromino( int in_ID );
	void Init( int in_ID );
	void Move( Location loc );
	void Fall();
	bool CheckCollision( Field& f, const Location delta_loc, const int delta_r  );
	void Rotate();
	void Draw( Board& brd );
	char GetStateAt( int x,int y );
	int GetX();
	int GetY();
	int GetID();
private:
	int Rotate( const int& r,int x,int y );
	int xOffset = (Board::width-4) / 2;
	int yOffset = 3;
	std::string tetrominos[7];
	int ID;
	int nCurrentRotation = 0;
};