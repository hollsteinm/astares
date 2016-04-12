#include "SDLWAVAudioSystem.h"
#include <core/Config.h>
#include <log/ILogger.h>
#include "AudioAsset.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <core/File.h>

#define AUDIO_CHANNEL_SETTING "Channels"
#define AUDIO_SECTION "Audio"
#define AUDIO_PATH "Audio/"
#define AUDIO_TYPES 0


SDLWAVAudioSystem::SDLWAVAudioSystem() :
Channels(MIX_DEFAULT_CHANNELS),
DeviceName("Unknown"),
audioObjects()
{
}

SDLWAVAudioSystem::~SDLWAVAudioSystem() {
	Channels = MIX_DEFAULT_CHANNELS;
	DeviceName = "Unknown";
	AllAudioDevices.clear();
	Shutdown();
}

bool SDLWAVAudioSystem::Supported(string filename){
	auto pos = filename.find_last_of('.');
	if (pos != string::npos) {
		return filename.substr(pos, filename.size()) == ".wav";
	}
	else
	{
		return false;
	}
}

int64 SDLWAVAudioSystem::AddAsset(string filename) {
	AudioAsset asset;
	asset.Name = filename;
	string contents;
	if (File::Read(filename, contents)) {
		asset.rawData.reserve(contents.size());
		for (auto c : contents) {
			asset.rawData.push_back((uint8)c);
		}
		audioObjects[asset.GetInstanceId().GetValue()] = asset;
		return asset.GetInstanceId().GetValue();
	}
	else
	{
		return -1;
	}
}

void SDLWAVAudioSystem::RemoveAsset(int64 id) {
	audioObjects.erase(id);
}

void SDLWAVAudioSystem::PlayAudio(int64 audioId) {
	if (Exists(audioId)) {
		auto obj = audioObjects[audioId];

		if (obj.rawData.size() > 0) {

			switch (obj.Type._value)
			{
			case SoundType::SFX:
				if (!LoadedChunk(audioId)) {
					auto memoryBuffer = SDL_RWFromMem(obj.rawData.data(), obj.rawData.size());
					if (memoryBuffer != nullptr) {
						std::shared_ptr<Mix_Chunk> mixData(Mix_LoadWAV_RW(memoryBuffer, 1), Mix_FreeChunk);
						if (mixData) {
							LoadedChunks.emplace(std::make_pair(audioId, mixData));
						}
					}
				}
				Mix_PlayChannel(-1, LoadedChunks[audioId].get(), obj.Loops ? obj.LoopCount : 1);
				break;
			case SoundType::Music:
				if (Mix_PlayingMusic() != 0) {
					Mix_HaltMusic();
				}
				if (!LoadedMusic(audioId)) {
					auto memoryBuffer = SDL_RWFromMem(obj.rawData.data(), obj.rawData.size());
					if (memoryBuffer != nullptr) {
						std::shared_ptr<Mix_Music> musicData(Mix_LoadMUS_RW(memoryBuffer, 1), Mix_FreeMusic);
						if (musicData) {
							LoadedMusics.emplace(std::make_pair(audioId, musicData));
						}
					}
				}

				Mix_PlayMusic(LoadedMusics[audioId].get(), obj.Loops ? obj.LoopCount : 1);
				break;
			default:
				break;
			}
		}
	}
}

void SDLWAVAudioSystem::StopAudio(int64 audioId) {
	if (Exists(audioId)) {
		auto obj = audioObjects[audioId];
		switch (obj.Type._value) {
		case SoundType::Music:
			if (Mix_PlayingMusic() != 0) {
				Mix_HaltMusic();
			}
			break;
		case SoundType::SFX:
		default:
			break;
		}
	}
}

void SDLWAVAudioSystem::PauseAudio(int64 audioId) {
	if (Exists(audioId)) {
		auto obj = audioObjects[audioId];
		switch (obj.Type._value) {
		case SoundType::Music:
			if (Mix_PlayingMusic() != 0){
				if (Mix_PausedMusic() == 0){
					Mix_PauseMusic();
				}
			}
			break;
		case SoundType::SFX:
		default:
			break;
		}
	}
}

void SDLWAVAudioSystem::ResumeAudio(int64 audioId) {
	if (Exists(audioId)) {
		auto obj = audioObjects[audioId];
		switch (obj.Type._value) {
		case SoundType::Music:
			if (Mix_PausedMusic() == 1){
				Mix_ResumeMusic();
			}
			break;
		case SoundType::SFX:
		default:
			break;
		}
	}
}

string SDLWAVAudioSystem::GetName() const {
	return "SDLWAVAudioSystem";
}

void SDLWAVAudioSystem::Configure(Config& config) {
	if (config.HasSection(AUDIO_SECTION)) {
		if (config.HasSetting(AUDIO_CHANNEL_SETTING)) {
			Channels = (int8)config.AsInt(AUDIO_CHANNEL_SETTING);
		}
	}
}

bool SDLWAVAudioSystem::Initialize(std::shared_ptr<ILogger> logger) {
	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
		if (logger != nullptr) {
			logger->Error("Could not initialize audio: %s", SDL_GetError());
		}
	}

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, Channels, 2048) < 0) {
		if (logger != nullptr) {
			logger->Error("%s", Mix_GetError());
		}
		return false;
	}
	else {
		int32 length = SDL_GetNumAudioDevices(AUDIO_TYPES);
		for (int32 i = 0; i < length; ++i) {
			auto name = SDL_GetAudioDeviceName(i, AUDIO_TYPES);
			if (name != nullptr) {
				AllAudioDevices.push_back(string(name, strlen(name)));
				if (logger != nullptr) {
					logger->Info("Found %s audio device.", name);
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

void SDLWAVAudioSystem::UpdateVolume(int64 id, float volume) {
	if (Exists(id)) {
		audioObjects[id].Volume = (int32)((int64)volume);
	}
}

void SDLWAVAudioSystem::UpdateLooping(int64 id, int32 loopcount) {
	if (Exists(id)) {
		audioObjects[id].LoopCount = loopcount;
		audioObjects[id].Loops = loopcount != 0;
	}
}

void SDLWAVAudioSystem::UpdateSoundsType(int64 id, SoundType type) {
	if (Exists(id)) {
		audioObjects[id].Type = type;
	}
}

void SDLWAVAudioSystem::UpdateLength(int64 id, float length) {
	if (Exists(id)) {
		audioObjects[id].Length = (int32)((int64)length);
	}
}

void SDLWAVAudioSystem::UpdateChannel(int64 id, int8 channel) {
	if (Exists(id)) {
		audioObjects[id].Channel = channel;
	}

}

gate SDLWAVAudioSystem::Exists(int64 id) const {
	return audioObjects.find(id) != audioObjects.cend();
}

gate SDLWAVAudioSystem::LoadedChunk(int64 id) const {
	return LoadedChunks.find(id) != LoadedChunks.cend();
}

gate SDLWAVAudioSystem::LoadedMusic(int64 id) const {
	return LoadedMusics.find(id) != LoadedMusics.cend();
}