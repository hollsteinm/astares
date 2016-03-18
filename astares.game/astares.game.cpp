// astares.game.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "astares.game.h"


// This is an example of an exported variable
ASTARESGAME_API int nastaresgame=0;

// This is an example of an exported function.
ASTARESGAME_API int fnastaresgame(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see astares.game.h for the class definition
Castaresgame::Castaresgame()
{
	return;
}
