#ifndef CORESOCKET_H
#define CORESOCKET_H

#include "ISocket.h"

#ifdef _WIN32
#include <WinSock2.h>
typedef SOCKET Socket;
#endif

class ASTARESFRAMEWORK_API CoreSocket : public ISocket {
public:
	CoreSocket();
	virtual ~CoreSocket();

	virtual void Close() override;
	virtual gate Bind(const Address& address) override;
	virtual gate Ready() override;

protected:
	gate TryResolve(const class Address& address);

	Socket Sock;

	addrinfo* AddressInfo;

private:
};

#endif