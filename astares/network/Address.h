#ifndef ADDRESS_H
#define ADDRESS_H

#include "../core/String.h"

enum class Family {
	IPv4 = 0,
	IPv6,
	Unknown = ~0
};

class Address {
private:
	String Hostname;
	String Port;
	Family Fam;

public:
	Address(String hostname, String port, Family family);
	Address(const Address& other);

	inline String GetHostname() const { return Hostname; }
	inline String GetPort() const { return Port; }
	inline Family GetFamily() const { return Fam; }
};


#endif