#include "PlayAudioHandler.h"
#include "PlayAudioMessage.h"
#include "IAudioSystem.h"

PlayAudioHandler::PlayAudioHandler(IAudioSystem* audioSubSystem, MessageHub& hub) :
	AHandler(hub),
	audioSystem(audioSubSystem)
{

}

void PlayAudioHandler::InternalHandle(PlayAudioMessage* Message) {
	audioSystem->PlayAudio(Message->GetAudioId());
}