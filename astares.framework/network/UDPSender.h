#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <string>
#include "NetworkMessage.h"

class UDPSender {
public:
	UDPSender(std::string host, std::string port);
	~UDPSender();

	void Send(NetworkMessage* NetMessage);

private:
	struct ISocket* Sock;
};



#endif