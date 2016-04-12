#ifndef UDPSENDER_H
#define UDPSENDER_H

#include "../astares.framework.h"
#include <core/Types.h>

class ASTARESFRAMEWORK_API UDPSender {
public:
	UDPSender(string host, string port);
	~UDPSender();

	void Send(const string& data);

private:
	std::unique_ptr<struct ISocket> Sock;
};



#endif