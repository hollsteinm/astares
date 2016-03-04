#ifndef SDL_INPUT_SYSTEM_H
#define SDL_INPUT_SYSTEM_H

#include "IInputSystem.h"
#include <map>
#include "../messaging/MessageHub.h"
#include "../messaging/AHandler.h"

class SDLInputSystem : public IInputSystem {

public:
	SDLInputSystem(MessageHub& hub);

	void AddMapping(int key, String name) override;
	void ConsumeKey(int key, KeyState state) override;

	String GetName() const override;

	void Configure(class Config& config) override;
	bool Initialize(ILogger* logger) override;
	bool Run() override;
	void Shutdown() override;

private:
	struct KeyProxy {
		String Mapping;
		KeyState state;
	};

	std::map<int, KeyProxy> Keymap;
	MessageHub* inputHub;
};

#endif