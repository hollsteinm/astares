#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include <string>
#include "../messaging/MessageHub.h"


class UDPListener : public MessageHub {
public:
	UDPListener(std::string port);
	~UDPListener();

	void Digest();

private:
	struct ISocket* Sock;
};



#endif