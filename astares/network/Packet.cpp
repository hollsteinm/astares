#include "Packet.h"

#include <iostream>


Packet::Packet() :
	Header(0x17)
{
	Size.l = 0;
}

Packet::Packet(const std::string& in, long size) {
	Header = 0x17;
	data = in;
	Size.l = size;
}

Packet::Packet(const Packet& other) :
	Size(other.Size),
	Header(Header),
	data(other.data)
{
}

Packet::~Packet() {

}

long Packet::RawSize() const {
	return PACKET_HEADER_SIZE + PACKET_SIZE_SIZE + Size.l;
}

long Packet::ToRaw(std::string& outData) const {
	long length = RawSize();
	
	int idx = 0;
	outData[idx++] = Header;

	for (int i = 0; i < PACKET_SIZE_SIZE; ++i) {
		outData[idx++] = Size.c[i];
	}

	for (long l = 0; l < Size.l; ++l) {
		outData[idx++] = data[l];
	}

	return length;
}

std::ostream& operator<<(std::ostream& out, Packet& packet) {
	return out.write(packet.data.c_str(), packet.data.size());
}

std::istream& operator>>(std::istream& in, Packet& packet) {
	in.seekg(0, std::ios::end);
	long length = (long)in.tellg();
	in.seekg(0, std::ios::beg);
	char* buffer = new char[length];

	in.read(buffer, length);
	packet = Packet(std::string(buffer, length), length);

	delete[] buffer;

	return in;
}

