#include "Board.h"

Board::Tetromino::Tetromino()
{
	tetrominos[0].append( "....." );
	tetrominos[0].append( "....." );
	tetrominos[0].append( "..OO." );
	tetrominos[0].append( ".OO.." );
	tetrominos[0].append( "....." );

	tetrominos[1].append( "....." );
	tetrominos[1].append( "....." );
	tetrominos[1].append( ".OO.." );
	tetrominos[1].append( "..OO." );
	tetrominos[1].append( "....." );

	tetrominos[2].append( "....." );
	tetrominos[2].append( "....." );
	tetrominos[2].append( "OOOO." );
	tetrominos[2].append( "....." );
	tetrominos[2].append( "....." );

	tetrominos[3].append( "....." );
	tetrominos[3].append( "....." );
	tetrominos[3].append( ".OO.." );
	tetrominos[3].append( ".OO.." );
	tetrominos[3].append( "....." );

	tetrominos[4].append( "....." );
	tetrominos[4].append( "....." );
	tetrominos[4].append( ".OOO." );
	tetrominos[4].append( "...O." );
	tetrominos[4].append( "....." );

	tetrominos[5].append( "....." );
	tetrominos[5].append( "....." );
	tetrominos[5].append( ".OOO." );
	tetrominos[5].append( ".O..." );
	tetrominos[5].append( "....." );

	tetrominos[6].append( "....." );
	tetrominos[6].append( "....." );
	tetrominos[6].append( ".OOO." );
	tetrominos[6].append( "..O.." );
	tetrominos[6].append( "....." );
}

void Board::Tetromino::Init( int in_ID )
{
	ID = in_ID;
}

void Board::Tetromino::Fall()
{
	loc.y--;
}

void Board::Tetromino::Rotate( Keyboard& kbd )
{
	if( kbd.KeyIsPressed( 'Z' ) && ID != 3 )
	{
		// check if avaliable
		// rotate counter clockwise
	}
	if( kbd.KeyIsPressed( 'X' ) && ID != 3 )
	{
		// check if avaliable
		// rotate clockwise
	}
}

void Board::Tetromino::Move( Keyboard& kbd )
{
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		// check if avaliable
		// move left
	}
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		// check if avaliable
		// move right
	}
}

void Board::Tetromino::DrawCube( Location& loc,Color c,Graphics& gfx )
{
	gfx.DrawRectDim( loc.x*dimensions,loc.y*dimensions,dimensions,dimensions,c );
}
