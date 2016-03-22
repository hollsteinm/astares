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

UID UID::Make()
{
	int32 rand = std::rand();
	return UID(std::hash<int64>()(std::clock() + rand));
}

int64 UID::GetValue() const {
	return value;
}

union LazyConv {
	int64 lval;
	int32 ival[2];
};

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