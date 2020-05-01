#pragma once

#include "Location.h"
#include "Graphics.h"
#include "Keyboard.h"

class Board
{
public:
	class Tetromino
	{
	public:
		Tetromino();
		void Init( int in_ID );
		void Fall();
		void Rotate( Keyboard& kbd );
		void Move( Keyboard& kbd );
		void DrawCube( Location& loc,Color c,Graphics& gfx );
		bool MoveAvaliable( Board& brd, Location& delta_loc, int delta_rot );
	private:
		int RotatedMatrix( Location& loc,int r );
		int ID;
		int CurrenRotation = 0;
		Location loc = { 5,2 };
		static constexpr int dimensions = 20;
		std::string tetrominos[7];
	};

	// Constructor
	Board();

	// Functions
	void Draw( Graphics& gfx );

private:
	static constexpr int width = 10;
	static constexpr int height = 20;
	char* pBoard = new char[width * height];
	Tetromino& t;
};