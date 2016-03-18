// astares.framework.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "astares.framework.h"


// This is an example of an exported variable
ASTARESFRAMEWORK_API int nastaresframework=0;

// This is an example of an exported function.
ASTARESFRAMEWORK_API int fnastaresframework(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see astares.framework.h for the class definition
Castaresframework::Castaresframework()
{
	return;
}
