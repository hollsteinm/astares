#ifndef IAUDIO_SYSTEM
#define IAUDIO_SYSTEM

#include "../astares.framework.h"
#include "SoundType.h"
#include <core\ISubsystem.h>

struct ASTARESFRAMEWORK_API IAudioSystem : public ISubsystem {
	IAudioSystem(){}
	virtual ~IAudioSystem(){}

	virtual bool Supported(string filename) = 0;

	virtual int64 AddAsset(string filename) = 0;
	virtual void RemoveAsset(int64 id) = 0;

	virtual void PlayAudio(int64 audioId) = 0;
	virtual void StopAudio(int64 audioId) = 0;
	virtual void PauseAudio(int64 audioId) = 0;
	virtual void ResumeAudio(int64 audioId) = 0;

	virtual void UpdateVolume(int64 id, float volume) = 0;
	virtual void UpdateLooping(int64 id, int32 loopcount) = 0;
	virtual void UpdateSoundsType(int64 id, SoundType type) = 0;
	virtual void UpdateLength(int64 id, float length) = 0;
	virtual void UpdateChannel(int64 id, int8 channel) = 0;
};

#endif