#include "CoreSocket.h"
#include "Address.h"

#ifdef _WIN32
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define inet_ntop InetNtopA
#endif

CoreSocket::CoreSocket() :
	Sock(0),
	AddressInfo(nullptr)
{
}

CoreSocket::~CoreSocket() {
	Close();
}

void CoreSocket::Close() {
	closesocket(Sock);
	freeaddrinfo(AddressInfo);
}

bool CoreSocket::Bind(const Address& address) {
	if (TryResolve(address)) {
		for (addrinfo* ptr = AddressInfo; ptr != nullptr; ptr = ptr->ai_next) {
			if (bind(Sock, ptr->ai_addr, ptr->ai_addrlen) != SOCKET_ERROR) {
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

bool CoreSocket::TryResolve(const Address& desired) {
	addrinfo hints;
	char port[128];
	char host[128];
	char* phost = nullptr;

	memset(&port[0], 0, sizeof(char) * 128);
	memset(&host[0], 0, sizeof(char) * 128);

	strcpy_s(port, desired.GetPort().c_str());

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;

	if (desired.GetHostname().empty()) {
		hints.ai_flags = AI_PASSIVE;
	}
	else {
		strcpy_s(host, desired.GetHostname().c_str());
		phost = &host[0];
	}

	return getaddrinfo(phost, &port[0], &hints, &AddressInfo) == 0;
}