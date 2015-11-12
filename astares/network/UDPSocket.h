#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "CoreSocket.h"
#include "Address.h"


class UDPSocket : public CoreSocket {
public:
	virtual bool Open(const Address& address) override;

	virtual int Send(std::string data) override;
	virtual int Read(std::string& outData, int size) override;
};


#endif