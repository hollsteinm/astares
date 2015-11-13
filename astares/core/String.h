#ifndef STRING_H
#define STRING_H

#include <string>
#include <ostream>
#include <istream>

struct String : public std::string{
	void Encode();
	void Decode();

	String();
	String(const std::string& str);
	String(const char* str);
	String(const char* str, int length);
	~String();

	void operator=(const char* str);
	void operator=(const std::string& str);

	friend std::ostream& operator << (std::ostream& out, String& str);
	friend std::istream& operator >> (std::istream& in, String& str);
};

#endif