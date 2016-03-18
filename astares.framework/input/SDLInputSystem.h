#ifndef SDL_INPUT_SYSTEM_H
#define SDL_INPUT_SYSTEM_H

#include "IInputSystem.h"
#include <map>

class SDLInputSystem : public IInputSystem {

public:
	SDLInputSystem(std::shared_ptr<class MessageHub> hub);

	void AddMapping(int32 key, std::string name) override;
	void ConsumeKey(int32 key, KeyState state) override;

	std::string GetName() const override;

	void Configure(class Config& config) override;
	bool Initialize(ILogger* logger) override;
	bool Run() override;
	void Shutdown() override;

private:
	struct KeyProxy {
		string Mapping;
		KeyState state;

		KeyProxy(string name)
			: Mapping(name),
			state(KeyState::Released)
		{

		}

		KeyProxy()
			: Mapping(),
			state(KeyState::Released)
		{}
	};

	std::map<int32, KeyProxy> Keymap;
	std::shared_ptr<class MessageHub> inputHub;
};

#endif