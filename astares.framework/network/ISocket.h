#ifndef ISOCKET_H
#define ISOCKET_H

#include "../astares.framework.h"
#include <core/Types.h>

struct ASTARESFRAMEWORK_API ISocket {
	virtual ~ISocket() {}

	virtual gate Open(const class Address& address) = 0;
	virtual gate Bind(const class Address& address) = 0;

	virtual void Close() = 0;

	virtual int32 Send(const string& data) = 0;
	virtual int32 Read(string& outData, int32 size) = 0;
	virtual gate Ready() = 0;
};


#endif