#include "Packet.h"

#include <iostream>

const int8 Packet::Header = 0x17;

Packet::Packet()
{
	Size.l = 0;
}

Packet::Packet(const string& in, long size) {
	data = in;
	Size.l = size;
}

Packet::Packet(const Packet& other) :
	Size(other.Size),
	data(other.data)
{
}

Packet::~Packet() {

}

int64 Packet::RawSize() const {
	return PACKET_HEADER_SIZE + PACKET_SIZE_SIZE + Size.l;
}

int64 Packet::ToRaw(string& outData) const {
	int64 length = RawSize();
	
	int32 idx = 0;
	outData.resize(length);
	outData[idx++] = Header;

	for (int32 i = 0; i < PACKET_SIZE_SIZE; ++i) {
		outData[idx++] = Size.c[i];
	}

	for (long l = 0; l < Size.l; ++l) {
		outData[idx++] = data[l];
	}

	return length;
}

WriteStream& operator<<(WriteStream& out, Packet& packet) {
	return out.write(packet.data.c_str(), packet.data.size());
}

ReadStream& operator>>(ReadStream& in, Packet& packet) {
	in.seekg(0, std::ios::end);
	auto length = in.tellg();
	in.seekg(0, std::ios::beg);
	char* buffer = new char[length];

	in.read(buffer, length);
	packet = Packet(string(buffer, length), length);

	delete[] buffer;

	return in;
}