#ifndef SDLWAV_AUDIO_SYSTEM_H
#define SDLWAV_AUDIO_SYSTEM_H

#include "IAudioSystem.h"

class ASTARESCORE_API Config;
class ASTARESCORE_API ILogger;

class ASTARESFRAMEWORK_API SDLWAVAudioSystem : public IAudioSystem {
public:
	SDLWAVAudioSystem();
	~SDLWAVAudioSystem();

	virtual bool Supported(string filename) override;

	virtual int64 AddAsset(string filename) override;
	virtual void RemoveAsset(int64 id) override;

	virtual void PlayAudio(int64 audioId) override;
	virtual void StopAudio(int64 audioId) override;
	virtual void PauseAudio(int64 audioId) override;
	virtual void ResumeAudio(int64 audioId) override;

	virtual string GetName() const override;

	virtual void Configure(Config& config) override;
	virtual bool Initialize(std::shared_ptr<ILogger> logger) override;
	virtual bool Run() override;
	virtual void Shutdown() override;

	virtual void UpdateVolume(int64 id, float volume) override;
	virtual void UpdateLooping(int64 id, int32 loopcount) override;
	virtual void UpdateSoundsType(int64 id, SoundType type) override;
	virtual void UpdateLength(int64 id, float length) override;
	virtual void UpdateChannel(int64 id, int8 channel) override;

private:
	int8 Channels;
	string DeviceName;
	vector<string> AllAudioDevices;
	map<int64, class AudioAsset> audioObjects;
	map<int64, std::shared_ptr<struct Mix_Chunk>> LoadedChunks;
	map<int64, std::shared_ptr<struct _Mix_Music>> LoadedMusics;

	gate Exists(int64 id) const;
	gate LoadedChunk(int64 id) const;
	gate LoadedMusic(int64 id) const;

};


#endif