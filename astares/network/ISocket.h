#ifndef ISOCKET_H
#define ISOCKET_H

#include <iostream>



struct ISocket {
	virtual ~ISocket() {}

	virtual bool Open(const class Address& address) = 0;
	virtual bool Bind(const class Address& address) = 0;

	virtual void Close() = 0;

	virtual int Send(std::string data) = 0;
	virtual int Read(std::string& outData, int size) = 0;
};


#endif