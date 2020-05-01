#include "Board.h"

Board::Board()
{
	for( int x = 0; x < width; x++ )
		for( int y = 0; y < height; y++ )
			pBoard[y * width + x] = ' ';
}

void Board::Draw( Graphics& gfx )
{
	for( int x = 0; x < width; x++ )
		for( int y = 0; y < height; y++ )
			t.DrawCube( Location{ x,y },Colors::Red,gfx );

	t.DrawTetromino( gfx );
}

void Board::DynamicUpdate( Keyboard& kbd )
{
	t.Move( kbd,*this );
	t.Rotate( kbd,*this );
}
