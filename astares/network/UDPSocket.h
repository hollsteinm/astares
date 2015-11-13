#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "CoreSocket.h"
#include "Address.h"


class UDPSocket : public CoreSocket {
public:
	virtual bool Open(const Address& address) override;

	virtual int Send(String data) override;
	virtual int Read(String& outData, int size) override;
};


#endif