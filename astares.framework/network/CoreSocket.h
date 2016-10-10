#ifndef CORESOCKET_H
#define CORESOCKET_H

#include "ISocket.h"

#ifdef _WIN32
#include <WinSock2.h>
typedef SOCKET Socket;
#endif

namespace astares
{
	class ASTARESFRAMEWORK_API CoreSocket : public ISocket {
	public:
		CoreSocket();
		virtual ~CoreSocket();

		virtual void Close() override;
		virtual bool Bind(const Address& address) override;
		virtual bool Ready() override;

	protected:
		bool TryResolve(const class Address& address);

		Socket Sock;

		addrinfo* AddressInfo;

	private:
	};
}

#endif