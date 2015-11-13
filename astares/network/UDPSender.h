#ifndef UDPSENDER_H
#define UDPSENDER_H

#include "../core/String.h"
#include "NetworkMessage.h"

class UDPSender {
public:
	UDPSender(String host, String port);
	~UDPSender();

	void Send(NetworkMessage* NetMessage);

private:
	struct ISocket* Sock;
};



#endif