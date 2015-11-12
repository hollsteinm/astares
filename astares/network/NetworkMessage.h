#ifndef NETWORK_MESSAGE_H
#define NETWORK_MESSAGE_H

#include "../messaging/Message.h"

DECL_CLASS(NetworkMessage) : public Message {
	DECL_BODY(NetworkMessage)
	public:
		NetworkMessage(Object* sender);
};

#endif