#pragma once

#include "Board.h"
#include "Location.h"

class Interface
{
public:
	Interface();
private:
	static constexpr int size = Board::width* Board::height;
	char pInterface[size];
};