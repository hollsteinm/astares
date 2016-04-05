#include "Variant.h"
#include "../serialization/StringHelper.h"
#include <sstream>

#ifndef CTOR_VARIANT_DEF
#define CTOR_VARIANT_DEF(T) \
Variant::Variant(const T& newValue) \
: Variant(VariantTypeId<T>::GetType(), VariantTypeId<T>::GetCustomType(), VariantTypeId<T>::GetTypeName()) \
{ \
	buffer << newValue; \
}\
	void Variant::Get(T& value) \
								{\
buffer >> value;\
								}
#endif

#ifndef CTOR_VARIANT_VECTOR_DEF
#define CTOR_VARIANT_VECTOR_DEF(T) \
Variant::Variant(const vector<T>& newValue) \
: Variant(VariantTypeId<vector<T>>::GetType(), VariantTypeId<vector<T>>::GetCustomType(), VariantTypeId<vector<T>>::GetTypeName()) \
{ \
buffer << newValue; \
} \
	void Variant::Get(vector<T>& value) \
								{\
		buffer >> value;\
								}
#endif

#ifndef CTOR_VARIANT_QUEUE_DEF
#define CTOR_VARIANT_QUEUE_DEF(T) \
Variant::Variant(const queue<T>& newValue) \
: Variant(VariantTypeId<queue<T>>::GetType(), VariantTypeId<queue<T>>::GetCustomType(), VariantTypeId<queue<T>>::GetTypeName()) \
{ \
buffer << newValue; \
}\
	void Variant::Get(queue<T>& value) \
								{\
		buffer >> value;\
								}
#endif

static inline void copy_stream(Stream& lhs, const Stream& rhs)
{
	lhs.copyfmt(rhs);
	lhs.clear(rhs.rdstate());
	lhs.basic_ios<char>::rdbuf(rhs.rdbuf());
	lhs.clear();
	lhs.seekg(0, std::ios::beg);
}

Variant::Variant(const VariantType& type)
	: type(type),
	size(0),
	name("unknown"),
	customType(0),
	buffer(new std::stringbuf(std::ios_base::in | std::ios_base::out | std::ios_base::binary))
{
}

Variant::Variant(const VariantType& type, const int64& customType)
	: type(type),
	size(0),
	name("unknown"),
	customType(customType),
	buffer(new std::stringbuf(std::ios_base::in | std::ios_base::out | std::ios_base::binary))
{
}

Variant::Variant(const VariantType& type, const int64& customType, const string& name)
	: Variant(type, customType)
{
	this->name = name;
}

Variant::Variant(const Variant& other)
	: type(other.type),
	size(other.size),
	name(other.name),
	customType(other.customType),
	bIsCollection(other.bIsCollection),
	collectionSize(other.collectionSize),
	collectionType(other.collectionType),
	collectionCustomType(other.collectionCustomType),
	buffer(new std::stringbuf(std::ios_base::in | std::ios_base::out | std::ios_base::binary))
{
	copy_stream(buffer, other.buffer);
}

Variant::~Variant()
{

}

void Variant::Get(ISerializable* value)
{
	value->Deserialize(buffer, 0);
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
	std::stringstream strstream(std::ios::binary | std::ios::in | std::ios::out);
	copy_stream(strstream, variant.buffer);
	return out << variant.type << ' '
		<< variant.customType << ' '
		<< variant.size << ' '
		<< variant.bIsCollection << ' '
		<< variant.collectionSize << ' '
		<< variant.collectionType << ' '
		<< variant.collectionCustomType << ' '
		<< StringHelper::Encode(variant.name) << ' '
		<< StringHelper::Encode(strstream.str());
}

ReadStream& operator >> (ReadStream& in, Variant& variant)
{
	string inboundData;
	in >> variant.type
		>> variant.customType
		>> variant.size
		>> variant.bIsCollection 
		>> variant.collectionSize 
		>> variant.collectionType 
		>> variant.collectionCustomType 
		>> variant.name
		>> inboundData;
	StringHelper::MakeDecoded(variant.name);
	variant.buffer.clear();
	variant.buffer.set_rdbuf(new std::stringbuf(StringHelper::Decode(inboundData), std::ios::binary | std::ios::in | std::ios::out));
	return in;
}

