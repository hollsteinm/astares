#include "UDPSender.h"

#include "UDPSocket.h"
#include "Address.h"
#include "Packet.h"

#include <sstream>


UDPSender::UDPSender(std::string host, std::string port) :
	Sock(new UDPSocket())
{
	Sock->Open(Address(host, port, Family::IPv6));
}

UDPSender::~UDPSender() {
	delete Sock;
	Sock = nullptr;
}

void UDPSender::Send(NetworkMessage* NetMessage) {
	if (NetMessage != nullptr) {
		std::stringstream send;

		Packet p;
		send >> p;

		Sock->Send(p.data);

		send.flush();
		send.clear();
	}
}