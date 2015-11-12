#include "PlayAudioMessage.h"

PlayAudioMessage::PlayAudioMessage() {
	CTOR_REGISTER(PlayAudioMessage)
}

PlayAudioMessage::~PlayAudioMessage() {

}

REFLECTION_BEGIN(PlayAudioMessage)
	PARENT(AudioMessage)
REFLECTION_END(PlayAudioMessage)