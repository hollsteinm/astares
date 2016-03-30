#include "Variant.h"
#include "../serialization/StringHelper.h"

Variant::Variant(VariantType type)
	: type(type),
	size(0),
	name("unknown"),
	customType(0),
	buffer(std::ios::binary | std::ios::in | std::ios::out)
{
}

Variant::Variant(VariantType type, int64 customType)
	: type(type),
	size(0),
	name("unknown"),
	customType(customType),
	buffer(std::ios::binary | std::ios::in | std::ios::out)
{
}

Variant::~Variant()
{

}

Variant::Variant(const Variant& other)
	: type(other.type),
	size(other.size),
	name(other.name),
	customType(other.customType),
	buffer(other.buffer.str(), std::ios::binary | std::ios::in | std::ios::out)
{

}

WriteStream& operator << (WriteStream& out, const VariantType& val)
{
	out << (int32)val;
	return out;
}

ReadStream& operator >> (ReadStream& in, VariantType& val)
{
	int32 o;
	in >> o;
	val = (VariantType)o;
	return in;
}

WriteStream& operator << (WriteStream& out, const Variant& variant)
{
	return out << variant.type				  << ' '
		<< variant.customType				  << ' '
		<< variant.size						  << ' '
		<< StringHelper::Encode(variant.name) << ' '
		<< StringHelper::Encode(variant.buffer.str());
}

ReadStream& operator >> (ReadStream& in, Variant& variant)
{
	string inboundData;
	in >> variant.type
		>> variant.customType
		>> variant.size
		>> variant.name 
		>> inboundData;
	StringHelper::MakeDecoded(variant.name);
	variant.SetRaw(StringHelper::Decode(inboundData));
	return in;
}

VariantType Variant::GetVariantType() const { return type; }
int64 Variant::GetType() const { return (int64)((int32)type); }
string Variant::GetName() const { return name; }
size_t Variant::GetSize() const { return size; }
int64 Variant::GetCustomType() const { return customType; }
string Variant::Value() const { return buffer.str(); }

void Variant::SetRaw(const string& newValue){
	buffer = std::stringstream(newValue, std::ios::binary | std::ios::in | std::ios::out);
}