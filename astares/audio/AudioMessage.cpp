#include "AudioMessage.h"

AudioMessage::AudioMessage() {
	CTOR_REGISTER(AudioMessage)
}

AudioMessage::~AudioMessage() {

}

int AudioMessage::GetAudioId() const {
	return AudioId;
}

REFLECTION_BEGIN(AudioMessage)
	PARENT(Message)
	FIELD(int, AudioId)
REFLECTION_END(AudioMessage)