#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board( Graphics& gfx );
	void DrawCell( const Location& loc,Color c );
	void DrawCellBorder( const Location& loc,int bWidth,Color cSolid,Color cBorder );
	int GetWidth() const;
	int GetHeight() const;
public:
	static constexpr int width = 39;
	static constexpr int height = 30;
private:
	static constexpr int dimension = 20;
	Graphics& gfx;
};
