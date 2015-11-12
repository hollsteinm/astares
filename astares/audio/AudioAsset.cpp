#include <SDL_mixer.h>
#include "AudioAsset.h"

AudioAsset::AudioAsset() :
	Loops(false),
	LoopCount(0),
	Volume(MIX_MAX_VOLUME),
	Filename("None")
{
	CTOR_REGISTER(AudioAsset)
}

AudioAsset::~AudioAsset() {

}

REFLECTION_BEGIN(AudioAsset)
	PARENT(Asset)
	PROPERTY(int, Volume)
	PROPERTY(bool, Loops)
	PROPERTY(int, LoopCount)
	PROPERTY(String, Filename)
REFLECTION_END(AudioAsset)

MusicAudioAsset::MusicAudioAsset() :
	Data(nullptr)
{
	CTOR_REGISTER(MusicAudioAsset)
}

MusicAudioAsset::~MusicAudioAsset() {
	Mix_FreeMusic(Data);
}

REFLECTION_BEGIN(MusicAudioAsset)
	PARENT(AudioAsset)
REFLECTION_END(MusicAudioAsset)

SFXAudioAsset::SFXAudioAsset() :
	Data(nullptr)
{
	CTOR_REGISTER(SFXAudioAsset)
}

SFXAudioAsset::~SFXAudioAsset() {
	Mix_FreeChunk(Data);
}

void AudioAsset::PostDeserialize(std::istream& in) {
	ImportFromFile(Filename);
}


REFLECTION_BEGIN(SFXAudioAsset)
	PARENT(AudioAsset)
REFLECTION_END(SFXAudioAsset)

bool MusicAudioAsset::ImportFromFile(std::string filename) {
	Mix_FreeMusic(Data);
	Data = nullptr;
	Filename = filename;
	Data = Mix_LoadMUS(filename.c_str());
	return Data != nullptr;
}

bool SFXAudioAsset::ImportFromFile(std::string filename) {
	Mix_FreeChunk(Data);
	Data = nullptr;
	Filename = filename;
	Data = Mix_LoadWAV(filename.c_str());
	if (Data != nullptr) {
		Data->volume = Volume;
	}
	return Data != nullptr;
}