VariantType Variant::GetCollectionType() const
{
	return bIsCollection ? collectionType : type;
}

int64 Variant::GetCollectionCustomType() const
{
	return bIsCollection ? collectionCustomType : customType;
}

size_t Variant::Count() const { return collectionSize; }
bool Variant::IsCollection() const { return bIsCollection; }
VariantType Variant::GetVariantType() const { return type; }
int64 Variant::GetType() const { return (int64)((int32)type); }
string Variant::GetName() const { return name; }
size_t Variant::GetSize() const { return size; }
int64 Variant::GetCustomType() const { return customType; }

string Variant::Value() const
{
	std::stringstream strstream;
	copy_stream(strstream, buffer);
	return strstream.str();
}

void Variant::operator=(const Variant& other)
{
	type = other.type;
	size = other.size;
	name = other.name;
	customType = other.customType;
	bIsCollection = other.bIsCollection;
	collectionSize = other.collectionSize;
	collectionType = other.collectionType;
	collectionCustomType = other.collectionCustomType;
	copy_stream(buffer, other.buffer);
}

bool Variant::operator==(const Variant& other)
{
	return type == other.type && customType == other.customType;
}

bool Variant::operator!=(const Variant& other)
{
	return !(operator==(other));
}


Variant::Variant(const string& newValue)
	: Variant(VariantTypeId<string>::GetType(), VariantTypeId<string>::GetCustomType(), VariantTypeId<string>::GetTypeName())
{
	buffer << StringHelper::Encode(newValue);
}
void Variant::Get(string& value)
{
	string val;
	buffer >> val;
	value = StringHelper::Decode(val);
}

Variant::Variant(const vector<string>& newValue)
	: Variant(VariantTypeId<vector<string>>::GetType(), VariantTypeId<vector<string>>::GetCustomType(), VariantTypeId<vector<string>>::GetTypeName())
{
	size_t size = newValue.size();
	buffer << size << ' ';
	for (auto s : newValue)
	{
		buffer << StringHelper::Encode(s) << ' ';
	}
}
void Variant::Get(vector<string>& value)
{
	size_t size = 0;
	buffer >> size;
	value.reserve(size);
	for (int i = 0; i < size; ++i)
	{
		string val;
		buffer >> val;
		value.push_back(StringHelper::Decode(val));
	}
}


Variant::Variant(const queue<string>& newValue)
	: Variant(VariantTypeId<queue<string>>::GetType(), VariantTypeId<queue<string>>::GetCustomType(), VariantTypeId<queue<string>>::GetTypeName())
{
	size_t size = newValue.size();
	buffer << size << ' ';
	queue<string> cpy = newValue;
	while (!cpy.empty())
	{
		buffer << StringHelper::Encode(cpy.front()) << ' ';
		cpy.pop();		
	}
}
void Variant::Get(queue<string>& value)
{
	size_t size = 0;
	buffer >> size;
	while (!value.empty())
	{
		value.pop();
	}
	for (int i = 0; i < size; ++i)
	{
		string val;
		buffer >> val;
		value.push(StringHelper::Decode(val));
	}
}

CTOR_VARIANT_DEF(int8)
CTOR_VARIANT_DEF(int16)
CTOR_VARIANT_DEF(int32)
CTOR_VARIANT_DEF(int64)
CTOR_VARIANT_DEF(uint8)
CTOR_VARIANT_DEF(uint16)
CTOR_VARIANT_DEF(uint32)
CTOR_VARIANT_DEF(uint64)
CTOR_VARIANT_DEF(f32)
CTOR_VARIANT_DEF(f64)
CTOR_VARIANT_DEF(gate)
CTOR_VARIANT_DEF(UID)
CTOR_VARIANT_DEF(Vector2)
CTOR_VARIANT_DEF(Vector3)
CTOR_VARIANT_DEF(Vector4)
CTOR_VARIANT_DEF(Matrix2)
CTOR_VARIANT_DEF(Matrix3)
CTOR_VARIANT_DEF(Matrix4)
CTOR_VARIANT_DEF(Quaternion)
CTOR_VARIANT_DEF(Plane)
CTOR_VARIANT_DEF(Ray2)
CTOR_VARIANT_DEF(Ray3)
CTOR_VARIANT_DEF(Sphere)
CTOR_VARIANT_DEF(Hull)
CTOR_VARIANT_DEF(Box)
CTOR_VARIANT_DEF(Transform)

