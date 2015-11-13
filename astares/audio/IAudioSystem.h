#ifndef IAUDIO_SYSTEM
#define IAUDIO_SYSTEM

#include "../core/ISubsystem.h"

struct IAudioSystem : public ISubsystem {
	IAudioSystem(){}
	virtual ~IAudioSystem(){}

	virtual class AudioAsset* AddAsset(long typeId, String filename) = 0;
	virtual void RemoveAsset(long id) = 0;

	virtual void PlayAudio(long audioId) = 0;
	virtual void StopAudio(long audioId) = 0;
	virtual void PauseAudio(long audioId) = 0;
	virtual void ResumeAudio(long audioId) = 0;

};

#endif