#include "Tetromino.h"

Tetromino::Tetromino( int in_ID )
{
	ID = in_ID;

	tetrominos[0].append( "..X." );
	tetrominos[0].append( "..X." );
	tetrominos[0].append( "..X." );
	tetrominos[0].append( "..X." );

	tetrominos[1].append( "...." );
	tetrominos[1].append( ".X.." );
	tetrominos[1].append( ".XXX" );
	tetrominos[1].append( "...." );

	tetrominos[2].append( "...." );
	tetrominos[2].append( "...X" );
	tetrominos[2].append( ".XXX" );
	tetrominos[2].append( "...." );

	tetrominos[3].append( "...." );
	tetrominos[3].append( ".XX." );
	tetrominos[3].append( ".XX." );
	tetrominos[3].append( "...." );

	tetrominos[4].append( "...." );
	tetrominos[4].append( "..XX" );
	tetrominos[4].append( ".XX." );
	tetrominos[4].append( "...." );

	tetrominos[5].append( "...." );
	tetrominos[5].append( "..X." );
	tetrominos[5].append( ".XXX" );
	tetrominos[5].append( "...." );

	tetrominos[6].append( "...." );
	tetrominos[6].append( ".XX." );
	tetrominos[6].append( "..XX" );
	tetrominos[6].append( "...." );
}

int Tetromino::Rotate( const int& r,int px,int py )
{
	switch( r % 4 )
	{
	case 0: return py * 4 + px;			// 0 degrees
	case 1: return 12 + py - (px * 4);	// 90 degrees
	case 2:	return 15 - (py * 4) - px;	// 180 degrees
	case 3: return 3 - py + (px * 4);	// 270 degrees
	}
	return 0;
}


void Tetromino::Draw( Board& brd )
{
	for( int y = 0; y < 4; y++ )
	{
		for( int x = 0; x < 4; x++ )
		{
			if( tetrominos[ID][Rotate( nCurrentRotation,x,y )] == 'X' )
			{
				Location loc = { x + xOffset, y + yOffset };
				Color c1( 88,133,181 );
				Color c2 = Colors::LightGray; // (133,181,88);
				brd.DrawCellBorder( loc,2,c1,c2 );
			}
		}
	}
}

char Tetromino::GetStateAt( int x,int y )
{
	return tetrominos[ID][Rotate( nCurrentRotation,x,y )];
}

int Tetromino::GetX()
{
	return xOffset;
}

int Tetromino::GetY()
{
	return yOffset;
}

int Tetromino::GetID()
{
	return ID;
}

void Tetromino::Init( int in_ID )
{
	ID = in_ID;
	xOffset = (Board::width - 4) / 2;
	yOffset = 3;
}

void Tetromino::Move( Location loc )
{
	xOffset += loc.x;
	yOffset += loc.y;
}

void Tetromino::Fall()
{
	yOffset++;
}

bool Tetromino::CheckCollision( Field& f,const Location delta_loc, const int delta_r )
{
	for( int y = 0; y < 4; y++ )
	{
		for( int x = 0; x < 4; x++ )
		{
			if( tetrominos[ID][Rotate( nCurrentRotation+delta_r,x,y )] == 'X' &&
			(	f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '#' ||
				f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '0' ||
				f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '1' ||
				f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '2' ||
				f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '3' ||
				f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '4' ||
				f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '5' ||
				f.GetStateAt( xOffset - f.xOffset + x + delta_loc.x,yOffset - f.yOffset + y + delta_loc.y ) == '6'
				) ) return true;
		}
	}
	return false;
}

void Tetromino::Rotate()
{
	nCurrentRotation++;
}
