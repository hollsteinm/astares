#include "SDLWAVAudioSystem.h"
#include "../core/Config.h"
#include "../core/AssetManager.h"
#include "../log/ILogger.h"
#include "AudioAsset.h"
#include <SDL_mixer.h>

#define AUDIO_CHANNEL_SETTING "Channels"
#define AUDIO_SECTION "Audio"
#define AUDIO_TYPES 0


SDLWAVAudioSystem::SDLWAVAudioSystem(AssetManager* assetManager) :
	Channels(MIX_DEFAULT_CHANNELS),
	DeviceName("Unknown"),
	Manager(assetManager)
{
}

SDLWAVAudioSystem::~SDLWAVAudioSystem() {
	Channels = MIX_DEFAULT_CHANNELS;
	DeviceName = "Unknown";
	AllAudioDevices.clear();
	Shutdown();
}

AudioAsset* SDLWAVAudioSystem::AddAsset(long typeId, std::string filename) {
	AudioAsset* result = (AudioAsset*)Manager->LoadExternalContent(typeId, "Audio/" + filename);
	if (result != nullptr) {
		return result;
	}
	else {
		return nullptr;
	}
}

void SDLWAVAudioSystem::RemoveAsset(long id) {
}
	 
void SDLWAVAudioSystem::PlayAudio(long audioId) {
	AudioAsset* asset = (AudioAsset*)Manager->Get(audioId);

	const long mtId = TYPEOF(MusicAudioAsset);
	const long ctId = TYPEOF(SFXAudioAsset);

	if (asset != nullptr) {
		if (asset->GetTypeId() == mtId) {
			if (Mix_PlayingMusic() != 0) {
				Mix_HaltMusic();
			}
			MusicAudioAsset* mAsset = (MusicAudioAsset*)asset;
			if (mAsset->Data != nullptr) {
				Mix_PlayMusic(mAsset->Data, mAsset->Loops ? mAsset->LoopCount : 0);
			}
		}
		else if (asset->GetTypeId() == ctId) {
			SFXAudioAsset* sfx = (SFXAudioAsset*)asset;
			if (sfx->Data != nullptr) {
				Mix_PlayChannel(-1, sfx->Data, sfx->Loops ? sfx->LoopCount : 0);
			}
		}
	}
}

void SDLWAVAudioSystem::StopAudio(long audioId) {
	AudioAsset* asset = (AudioAsset*)Manager->Get(audioId);
	if (asset != nullptr) {
		if (asset->GetTypeId() == TYPEOF(MusicAudioAsset)) {
			if (Mix_PlayingMusic() != 0) {
				Mix_HaltMusic();
			}
		}
	}
}

void SDLWAVAudioSystem::PauseAudio(long audioId) {
	AudioAsset* asset = (AudioAsset*)Manager->Get(audioId);
	if (asset != nullptr) {
		if (asset->GetTypeId() == TYPEOF(MusicAudioAsset)) {
			if (Mix_PlayingMusic() != 0){
				if (Mix_PausedMusic() == 0){
					Mix_PauseMusic();
				}
			}
		}
	}
}

void SDLWAVAudioSystem::ResumeAudio(long audioId) {
	AudioAsset* asset = (AudioAsset*)Manager->Get(audioId);
	if (asset != nullptr) {
		if (asset->GetTypeId() == TYPEOF(MusicAudioAsset)) {
			if (Mix_PausedMusic() == 1){
				Mix_ResumeMusic();
			}
		}
	}
}

std::string SDLWAVAudioSystem::GetName() const {
	return "SDLWAVAudioSystem";
}

void SDLWAVAudioSystem::Configure(const Config& config) {
	if (config.HasSection(AUDIO_SECTION)) {
		if (config.HasSetting(AUDIO_CHANNEL_SETTING)) {
			Channels = (char)config.Int(AUDIO_CHANNEL_SETTING);
		}
	}
}



bool SDLWAVAudioSystem::Initialize(ILogger* logger) {
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, Channels, 2048) < 0) {
		if (logger != nullptr) {
			logger->Error("%s", Mix_GetError());
		}
		return false;
	}
	else {
		int length = SDL_GetNumAudioDevices(AUDIO_TYPES);
		if (length > 0) {
			for (int i = 0; i < length; ++i) {
				const char* name = SDL_GetAudioDeviceName(i, AUDIO_TYPES);
				if (name != nullptr) {
					AllAudioDevices.push_back(std::string(name, strlen(name)));
					if (logger != nullptr) {
						logger->Info("Found %s audio device.", name);
					}
				}
			}
		}
		DeviceName = AllAudioDevices.size() > 0 ? AllAudioDevices[0] : "Unknown";
		if (logger != nullptr) {
			logger->Info("New audio device in use: %s", DeviceName.c_str());
		}
		return true;
	}
}

bool SDLWAVAudioSystem::Run() {
	return true;
}

void SDLWAVAudioSystem::Shutdown() {
	Mix_CloseAudio();
}