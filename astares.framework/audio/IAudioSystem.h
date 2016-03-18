#ifndef IAUDIO_SYSTEM
#define IAUDIO_SYSTEM

#include "../core/ISubsystem.h"
#include "SoundType.h"

struct IAudioSystem : public ISubsystem {
	IAudioSystem(){}
	virtual ~IAudioSystem(){}

	virtual bool Supported(string filename) = 0;

	virtual int64 AddAsset(string filename) = 0;
	virtual void RemoveAsset(int64 id) = 0;

	virtual void PlayAudio(long audioId) = 0;
	virtual void StopAudio(long audioId) = 0;
	virtual void PauseAudio(long audioId) = 0;
	virtual void ResumeAudio(long audioId) = 0;

	virtual void UpdateVolume(int64 id, float volume) = 0;
	virtual void UpdateLooping(int64 id, int32 loopcount) = 0;
	virtual void UpdateSoundsType(int64 id, SoundType type) = 0;
	virtual void UpdateLength(int64 id, float length) = 0;
	virtual void UpdateChannel(int64 id, int8 channel) = 0;
};

#endif