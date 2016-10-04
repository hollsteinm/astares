#include "UID.h"
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace astares;

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

cstring UID::ToString() const {
	std::stringstream out;
	LazyConv val;
	val.lval = value;
	out << std::setfill('0') << std::setw(8) << std::hex << val.ival[0] << "-" << std::setw(8) << val.ival[1];
	return out.str().c_str();
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