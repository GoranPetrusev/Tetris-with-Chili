/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    brd( gfx ),
    tID( 0,6 ),
    t( 5 ),
	rng( std::random_device()() )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if( inputCounter >= inputPeriod )
    {
        if( wnd.kbd.KeyIsPressed( VK_LEFT ) )
        {
            if( !t.CheckCollision( f,Location{ -1,0 },0 ) && (delayCounterL == 0 || delayCounterL >= delayPeriod) )
                t.Move( Location{ -1,0 } );
            delayCounterL++;
        }
        else
        {
            delayCounterL = 0;
        }

        if( wnd.kbd.KeyIsPressed( VK_RIGHT ) )
        {
            if( !t.CheckCollision( f,Location{ 1,0 },0 ) && (delayCounterR == 0 || delayCounterR >= delayPeriod) )
                t.Move( Location{ 1,0 } );
            delayCounterR++;
        }
        else
        {
            delayCounterR = 0;
        }


        if( wnd.kbd.KeyIsPressed( VK_DOWN ) )
        {
            if( !t.CheckCollision( f,Location{ 0,1 },0 ))
                t.Move( Location{ 0,1 } );
        }

        inputCounter = 0;
    }

    if( wnd.kbd.KeyIsPressed( 'Z' ) )
    {
        if( !lockRotation )
        {
            if( !t.CheckCollision( f,Location{ 0,0 },1 ) )
                t.Rotate();

            lockRotation = true;
        }
    }
    else
    {
        lockRotation = false;
    }

    if( tickCounter >= tickPeriod )
    {
        if( !t.CheckCollision( f,Location{ 0,1 },0 ) )
        {
            t.Fall();
        }
        else
        {
            for( int y = 0; y < 4; y++ )
            {
                for( int x = 0; x < 4; x++ )
                {
                    if( t.GetStateAt( x,y ) == 'X' )
                    {
                        char state = 54 - t.GetID();
                        f.PushPiece( t.GetX() - f.xOffset + x,t.GetY() - f.yOffset + y, state );
                    }
                }
            }
            f.OnFullLine();
            f.OnGameOver();
            t.Init( tID( rng ) );
        }

        tickCounter = 0;
    }

    inputCounter++;
    if( !fastDrop )
        tickCounter++;
}

void Game::ComposeFrame()
{
    f.DrawField( brd );
    t.Draw( brd );
}
