#include "PropertyVariant.h"
#include "../serialization/StringHelper.h"
#include <sstream>

static inline void copy_stream(Stream& lhs, const Stream& rhs)
{
	lhs.copyfmt(rhs);
	lhs.clear(rhs.rdstate());
	lhs.basic_ios<char>::rdbuf(rhs.rdbuf());
	lhs.clear();
	lhs.seekg(0, std::ios::beg);
}

PropertyVariant::PropertyVariant() : Variant(VariantType::unknown){}
PropertyVariant::PropertyVariant(const VariantType& type) : Variant(type){}
PropertyVariant::PropertyVariant(const VariantType& type, const int64& customType) : Variant(type, customType){}

PropertyVariant::PropertyVariant(const PropertyVariant& other)
	: Variant(VariantType::unknown)
{
	type = other.type;
	size = other.size;
	name = other.name;
	customType = other.customType;
	buffer.clear();
	copy_stream(buffer, other.buffer);
	info = other.info;
	propName = other.propName;
}

PropertyVariant::PropertyVariant(const VariantType& type, const int64& customType, const string& variantName)
	: Variant(type, customType, variantName)
{

}

PropertyVariant::PropertyVariant(const string& propertyName, const VariantType& type, const int64& customType, const string& variantName)
	: Variant(type, customType, variantName)
{
	propName = propertyName;
}

PropertyVariant::~PropertyVariant(){}


ReadStream& operator >> (ReadStream& in, PropertyVariant& variant)
{
	string encodedData;
	in >> variant.type >> variant.customType >> variant.size >> variant.name >> encodedData >> variant.propName;
	StringHelper::MakeDecoded(variant.name);
	StringHelper::MakeDecoded(variant.propName);
	variant.buffer.clear();
	variant.buffer.set_rdbuf(new std::stringbuf(StringHelper::Decode(encodedData), std::ios::binary | std::ios::in | std::ios::out));
	return in;
}

WriteStream& operator << (WriteStream& out, const PropertyVariant& variant)
{
	std::stringstream strstream(std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	copy_stream(strstream, variant.buffer);
	return out << variant.type << ' '
		<< variant.customType << ' '
		<< variant.size << ' '
		<< StringHelper::Encode(variant.name) << ' '
		<< StringHelper::Encode(strstream.str()) << ' '
		<< StringHelper::Encode(variant.propName);
}

PropertyVariant::PropertyVariant(const Variant& other) : Variant(other)
{

}