#include "UDPSocket.h"


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

int32 UDPSocket::Send(std::string data) {
	int32 sent = 0;
	for (addrinfo* ptr = AddressInfo; ptr != nullptr; ptr = ptr->ai_next) {
		sent = sendto(Sock, data.c_str(), data.size(), 0, ptr->ai_addr, ptr->ai_addrlen);
		if (sent != SOCKET_ERROR) {
			return sent;
		}
	}
	return sent;
}

int32 UDPSocket::Read(std::string& outData, int32 size) {
	sockaddr_storage ipsockaddr;
	int32 length = sizeof(sockaddr_storage);
	
	memset(&ipsockaddr, 0, length);
	
	char* dat = new char[size];

	int32 re = recvfrom(Sock, dat, size, 0, (sockaddr*)&ipsockaddr, &length);

	if (re != SOCKET_ERROR) {
		outData.assign(dat, re);
		delete[] dat;

		return re;
	}
	else {
		delete[] dat;

		return 0;
	}
}