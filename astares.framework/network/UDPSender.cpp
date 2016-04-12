#include "UDPSender.h"

#include "UDPSocket.h"
#include "Address.h"
#include "Packet.h"

UDPSender::UDPSender(string host, string port) :
Sock(new UDPSocket())
{
	Sock->Open(Address(host, port, Family::IPv6));
}

UDPSender::~UDPSender() {
}

void UDPSender::Send(const string& data) {
	Packet p(data, data.size());
	string raw;
	p.ToRaw(raw);
	Sock->Send(raw);
}