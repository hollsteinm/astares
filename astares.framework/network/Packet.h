#ifndef PACKET_H
#define PACKET_H

#ifndef PACKET_HEADER_SIZE
#define PACKET_HEADER_SIZE	1
#endif

#ifndef PACKET_SIZE_SIZE
#define PACKET_SIZE_SIZE	8
#endif

#include "../astares.framework.h"
#include <core/Types.h>

union PacketSize {
	int8	c[PACKET_SIZE_SIZE];
	int32	i[PACKET_SIZE_SIZE / 4];
	int64	l;
};

struct ASTARESFRAMEWORK_API Packet {
	static const int8 Header;
	PacketSize Size;

	string data;

	Packet();
	Packet(const string& in, long size);
	Packet(const Packet& other);
	~Packet();

	int64 RawSize() const;
	int64 ToRaw(string& outData) const;

	friend ASTARESFRAMEWORK_API std::ostream& operator<<(std::ostream& out, Packet& packet);
	friend ASTARESFRAMEWORK_API std::istream& operator>>(std::istream& in, Packet& packet);
};

#endif