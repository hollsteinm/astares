#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include "ISocket.h"


class ASTARESFRAMEWORK_API UDPListener {
public:
	UDPListener(cstring port);
	~UDPListener();

	bool Ready();
	struct Packet GetPacket();

private:
	bool isAvailable;
	std::unique_ptr<struct ISocket> Sock;
};



#endif