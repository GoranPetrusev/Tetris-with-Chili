#include "Field.h"

Field::Field()
{
	for( int y = 0; y < height; y++ )
		for( int x = 0; x < width; x++ )
			pField[y * width + x] = (x == 0 || x == width - 1 || y == height - 1)?'#':' ';
}

void Field::DrawField( Board& brd )
{
	for( int y = 0; y < height; y++ )
	{
		for( int x = 0; x < width; x++ )
		{
			switch( pField[y * width + x] )
			{
			case '#': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			case '0': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			case '1': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			case '2': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			case '3': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			case '4': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			case '5': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			case '6': {
				Location loc = { x + xOffset,y + yOffset };
				Color c = Colors::LightGray;
				brd.DrawCell( loc,c );
				break;
			}
			default: {
				Location loc = { x + xOffset,y + yOffset };
				Color c1(40,40,40);
				Color c2 = Colors::Black;
				brd.DrawCellBorder( loc,1,c1,c2 );
				break;
			}

			}
		}
	}
}

char Field::GetStateAt( int x,int y )
{
	return pField[y * width + x];
}

void Field::PushPiece( int x,int y,char state )
{
	pField[y * width + x] = state;
}

void Field::OnFullLine()
{
	bool exit = false;
	for( int y = 0; y < height-1; y++ )
	{
		for( int x = 1; x < width; x++ )
		{
			if( pField[y * width + x] == ' ' )
			{
				break;
			}
			else if( x == width - 1 )
			{
				for( int ym = y; ym > 0; ym-- )
				{
					for( int xm = 1; xm < width; xm++ )
					{
						pField[ym * width + xm] = pField[(ym - 1) * width + xm];
					}
				}
			}
		}
	}
}

void Field::OnGameOver()
{
	int piecesOnTop = 0;
	for( int x = 1; x < width; x++ )
	{
		if( pField[x] != ' ' ) piecesOnTop++;
	}

	if( piecesOnTop >= 2 )
	{
		for( int y = 0; y < height; y++ )
			for( int x = 0; x < width; x++ )
				pField[y * width + x] = (x == 0 || x == width - 1 || y == height - 1)?'#':' ';
	}
}
