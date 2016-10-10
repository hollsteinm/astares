#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "CoreSocket.h"
#include "Address.h"


class ASTARESFRAMEWORK_API UDPSocket : public CoreSocket {
public:
	virtual bool Open(const Address& address) override;

	virtual int32 Send(cstring data, uint64 size) override;
	virtual int32 Read(char*& outData, int32 size) override;
};


#endif