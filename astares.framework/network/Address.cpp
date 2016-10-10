#include "Address.h"

using namespace astares;

Address::Address(cstring hostname, cstring port, Family family) :
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

std::cstring Address::GetHostname() const { return Hostname; }
std::cstring Address::GetPort() const { return Port; }
Family Address::GetFamily() const { return Fam; }