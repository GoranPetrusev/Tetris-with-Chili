#include "Board.h"

void Board::Tetromino::DrawCube( Location& loc,Color c,Graphics& gfx )
{
	gfx.DrawRectDim( loc.x*dimensions,loc.y*dimensions,dimensions,dimensions,c );
}
