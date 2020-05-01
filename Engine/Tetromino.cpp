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
	pos.y++;
}

void Board::Tetromino::Rotate( Keyboard& kbd,Board& brd )
{
	if( kbd.KeyIsPressed( 'Z' ) && ID != 3 )
	{
		if( DoesPieceFit( brd,Location{ 0,0 },1 ) )
			nCurrentRotation++;
	}
	if( kbd.KeyIsPressed( 'X' ) && ID != 3 )
	{
		if( DoesPieceFit( brd,Location{ 0,0 },-1 ) )
		{
			if( nCurrentRotation == 0 )
				nCurrentRotation = 3;
			else
				nCurrentRotation--;
		}
	}
}

void Board::Tetromino::Move( Keyboard& kbd,Board& brd )
{
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		if( DoesPieceFit( brd,Location{ -1,0 },0 ) )
			pos.x--;
	}
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		if( DoesPieceFit( brd,Location{ 1,0 },0 ) )
			pos.x++;
	}
}

void Board::Tetromino::DrawCube( Location& loc,Color c,Graphics& gfx )
{
	gfx.DrawRectDim( loc.x*dimensions,loc.y*dimensions,dimensions,dimensions,c );
}

void Board::Tetromino::DrawTetromino( Graphics& gfx )
{
	for( int x = 0; x < 5; x++ )
		for( int y = 0; y < 5; y++ )
			if( tetrominos[ID][y * 5 + x] == 'O' )
				DrawCube( Location{ x + pos.x,y + pos.y },Colors::Blue,gfx );

}

bool Board::Tetromino::DoesPieceFit( Board& brd,Location& delta_loc,int delta_rot )
{
	for( int x = 0; x < 5; x++ )
	{
		for( int y = 0; y < 5; y++ )
		{
			// Index into piece
			int pi = RotatedMatrix( Location{ x,y },nCurrentRotation - delta_rot );

			// Index into board
			int fi = (y + pos.y + delta_loc.y) * width + (x + pos.x + delta_loc.x);

			if( x + delta_loc.x >= 0 && x + delta_loc.x < width )
			{
				if( y + delta_loc.y >= 0 && y + delta_loc.y < height )
				{
					if( brd.pBoard[fi] != ' ' && tetrominos[ID][pi] == 'O' )
						return true;
				}
			}
		}
	}

	return false;
}

int Board::Tetromino::RotatedMatrix( Location& index,int r )
{
	switch( r % 4 )
	{
	case 0: return pos.y * 4 + pos.x;			// 0 degrees
	case 1: return 12 + pos.y - (pos.x * 4);	// 90 degrees
	case 2:	return 15 - (pos.y * 4) - pos.x;	// 180 degrees
	case 3: return 3 - pos.y + (pos.x * 4);		// 270 degrees
	}
	return 0;
}
