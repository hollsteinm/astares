#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

enum class Family {
	IPv4 = 0,
	IPv6,
	Unknown = ~0
};

class Address {
private:
	std::string Hostname;
	std::string Port;
	Family Fam;

public:
	Address(std::string hostname, std::string port, Family family);
	Address(const Address& other);

	inline std::string GetHostname() const { return Hostname; }
	inline std::string GetPort() const { return Port; }
	inline Family GetFamily() const { return Fam; }
};


#endif