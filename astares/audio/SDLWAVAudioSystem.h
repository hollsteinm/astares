#ifndef SDLWAV_AUDIO_SYSTEM_H
#define SDLWAV_AUDIO_SYSTEM_H

#include "IAudioSystem.h"
#include <vector>

class SDLWAVAudioSystem : public IAudioSystem {
public:
	SDLWAVAudioSystem(class AssetManager* assetManager);
	~SDLWAVAudioSystem();

	virtual class AudioAsset* AddAsset(long typeId, String filename) override;
	virtual void RemoveAsset(long id) override;

	virtual void PlayAudio(long audioId) override;
	virtual void StopAudio(long audioId) override;
	virtual void PauseAudio(long audioId) override;
	virtual void ResumeAudio(long audioId) override;

	virtual String GetName() const override;

	virtual void Configure(const class Config& config) override;
	virtual bool Initialize(struct ILogger* logger) override;
	virtual bool Run() override;
	virtual void Shutdown() override;

private:
	char Channels;
	String DeviceName;
	std::vector<String> AllAudioDevices;

protected:
	class AssetManager* Manager;

};


#endif