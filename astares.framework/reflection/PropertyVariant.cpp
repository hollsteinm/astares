#include "PropertyVariant.h"
#include "../serialization/StringHelper.h"

PropertyVariant::PropertyVariant() : Variant(VariantType::unknown){}
PropertyVariant::PropertyVariant(VariantType type) : Variant(type){}
PropertyVariant::PropertyVariant(VariantType type, int64 customType) : Variant(type, customType){}
PropertyVariant::~PropertyVariant(){}
PropertyVariant::PropertyVariant(const PropertyVariant& other)
	: Variant(VariantType::unknown)
{
	type = other.type;
	size = other.size;
	name = other.name;
	customType = other.customType;
	buffer = std::stringstream(other.buffer.str());
	info = other.info;
	propName = other.propName;
}

ReadStream& operator >> (ReadStream& in, PropertyVariant& variant)
{
	string encodedData;
	in >> variant.type >> variant.customType >> variant.size >> variant.name >> encodedData >> variant.propName;
	StringHelper::MakeDecoded(variant.name);
	StringHelper::MakeDecoded(variant.propName);
	variant.SetRaw(StringHelper::Decode(encodedData));
	return in;
}

WriteStream& operator << (WriteStream& out, const PropertyVariant& variant)
{
	return out << variant.type << ' '
		<< variant.customType << ' '
		<< variant.size << ' '
		<< StringHelper::Encode(variant.name) << ' '
		<< StringHelper::Encode(variant.buffer.str()) << ' '
		<< StringHelper::Encode(variant.propName);
}