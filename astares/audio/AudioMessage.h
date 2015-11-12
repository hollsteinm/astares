#ifndef AUDIO_MESSAGE_H
#define AUDIO_MESSAGE_H

#include "../reflection/Reflection.h"
#include "../messaging/Message.h"

DECL_CLASS(AudioMessage) : public Message {
	DECL_BODY(AudioMessage)

public:
	int GetAudioId() const;
private:
	int AudioId;
};

#endif