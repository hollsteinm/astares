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

Variant::Variant(VariantType type, long customType)
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



std::ostream& operator << (std::ostream& out, const VariantType& val)
{
	out << (int32)val;
	return out;
}

std::istream& operator >> (std::istream& in, VariantType& val)
{
	int32 o;
	in >> o;
	val = (VariantType)o;
	return in;
}

std::ostream& operator << (std::ostream& out, const Variant& variant)
{
	return out << variant.type				  << ' '
		<< variant.customType				  << ' '
		<< variant.size						  << ' '
		<< StringHelper::Encode(variant.name) << ' '
		<< StringHelper::Encode(variant.buffer.str());
}

std::istream& operator >> (std::istream& in, Variant& variant)
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

const VariantType Variant::GetVariantType() const { return type; }
const int64 Variant::GetType() const { return (int64)((int32)type); }
const string Variant::GetName() const { return name; }
const size_t Variant::GetSize() const { return size; }
const int64 Variant::GetCustomType() const { return customType; }
const string Variant::Value() const { return buffer.str(); }

void Variant::SetRaw(const string& newValue){
	buffer = std::stringstream(newValue, std::ios::binary | std::ios::in | std::ios::out);
}