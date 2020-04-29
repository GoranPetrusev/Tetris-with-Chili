#include <assert.h>
#include "Board.h"

Board::Board( Graphics& gfx )
	:
	gfx( gfx )
{
}

void Board::DrawCell( const Location& loc,Color c )
{
	assert( loc.x < width );
	assert( loc.x >= 0 );
	assert( loc.y < height );
	assert( loc.y >= 0 );
	gfx.DrawRectDim( loc.x * dimension,loc.y * dimension,dimension,dimension,c );
}

void Board::DrawCellBorder( const Location& loc,int bWidth,Color cSolid,Color cBorder )
{
	assert( loc.x < width );
	assert( loc.x >= 0 );
	assert( loc.y < height );
	assert( loc.y >= 0 );
	gfx.DrawRectDim( loc.x * dimension,loc.y * dimension,dimension,dimension,cBorder );
	gfx.DrawRectDim( (loc.x * dimension) + bWidth,(loc.y * dimension) + bWidth,
		dimension - bWidth * 2,dimension - bWidth * 2,cSolid );
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}
