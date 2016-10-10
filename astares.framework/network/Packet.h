#ifndef PACKET_H
#define PACKET_H

#include "../astares.framework.h"
#include <core/Types.h>

#ifndef PACKET_HEADER_SIZE
#define PACKET_HEADER_SIZE	sizeof(int8)
#endif

#ifndef PACKET_SIZE_SIZE
#define PACKET_SIZE_SIZE	sizeof(uint64)
#endif

namespace astares
{
	union PacketSize {
		uint8	c[PACKET_SIZE_SIZE];
		uint32	i[PACKET_SIZE_SIZE / 2];
		uint64	l;
	};

	struct ASTARESFRAMEWORK_API Packet 
	{
		static const int8 Header;
		PacketSize Size;

		cstring data;

		Packet();
		Packet(cstring in, long size);
		Packet(const Packet& other);
		~Packet();

		int64 RawSize() const;
		int64 ToRaw(char*& outData) const;

		friend ASTARESFRAMEWORK_API std::ostream& operator<<(std::ostream& out, Packet& packet);
		friend ASTARESFRAMEWORK_API std::istream& operator>>(std::istream& in, Packet& packet);
	};
}

#endif