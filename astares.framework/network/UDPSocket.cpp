#include "UDPSocket.h"
#include <core/Types.h>

using namespace astares;

bool UDPSocket::Open(const Address& address) {
	if (TryResolve(address)) {
		for (addrinfo* ptr = AddressInfo; ptr != nullptr; ptr = ptr->ai_next) {
			Sock = socket(ptr->ai_family, SOCK_DGRAM, IPPROTO_UDP);
			if (Sock != SOCKET_ERROR) {
				return true;
			}
		}
	}
	return false;
}

int32 UDPSocket::Send(cstring data, uint64 size) {
	int32 sent = 0;
	for (addrinfo* ptr = AddressInfo; ptr != nullptr; ptr = ptr->ai_next) {
		sent = sendto(Sock, data, size, 0, ptr->ai_addr, ptr->ai_addrlen);
		if (sent != SOCKET_ERROR) {
			return sent;
		}
	}
	return sent;
}

int32 UDPSocket::Read(char*& outData, int32 size) {
	static const int32 bufferSize = 64 * 1024;
	sockaddr_storage ipsockaddr;
	int32 length = sizeof(sockaddr_storage);
	memset(&ipsockaddr, 0, length);
	outData = new char[bufferSize];
	int32 re = recvfrom(Sock, outData, bufferSize, 0, (sockaddr*)&ipsockaddr, &length);

	if (re != size) {
		//do something? unexpected, cache?? IDK
	}

	if (re != SOCKET_ERROR) {
		return re;
	}
	else {
		return 0;
	}
}