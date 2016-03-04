#include "InputTests.h"
#include "../SDLInputSystem.h"
#include "../../core/Config.h"
#include "../../log/CommonLogger.h"
#include "../../core/System.h"
#include "../KeyEventMessage.h"
#include <SDL.h>

class SimpleAHandler : public AHandler < KeyEventMessage > {
public:
	SimpleAHandler(MessageHub& hub) : 
		AHandler<KeyEventMessage>(hub)
	{
	}
protected:
	virtual void InternalHandle(KeyEventMessage* message) {
		std::cout << *message << std::endl;
	}
};

void test::input::Console() {
	MessageHub hub;
	Config config("");
	CommonLogger logger;

	SimpleAHandler handler(hub);

	Array<ISubsystem*> systems;
	systems.push_back( new SDLInputSystem(hub));

	System system(&logger, systems);
	
	config.Parse("(Input)[A=TestKeyPressed]");

	system.Configure(config);

	//need to do this to test input
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
		return;
	}
	else {
		SDL_Window* window = SDL_CreateWindow("Test Input Window", 
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 
			192, 108, 
			SDL_WINDOW_SHOWN);
		
	}

	if (system.Initialize()) {
		while (system.Run()) {

		}
		system.Shutdown();
	}
}