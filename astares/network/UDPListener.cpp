#include "UDPListener.h"

#include "UDPSocket.h"
#include "Packet.h"
#include "../reflection/Serialization.h"
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
	
	std::string data;
	data.reserve(MaxBuffer);

	int read = 0;
	int recvd = 0;

	recvd = Sock->Read(data, MaxBuffer);
	data[read++];
	PacketSize s;

	for (int i = 0; i < PACKET_SIZE_SIZE; ++i) {
		s.c[i] = data[read++];
	}

	std::stringstream dataStream;
	dataStream << Packet(data, s.l);

	NetworkMessage* ns = Deserialize<NetworkMessage>(dataStream);

	dataStream.clear();
	data.clear();

	if (ns != nullptr) {
		Publish(ns);
	}
}