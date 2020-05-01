#pragma once

#include "Location.h"
#include "Graphics.h"
#include "Keyboard.h"

class Board
{
private:
	class Tetromino
	{
	public:
		Tetromino();
		void Init( int in_ID );
		void Fall();
		void Rotate( Keyboard& kbd,Board& brd );
		void Move( Keyboard& kbd,Board& brd );
		void DrawCube( Location& loc,Color c,Graphics& gfx );
		void DrawTetromino( Graphics& gfx );
	private:
		bool DoesPieceFit( Board& brd,Location& delta_loc,int delta_rot );
		int RotatedMatrix( Location& index,int r );
		int ID = 0;
		int nCurrentRotation = 0;
		Location pos = { 5,5 };
		static constexpr int dimensions = 20;
		std::string tetrominos[7];
	};

public:
	// Constructor
	Board();

	// Functions
	void Draw( Graphics& gfx );
	void DynamicUpdate( Keyboard& kbd,Board& brd );
	void FixedUpdate( Keyboard& kbd,Board& brd );

private:
	static constexpr int width = 10;
	static constexpr int height = 20;
	char* pBoard = new char[width * height];
	Tetromino& t;

	// Timers
	static constexpr int nUpdatePeriod = 20;
	int nTimer = 0;
};