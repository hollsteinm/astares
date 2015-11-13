#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include "../core/String.h"
#include "../messaging/MessageHub.h"


class UDPListener : public MessageHub {
public:
	UDPListener(String port);
	~UDPListener();

	void Digest();

private:
	struct ISocket* Sock;
};



#endif