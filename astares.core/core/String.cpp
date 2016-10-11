#include "String.h"
#include <string>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <stdarg.h>

using namespace astares;

String::CharIterator::CharIterator(pointer ValuePtr) : 
	ValuePtr(ValuePtr)
{

}

String::CharIterator::self_type String::CharIterator::operator++() 
{ 
	self_type i = *this;  
	ValuePtr++; 
	return i; 
}
String::CharIterator::self_type String::CharIterator::operator++(int junk) 
{ 
	ValuePtr++; 
	return *this; 
}

String::CharIterator::reference String::CharIterator::operator*() const 
{ 
	return *ValuePtr; 
}

String::CharIterator::pointer String::CharIterator::operator->() const 
{ 
	return ValuePtr; 
}

bool String::CharIterator::operator==(const self_type& rhs) const 
{ 
	return ValuePtr == rhs.ValuePtr; 
}

bool String::CharIterator::operator!=(const self_type& rhs) const 
{ 
	return ValuePtr != rhs.ValuePtr; 
}

String::ConstCharIterator::ConstCharIterator(pointer ValuePtr) : 
	ValuePtr(ValuePtr) 
{ 

}

String::ConstCharIterator::self_type String::ConstCharIterator::operator++() 
{ 
	self_type i = *this; 
	ValuePtr++;
	return i; 
}

String::ConstCharIterator::self_type String::ConstCharIterator::operator++(int junk)
{ 
	ValuePtr++;
	return *this;
}

String::ConstCharIterator::reference String::ConstCharIterator::operator*() const 
{ 
	return *ValuePtr; 
}

String::ConstCharIterator::pointer String::ConstCharIterator::operator->() const 
{ 
	return ValuePtr; 
}

bool String::ConstCharIterator::operator==(const self_type& rhs) const
{ 
	return ValuePtr == rhs.ValuePtr; 
}

bool String::ConstCharIterator::operator!=(const self_type& rhs) const 
{ 
	return ValuePtr != rhs.ValuePtr; 
}

String::String() :
	InternalString()
{

}

String::String(cstring Source) :
	InternalString(Source)
{

}

String::String(cstring Source, uint64 size) :
	InternalString(Source, size)
{

}

String::String(const String& other) :
	InternalString(other.InternalString)
{

}

String::String(String&& other) :
	InternalString(other.InternalString)
{

}

String::String(ConstCharIterator First, ConstCharIterator Last) :
	InternalString(First, Last)
{

}

String::String(const std::string& str) :
	InternalString(str)
{

}

String::~String()
{

}

String String::SubString(uint64 StartIndex, uint64 Length) const
{
	return InternalString.substr(StartIndex, static_cast<std::string::size_type>(Length));
}

int32 String::Compare(const String& other) const
{
	return InternalString.compare(other.InternalString);
}

String String::ToLower() const
{
	String copy(InternalString);
	copy.MakeLower();
	return copy;
}

String String::ToUpper() const
{
	String copy(InternalString);
	copy.MakeUpper();
	return copy;
}

void String::MakeLower()
{
	std::transform(InternalString.begin(), InternalString.end(), InternalString.begin(), std::function<char(char)>([](char value) -> char
	{ 
		return static_cast<char>(tolower(static_cast<int>(value)));
	}));
}

void String::MakeUpper()
{
	std::transform(InternalString.begin(), InternalString.end(), InternalString.begin(), std::function<char(char)>([](char value) -> char 
	{ 
		return static_cast<char>(toupper(static_cast<int>(value))); 
	}));
}

String& String::Append(const String& other)
{
	InternalString.append(other.InternalString);
	return *this;
}

bool String::IsNumeric() const
{
	return InternalString.find_first_not_of("-1234567890.") == std::string::npos;
}

bool String::IsDecimal() const
{
	return IsNumeric() && (InternalString.find(".") != std::string::npos && InternalString.find_first_of(".") == InternalString.find_last_of("."));
}

bool String::IsBoolean() const
{
	return true;
}

bool String::IsEmpty() const
{
	return InternalString.empty();
}

bool String::IsWhitespace() const
{
	return InternalString.find_first_not_of(" ") == std::string::npos;
}

