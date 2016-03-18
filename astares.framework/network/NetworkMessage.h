#ifndef NETWORK_MESSAGE_H
#define NETWORK_MESSAGE_H

#include "../messaging/Message.h"

class NetworkMessage : public Message {
public:
	NetworkMessage();
	virtual ~NetworkMessage();
};

#endif