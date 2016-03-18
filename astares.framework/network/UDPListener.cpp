#include "UDPListener.h"

#include "UDPSocket.h"
#include "Packet.h"
#include "NetworkMessage.h"
#include <sstream>

UDPListener::UDPListener(std::string port) :
	Sock(new UDPSocket())
{
	Address loopback = Address("", port, Family::IPv6);
	if (Sock->Open(loopback)) {
		Sock->Bind(loopback);
	}
}

UDPListener::~UDPListener() {
	delete Sock;
	Sock = nullptr;
}

void UDPListener::Digest() {
	const static long MaxBuffer = 32000;
	string data;
	if (Sock->Read(data, MaxBuffer) > 0) {
		Publish(Message(data));
	}
}