#include "String.h"
#include "../core/Array.h"

String::String() :
	std::string()
{

}

String::String(const std::string& other) :
	std::string(other)
{

}

String::String(const char* str) :
	std::string(str)
{

}

String::String(const char* str, int length) :
	std::string(str, length)
{

}

String::~String() {

}

void String::Encode() {
	auto pos = find(" ");
	while (pos != String::npos) {
		replace(pos, 1, "%20");
		pos = find(" ");
	}
}

void String::Decode() {
	auto pos = find("%20");
	while (pos != String::npos) {
		replace(pos, 3, " ");
		pos = find("%20");
	}
}

void String::operator=(const char* str) {
	assign(str);
}

void String::operator=(const std::string& str) {
	assign(str);
}

std::ostream& operator << (std::ostream& out, String& str) {
	str.Encode();
	return out << std::string(str);
}

std::istream& operator >> (std::istream& in, String& str) {
	std::string dat;
	in >> dat;
	str = dat;
	str.Decode();
	return in;
}