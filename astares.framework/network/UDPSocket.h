#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "CoreSocket.h"
#include "Address.h"


class ASTARESFRAMEWORK_API UDPSocket : public CoreSocket {
public:
	virtual gate Open(const Address& address) override;

	virtual int32 Send(const string& data) override;
	virtual int32 Read(string& outData, int32 size) override;
};


#endif