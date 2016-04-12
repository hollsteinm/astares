#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include "ISocket.h"


class ASTARESFRAMEWORK_API UDPListener {
public:
	UDPListener(string port);
	~UDPListener();

	gate Ready();
	struct Packet GetPacket();

private:
	gate isAvailable;
	std::unique_ptr<struct ISocket> Sock;
};



#endif