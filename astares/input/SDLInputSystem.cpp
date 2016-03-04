#include "SDLInputSystem.h"
#include "KeyEventMessage.h"
#include <map>
#include <SDL.h>
#include "../core/Config.h"
#include "../log/ILogger.h"

#define MAP_KEYCODE(code) {SDL_GetKeyName(code), code}

#define KEY_MAP_SECTION "Input"

static const std::map<String, int> KeyCodeMap{
	MAP_KEYCODE(SDLK_0),
	MAP_KEYCODE(SDLK_1),
	MAP_KEYCODE(SDLK_2),
	MAP_KEYCODE(SDLK_3),
	MAP_KEYCODE(SDLK_4),
	MAP_KEYCODE(SDLK_5),
	MAP_KEYCODE(SDLK_6),
	MAP_KEYCODE(SDLK_7),
	MAP_KEYCODE(SDLK_8),
	MAP_KEYCODE(SDLK_9),
	MAP_KEYCODE(SDLK_a),
	MAP_KEYCODE(SDLK_b),
	MAP_KEYCODE(SDLK_c),
	MAP_KEYCODE(SDLK_d),
	MAP_KEYCODE(SDLK_e),
	MAP_KEYCODE(SDLK_f),
	MAP_KEYCODE(SDLK_g),
	MAP_KEYCODE(SDLK_h),
	MAP_KEYCODE(SDLK_i),
	MAP_KEYCODE(SDLK_j),
	MAP_KEYCODE(SDLK_k),
	MAP_KEYCODE(SDLK_l),
	MAP_KEYCODE(SDLK_m),
	MAP_KEYCODE(SDLK_n),
	MAP_KEYCODE(SDLK_o),
	MAP_KEYCODE(SDLK_p),
	MAP_KEYCODE(SDLK_q),
	MAP_KEYCODE(SDLK_r),
	MAP_KEYCODE(SDLK_s),
	MAP_KEYCODE(SDLK_t),
	MAP_KEYCODE(SDLK_u),
	MAP_KEYCODE(SDLK_v),
	MAP_KEYCODE(SDLK_w),
	MAP_KEYCODE(SDLK_x),
	MAP_KEYCODE(SDLK_y),
	MAP_KEYCODE(SDLK_z)
};

SDLInputSystem::SDLInputSystem(MessageHub& hub) {
	inputHub = &hub;
}

void SDLInputSystem::AddMapping(int key, String name) {
	if (Keymap.find(key) == Keymap.cend()) {
		Keymap[key] = KeyProxy{ name, KeyState::Released };
	}
}

void SDLInputSystem::ConsumeKey(int key, KeyState state) {
	if (Keymap.find(key) != Keymap.cend()) {
		KeyProxy prox = Keymap[key];
		bool changed = false;

		switch (prox.state)
		{
		case KeyState::Pressed:
			if (state == KeyState::Pressed) {
				prox.state = KeyState::Held;
				changed = true;
			}
			break;
		default:
			if (prox.state != state) {
				prox.state = state;
				changed = true;
			}
			break;
		}

		if (changed) {
			inputHub->Publish(new KeyEventMessage(prox.Mapping, prox.state));
		}
	}
}

String SDLInputSystem::GetName() const {
	return "SDLInput";
}

void SDLInputSystem::Configure(class Config& config) {
	if (config.HasSection(KEY_MAP_SECTION)){
		config.MoveSection(KEY_MAP_SECTION);

		for (auto kvp : KeyCodeMap) {
			if (config.HasSetting(kvp.first)){
				int key = kvp.second;
				String name = config.AsString(kvp.first);
				Keymap[key] = { name, KeyState::Released };
			}
		}

	}
}

bool SDLInputSystem::Initialize(struct ILogger* logger) {
	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0) {
		if (logger != nullptr) {
			logger->Error("Failed to initailize event system: %s", SDL_GetError());
		}
		return false;
	}
	else {
		return true;
	}
}

bool SDLInputSystem::Run() {
	bool stillRunning = true;
	SDL_Event evt;
	while (SDL_PollEvent(&evt)) {
		if (evt.type == SDL_EventType::SDL_QUIT) {
			stillRunning = false;
		}
		else if (evt.type == SDL_EventType::SDL_KEYDOWN || evt.type == SDL_EventType::SDL_KEYUP) {
			SDL_KeyboardEvent keyEvent = evt.key;
			ConsumeKey(keyEvent.keysym.sym, keyEvent.state == SDL_KEYDOWN ? KeyState::Pressed : KeyState::Released);
		}
	}
	return stillRunning;
}

void SDLInputSystem::Shutdown() {

}