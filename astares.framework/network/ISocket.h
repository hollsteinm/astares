#ifndef ISOCKET_H
#define ISOCKET_H

#include "../core/Types.h"

struct ISocket {
	virtual ~ISocket() {}

	virtual bool Open(const class Address& address) = 0;
	virtual bool Bind(const class Address& address) = 0;

	virtual void Close() = 0;

	virtual int32 Send(std::string data) = 0;
	virtual int32 Read(std::string& outData, int32 size) = 0;
};


#endif