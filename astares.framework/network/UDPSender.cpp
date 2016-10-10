#include "UDPSender.h"

#include "UDPSocket.h"
#include "Address.h"
#include "Packet.h"

UDPSender::UDPSender(cstring host, cstring port) :
Sock(new UDPSocket())
{
	Sock->Open(Address(host, port, Family::IPv6));
}

UDPSender::~UDPSender() {
}

void UDPSender::Send(cstring data, uint64 size) {
	Packet p(data, data.size());
	cstring raw;
	p.ToRaw(raw);
	Sock->Send(raw);
}