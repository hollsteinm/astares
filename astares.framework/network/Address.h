#ifndef ADDRESS_H
#define ADDRESS_H

#include "../astares.framework.h"
#include <core/Types.h>

enum  class Family {
	IPv4 = 0,
	IPv6,
	Unknown = ~0
};

class ASTARESFRAMEWORK_API Address {
private:
	std::string Hostname;
	std::string Port;
	Family Fam;

public:
	Address(std::string hostname, std::string port, Family family);
	Address(const Address& other);

	std::string GetHostname() const;
	std::string GetPort() const;
	Family GetFamily() const;
};


#endif