bool String::Contains(const String& Value) const
{
	return InternalString.find(Value.InternalString) != std::string::npos;
}

int8 String::ToInt8() const
{
	return static_cast<int8>(std::stoi(InternalString));
}

int16 String::ToInt16() const
{
	return static_cast<int16>(std::stoi(InternalString));
}

int32 String::ToInt32() const
{
	return static_cast<int32>(std::stol(InternalString));
}

int64 String::ToInt64() const
{
	return static_cast<int64>(std::stoll(InternalString));
}

uint8 String::ToUint8() const
{
	return static_cast<uint8>(std::stoul(InternalString));
}

uint16 String::ToUint16() const
{
	return static_cast<uint16>(std::stoul(InternalString));
}

uint32 String::ToUint32() const
{
	return static_cast<uint32>(std::stoul(InternalString));
}

uint64 String::ToUint64() const
{
	return static_cast<uint64>(std::stoull(InternalString));
}

f32 String::ToF32() const
{
	return static_cast<f32>(std::stof(InternalString));
}

f64 String::ToF64() const
{
	return static_cast<f64>(std::stod(InternalString));
}

bool String::ToBoolean() const
{
	return (ToLower() == "true" || ToLower() == "yes");
}

String String::FromInt8(int8 Value)
{
	return std::to_string(Value);
}

String String::FromInt16(int16 Value)
{
	return std::to_string(Value);
}

String String::FromInt32(int32 Value)
{
	return std::to_string(Value);
}

String String::FromInt64(int64 Value)
{
	return std::to_string(Value);
}

String String::FromUint8(uint8 Value)
{
	return std::to_string(Value);
}

String String::FromUint16(uint16 Value)
{
	return std::to_string(Value);
}

String String::FromUint32(uint32 Value)
{
	return std::to_string(Value);
}

String String::FromUint64(uint64 Value)
{
	return std::to_string(Value);
}

String String::FromF32(f32 Value)
{
	return std::to_string(Value);
}

String String::FromF64(f64 Value)
{
	return std::to_string(Value);
}

String String::FromBoolean(bool Value)
{
	return std::to_string(Value);
}

String String::FromFormat(const String& Format, ...)
{
	String result;
	va_list args;
	const char* fmt = Format.ToCString();
	va_start(args, fmt);
	char buff[256];
	if (vsprintf_s(buff, Format.ToCString(), args) >= 0)
	{
		result = String(buff, strnlen_s(buff, 256));
	}
	va_end(args);
	return result;
}

uint64 String::Length() const
{
	return InternalString.length();
}

cstring String::Data() const
{
	return InternalString.data();
}

String::CharIterator String::begin()
{
	return CharIterator(&*InternalString.begin());
}

String::CharIterator String::end()
{
	return CharIterator((&*InternalString.begin()) + InternalString.size());
}

String::ConstCharIterator String::cbegin() const
{
	return ConstCharIterator(&*InternalString.cbegin());
}

String::ConstCharIterator String::cend() const
{
	return ConstCharIterator((&*InternalString.cbegin()) + InternalString.size());
}

cstring String::ToCString() const
{
	return InternalString.c_str();
}

String& String::operator=(const String& rhs)
{
	InternalString = rhs.InternalString;
	return *this;
}

String& String::operator=(cstring rhs)
{
	InternalString = std::string(rhs, std::strlen(rhs));
	return *this;
}

String& String::operator=(String&& rhs)
{
	InternalString = rhs.InternalString;
	return *this;
}

char& String::operator[](uint64 Index)
{
	return InternalString[Index];
}

const char& String::operator[](uint64 Index) const
{
	return InternalString[Index];
}

bool String::operator==(const String& rhs) const
{
	return InternalString == rhs.InternalString;
}

bool String::operator!=(const String& rhs) const
{
	return InternalString != rhs.InternalString;
}

bool String::operator>=(const String& rhs) const
{
	return InternalString >= rhs.InternalString;
}

bool String::operator<=(const String& rhs) const
{
	return InternalString <= rhs.InternalString;
}

bool String::operator>(const String& rhs) const
{
	return InternalString > rhs.InternalString;
}

bool String::operator<(const String& rhs) const
{
	return InternalString < rhs.InternalString;
}