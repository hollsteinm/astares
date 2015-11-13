#include "CoreTest.h"

#include "../ObjectFactory.h"
#include "../../log/CommonLogger.h"
#include "../../reflection/TypeGraph.h"
#include "../Config.h"
#include "../System.h"
#include "../ISubsystem.h"
#include "../String.h"
#include "../../audio/SDLWAVAudioSystem.h"
#include <iostream>
#include <sstream>

void test::core::Console() {
	ILogger* logger = new CommonLogger();
	String content = "(Section0) garbage [Char=k Float=45.67 bool=false]   (Section9)\r\r\n[somthing=this]";

	Config cfg("");
	cfg.Parse(content);

	std::cout << ObjectFactory::Get().ToString() << std::endl;
	std::cout << std::endl << TypeGraph::Get().ToString() << std::endl;

	delete logger;

	String s = "This is a test with spaces for encoding spaces and it will always write out encoded";

	std::cout << s << std::endl;

	std::stringstream ss("This%20is%20a%20test%20with%20spaces%20for%20encoding%20spaces%20and%20it%20will%20always%20write%20out%20encoded");

	ss >> s;
}