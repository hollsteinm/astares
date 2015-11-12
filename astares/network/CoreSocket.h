#ifndef CORESOCKET_H
#define CORESOCKET_H

#include "ISocket.h"

#ifdef _WIN32
#include <WinSock2.h>
typedef SOCKET Socket;
#endif

class CoreSocket : public ISocket {
public:
	CoreSocket();
	virtual ~CoreSocket();

	virtual void Close() override;
	virtual bool Bind(const Address& address) override;

protected:
	bool TryResolve(const class Address& address);

	Socket Sock;

	addrinfo* AddressInfo;

private:
};

#endif