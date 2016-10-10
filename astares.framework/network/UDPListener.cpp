#include "UDPListener.h"

#include "UDPSocket.h"
#include "Packet.h"

UDPListener::UDPListener(cstring port) :
Sock(new UDPSocket())
{
	Address loopback = Address("", port, Family::IPv6);
	if (Sock->Open(loopback)) {
		isAvailable = Sock->Bind(loopback);
	}
}

UDPListener::~UDPListener() {
}

bool UDPListener::Ready() {
	return isAvailable && Sock->Ready();
}

Packet UDPListener::GetPacket() {
	const static int8 StartState = 0;
	const static int8 ReadState = 2;
	const static int8 EndState = 1;
	const static int8 netProtoSize = PACKET_SIZE_SIZE + PACKET_HEADER_SIZE;
	int8 currentState = StartState;
	int64 desiredRead = netProtoSize;
	PacketSize ps;
	memset(&ps, 0, sizeof(PacketSize));
	cstring data;
	isAvailable = false;
	do
	{
		cstring read;
		if (Sock->Read(read, desiredRead) > 0) {
			switch (currentState)
			{
			case StartState:
			{
				data.append(read);
				if (data.size() >= netProtoSize)
				{
					if (data[0] != Packet::Header) {
						currentState = EndState;
						break;
					}
					ps.c[0] = data[1];
					ps.c[1] = data[2];
					ps.c[2] = data[3];
					ps.c[3] = data[4];
					ps.c[4] = data[5];
					ps.c[5] = data[6];
					ps.c[6] = data[7];
					ps.c[7] = data[8];

					if (data.size() >= ps.l)
					{
						currentState = EndState;
					}
					else
					{
						currentState = ReadState;
						desiredRead = ps.l - data.size();
					}
				}
				break;
			}
			case ReadState:
			{
				data.append(read);
				if (data.size() >= ps.l)
				{
					currentState = EndState;
				}
				else
				{
					desiredRead = ps.l - data.size();
				}
				break;
			}
			case EndState:
			default:
				break;
			}
		}
		else {
			currentState = EndState;
		}
	} while (currentState != EndState);
	isAvailable = true;
	return Packet(data.substr(netProtoSize), data.size() - netProtoSize);
}