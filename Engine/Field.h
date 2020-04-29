#pragma once

#include "Board.h"
#include "Location.h"

class Field
{
public:
	Field();
	void DrawField( Board& brd );
	char GetStateAt( int x,int y );
	void PushPiece( int x,int y,char state );
	void OnFullLine();
	void OnGameOver();
public:
	static constexpr int width = 12;
	static constexpr int height = 21;
	static constexpr int xOffset = (Board::width - 12) / 2;
	static constexpr int yOffset = 5;
private:
	static constexpr int size = width * height;
	char* pField = new char[size];
};