CTOR_VARIANT_VECTOR_DEF(int8)
CTOR_VARIANT_VECTOR_DEF(int16)
CTOR_VARIANT_VECTOR_DEF(int32)
CTOR_VARIANT_VECTOR_DEF(int64)
CTOR_VARIANT_VECTOR_DEF(uint8)
CTOR_VARIANT_VECTOR_DEF(uint16)
CTOR_VARIANT_VECTOR_DEF(uint32)
CTOR_VARIANT_VECTOR_DEF(uint64)
CTOR_VARIANT_VECTOR_DEF(f32)
CTOR_VARIANT_VECTOR_DEF(f64)
CTOR_VARIANT_VECTOR_DEF(gate)
CTOR_VARIANT_VECTOR_DEF(UID)
CTOR_VARIANT_VECTOR_DEF(Vector2)
CTOR_VARIANT_VECTOR_DEF(Vector3)
CTOR_VARIANT_VECTOR_DEF(Vector4)
CTOR_VARIANT_VECTOR_DEF(Matrix2)
CTOR_VARIANT_VECTOR_DEF(Matrix3)
CTOR_VARIANT_VECTOR_DEF(Matrix4)
CTOR_VARIANT_VECTOR_DEF(Quaternion)
CTOR_VARIANT_VECTOR_DEF(Plane)
CTOR_VARIANT_VECTOR_DEF(Ray2)
CTOR_VARIANT_VECTOR_DEF(Ray3)
CTOR_VARIANT_VECTOR_DEF(Sphere)
CTOR_VARIANT_VECTOR_DEF(Hull)
CTOR_VARIANT_VECTOR_DEF(Box)
CTOR_VARIANT_VECTOR_DEF(Transform)

CTOR_VARIANT_QUEUE_DEF(int8)
CTOR_VARIANT_QUEUE_DEF(int16)
CTOR_VARIANT_QUEUE_DEF(int32)
CTOR_VARIANT_QUEUE_DEF(int64)
CTOR_VARIANT_QUEUE_DEF(uint8)
CTOR_VARIANT_QUEUE_DEF(uint16)
CTOR_VARIANT_QUEUE_DEF(uint32)
CTOR_VARIANT_QUEUE_DEF(uint64)
CTOR_VARIANT_QUEUE_DEF(f32)
CTOR_VARIANT_QUEUE_DEF(f64)
CTOR_VARIANT_QUEUE_DEF(gate)
CTOR_VARIANT_QUEUE_DEF(UID)
CTOR_VARIANT_QUEUE_DEF(Vector2)
CTOR_VARIANT_QUEUE_DEF(Vector3)
CTOR_VARIANT_QUEUE_DEF(Vector4)
CTOR_VARIANT_QUEUE_DEF(Matrix2)
CTOR_VARIANT_QUEUE_DEF(Matrix3)
CTOR_VARIANT_QUEUE_DEF(Matrix4)
CTOR_VARIANT_QUEUE_DEF(Quaternion)
CTOR_VARIANT_QUEUE_DEF(Plane)
CTOR_VARIANT_QUEUE_DEF(Ray2)
CTOR_VARIANT_QUEUE_DEF(Ray3)
CTOR_VARIANT_QUEUE_DEF(Sphere)
CTOR_VARIANT_QUEUE_DEF(Hull)
CTOR_VARIANT_QUEUE_DEF(Box)
CTOR_VARIANT_QUEUE_DEF(Transform)