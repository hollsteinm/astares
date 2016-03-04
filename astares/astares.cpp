// astares.cpp : Defines the entry point for the console application.
//

#include<iostream>

#include "stdafx.h"
#include <SDL_main.h>
#include "math\test\MatrixTests.h"
#include "core\test\CoreTest.h"
#include "network\test\SocketTest.h"
#include "reflection\test\SerializationTests.h"
#include "log\test\LoggerTests.h"
#include "audio\test\AudioTests.h"
#include "input\test\InputTests.h"

int main(int, char**){
	test::matrix::Console();
	test::core::Console();
	test::serial::Console();
	test::network::Console();
	test::log::Console();
	test::audio::Console();
	test::input::Console();
	return 0;
}