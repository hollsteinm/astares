#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "CoreSocket.h"
#include "Address.h"


class UDPSocket : public CoreSocket {
public:
	virtual bool Open(const Address& address) override;

	virtual int32 Send(std::string data) override;
	virtual int32 Read(std::string& outData, int32 size) override;
};


#endif