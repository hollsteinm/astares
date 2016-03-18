#ifndef VARIANT_H
#define VARIANT_H

#include "..\astares.framework.h"
#include <Core.h>
#include "..\serialization\StringHelper.h"
#include <sstream>

enum class VariantType
{
	int8 = 0,
	int16,
	int32,
	int64,
	uint8,
	uint16,
	uint32,
	uint64,
	f32,
	f64,
	gate,
	string,
	vector,
	map,
	queue,
	Vector2,
	Vector3,
	Vector4,
	Matrix2,
	Matrix3,
	Matrix4,
	Quaternion,
	Plane,
	Ray2,
	Ray3,
	Sphere,
	Hull,
	Box,
	Object,
	unknown = ~0
};


std::ostream& operator << (std::ostream& out, const VariantType& val);
std::istream& operator >> (std::istream& in, VariantType& val);

template<typename T>
struct VariantTypeId
{
	static VariantType GetType() {
		return VariantType::unknown;
	}

	static std::string GetTypeName() {
		return "unknown";
	}

	static int64 GetCustomType() {
		return (int64)std::hash<string>()(GetTypeName());
	}
};

#ifndef DECL_TEMPLATE_VARIANT
#define DECL_TEMPLATE_VARIANT(type, elem) template<> struct VariantTypeId<type<elem>> { static VariantType GetType() { return VariantType::##type; } static string GetTypeName() { return string(#type).append("[").append(#elem).append("]"); } static int64 GetCustomType() { return (int64)std::hash<string>()(GetTypeName());}};
#endif

#ifndef DECL_MAP_VARIANT
#define DECL_MAP_VARIANT(keyType, valueType) template<> struct VariantTypeId<map<keyType, valueType>> { static VariantType GetType() { return VariantType::map; } static string GetTypeName() { return string("map[").append(#keyType).append(",").append(#valueType).append("]"); } static int64 GetCustomType() { return (int64)std::hash<string>()(GetTypeName());}};
#endif

#ifndef DECL_VARIANT
#define DECL_VARIANT(type) template<> struct VariantTypeId<type> { static VariantType GetType() { return VariantType::##type; } static std::string GetTypeName() { return #type; } static int64 GetCustomType() {return (int64)std::hash<string>()(GetTypeName());}}; \
	DECL_TEMPLATE_VARIANT(vector, type) \
	DECL_TEMPLATE_VARIANT(queue, type)
#endif

DECL_VARIANT(int8)
DECL_VARIANT(int16)
DECL_VARIANT(int32)
DECL_VARIANT(int64)
DECL_VARIANT(uint8)
DECL_VARIANT(uint16)
DECL_VARIANT(uint32)
DECL_VARIANT(uint64)
DECL_VARIANT(f32)
DECL_VARIANT(f64)
DECL_VARIANT(gate)
DECL_VARIANT(string)
DECL_VARIANT(Vector2)
DECL_VARIANT(Vector3)
DECL_VARIANT(Vector4)
DECL_VARIANT(Matrix2)
DECL_VARIANT(Matrix3)
DECL_VARIANT(Matrix4)
DECL_VARIANT(Quaternion)
DECL_VARIANT(Plane)
DECL_VARIANT(Ray2)
DECL_VARIANT(Ray3)
DECL_VARIANT(Sphere)
DECL_VARIANT(Hull)
DECL_VARIANT(Box)

#ifndef DECL_OBJ_VARIANT
#define DECL_OBJ_VARIANT(type) template<> struct VariantTypeId<type> { static VariantType GetType() { return VariantType::Object; } static std::string GetTypeName() { return #type; } static int64 GetCustomType() {return (int64)std::hash<string>()(GetTypeName());}};
#endif

class ASTARESFRAMEWORK_API Variant
{
protected:
	string name;
	size_t size;
	int64 customType;
	VariantType type;
	std::stringstream buffer;

public:
	Variant(VariantType type);
	Variant(VariantType type, int64 customType);
	virtual ~Variant();
	Variant(const Variant& other);

	template<typename T>
	Variant(const T& newValue) :
		buffer(std::ios::binary | std::ios::in | std::ios::out)
	{
		type = VariantTypeId<T>::GetType();
		Set(newValue);
	}

	template<typename T> 
	void Set(const T& newValue){
		if (VariantTypeId<T>::GetType() == type || type == VariantType::unknown)
		{
			if (type == VariantType::unknown)
			{
				type = VariantTypeId<T>::GetType();
			}
			size = sizeof(T);
			name = VariantTypeId<T>::GetTypeName();
			customType = (int64)std::hash<string>()(name);
			buffer << newValue;
		}
	}

	template<>
	void Set<Variant>(const Variant& newValue){
		type = newValue.type;
		size = newValue.size;
		name = newValue.name;
		customType = newValue.customType;
		buffer = std::stringstream(newValue.buffer.str(), std::ios::binary | std::ios::in | std::ios::out);
	}

	template<>
	void Set<string>(const string& newValue)
	{
		string writeVal = newValue;
		StringHelper::Encode(writeVal);
		if (VariantTypeId<string>::GetType() == type || type == VariantType::unknown)
		{
			if (type == VariantType::unknown)
			{
				type = VariantTypeId<string>::GetType();
			}
			buffer << newValue;
			size = sizeof(string);
			name = VariantTypeId<string>::GetTypeName();
			customType = (long)std::hash<string>()(name);
		}
	}

	void SetRaw(const string& newValue);

	template<typename T>
	void Get(T& outValue) {
		if (VariantTypeId<T>::GetType() == type || type == VariantType::unknown)
		{
			buffer >> outValue;
		}
	}

	template<>
	void Get<string>(string& outValue) {
		Get(outValue);
		StringHelper::Decode(outValue);
	}

	const VariantType GetVariantType() const;
	const int64 GetType() const;
	const string GetName() const;
	const size_t GetSize() const;
	const int64 GetCustomType() const;
	const string Value() const;

	friend std::ostream& operator << (std::ostream& out, const Variant& variant);
	friend std::istream& operator >> (std::istream& in, Variant& variant);
};

#endif