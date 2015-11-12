#ifndef PLAY_AUDIO_HANDLER_H
#define PLAY_AUDIO_HANDLER_H

#include "../messaging/AHandler.h"

class PlayAudioHandler : public AHandler < class PlayAudioMessage > {
public:
	PlayAudioHandler(struct IAudioSystem* audioSubSystem, MessageHub& hub);

protected:
	virtual void InternalHandle(class PlayAudioMessage* Message) override;

private:
	struct IAudioSystem* audioSystem;
};

#endif