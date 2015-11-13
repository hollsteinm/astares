#include "Address.h"


Address::Address(String hostname, String port, Family family) :
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