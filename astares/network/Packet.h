#ifndef PACKET_H
#define PACKET_H

#ifndef PACKET_HEADER_SIZE
#define PACKET_HEADER_SIZE	1
#endif

#ifndef PACKET_SIZE_SIZE
#define PACKET_SIZE_SIZE	8
#endif

#include <iostream>


union PacketSize {
	char	c[8];
	int		i[2];
	long	l;
};

struct Packet {
	char Header;
	PacketSize Size;

	std::string data;

	Packet();
	Packet(const std::string& in, long size);
	Packet(const Packet& other);
	~Packet();

	long RawSize() const;
	long ToRaw(std::string& outData) const;
};


std::ostream& operator<<(std::ostream& out, Packet& packet);
std::istream& operator>>(std::istream& in, Packet& packet);


#endif