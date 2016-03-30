#include "UID.h"
#include <sstream>
#include <ctime>

UID::UID() :
	value(0)
{
}

UID::UID(const int64& val) :
	value(val)
{
}

UID::~UID() {

}

union LazyConv {
	int64 lval;
	int32 ival[2];
};

UID UID::Make()
{
	LazyConv lazy;
	int32 rand = std::rand();
	lazy.ival[0] = std::hash<int32>()(std::clock() + rand);
	rand = std::rand();
	lazy.ival[1] = std::hash<int32>()(std::clock() + rand);
	return UID(lazy.lval);
}

int64 UID::GetValue() const {
	return value;
}

string UID::ToString() const {
	std::stringstream out;
	LazyConv val;
	val.lval = value;
	out << std::hex << val.ival[0] << "-" << val.ival[1];
	return out.str();
}

ReadStream& operator >> (ReadStream& in, UID& out) {
	in >> out.value;
	return in;
}

WriteStream& operator << (WriteStream& out, const UID& in) {
	out << in.value;
	return out;
}

bool UID::operator==(const UID& rhs) const {
	return value == rhs.value;
}

bool UID::operator!=(const UID& rhs) const {
	return value != rhs.value;
}

bool UID::operator<(const UID& rhs) const {
	return value < rhs.value;
}

bool UID::operator>(const UID& rhs) const {
	return value > rhs.value;
}