#ifndef ADDRESS_H
#define ADDRESS_H

#include "../astares.framework.h"
#include <core/Types.h>

namespace astares
{
	BETTER_ENUM(Family, uint8,
		IPv4,
		IPv6,
		Unknown)

	class ASTARESFRAMEWORK_API Address 
	{
	private:
		cstring Hostname;
		cstring Port;
		Family Fam;

	public:
		Address(cstring hostname, cstring port, Family family);
		Address(const Address& other);

		cstring GetHostname() const;
		cstring GetPort() const;
		Family GetFamily() const;
	};

}
#endif