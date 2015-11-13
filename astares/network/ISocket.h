#ifndef ISOCKET_H
#define ISOCKET_H

#include <iostream>
#include "../core/String.h"

struct ISocket {
	virtual ~ISocket() {}

	virtual bool Open(const class Address& address) = 0;
	virtual bool Bind(const class Address& address) = 0;

	virtual void Close() = 0;

	virtual int Send(String data) = 0;
	virtual int Read(String& outData, int size) = 0;
};


#endif