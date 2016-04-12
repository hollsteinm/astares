#include "Address.h"


Address::Address(string hostname, string port, Family family) :
	Hostname(hostname),
	Port(port),
	Fam(family)
{
}


Address::Address(const Address& other):
	Hostname(other.Hostname),
	Port(other.Port),
	Fam(other.Fam)
{
}

std::string Address::GetHostname() const { return Hostname; }
std::string Address::GetPort() const { return Port; }
Family Address::GetFamily() const { return Fam; }