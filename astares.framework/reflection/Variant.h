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
	UID,
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
	Transform,
	Object,
	unknown = ~0
};


ASTARESFRAMEWORK_API WriteStream& operator << (WriteStream& out, const VariantType& val);
ASTARESFRAMEWORK_API ReadStream& operator >> (ReadStream& in, VariantType& val);

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

#ifndef DECL_API_TEMPLATE_VARIANT
#define DECL_API_TEMPLATE_VARIANT(api, type, elem)  TEMPLATE_EXTERN template<> struct api VariantTypeId<type<elem>> { static VariantType GetType() { return VariantType::##type; } static string GetTypeName() { return string(#type).append("[").append(#elem).append("]"); } static int64 GetCustomType() { return (int64)std::hash<string>()(GetTypeName());}};
#endif

#ifndef DECL_API_MAP_VARIANT
#define DECL_API_MAP_VARIANT(api, keyType, valueType) TEMPLATE_EXTERN template<> struct api VariantTypeId<map<keyType, valueType>> { static VariantType GetType() { return VariantType::map; } static string GetTypeName() { return string("map[").append(#keyType).append(",").append(#valueType).append("]"); } static int64 GetCustomType() { return (int64)std::hash<string>()(GetTypeName());}};
#endif

#ifndef DECL_TEMPLATE_VARIANT
#define DECL_TEMPLATE_VARIANT(type, elem) DECL_API_TEMPLATE_VARIANT(ASTARESFRAMEWORK_API, type, elem) 
#endif

#ifndef DECL_MAP_VARIANT
#define DECL_MAP_VARIANT(keyType, valueType)  DECL_API_MAP_VARIANT(ASTARESFRAMEWORK_API, keyType, valueType)
#endif

#ifndef DECL_API_VARIANT
#define DECL_API_VARIANT(api, type)  TEMPLATE_EXTERN template<> struct api VariantTypeId<type> { static VariantType GetType() { return VariantType::##type; } static std::string GetTypeName() { return #type; } static int64 GetCustomType() {return (int64)std::hash<string>()(GetTypeName());}}; \
		DECL_API_TEMPLATE_VARIANT(api, vector, type) \
		DECL_API_TEMPLATE_VARIANT(api, queue, type)
#endif

#ifndef DECL_VARIANT
#define DECL_VARIANT(type) DECL_API_VARIANT(ASTARESFRAMEWORK_API, type)
#endif

#ifndef DECL_API_OBJECT_VARIANT
#define DECL_API_OBJECT_VARIANT(api, type) TEMPLATE_EXTERN template<> struct api VariantTypeId<type> { static VariantType GetType() { return VariantType::Object; } static std::string GetTypeName() { return #type; } static int64 GetCustomType() {return (int64)std::hash<string>()(GetTypeName());}}; \
		DECL_API_TEMPLATE_VARIANT(api, vector, type) \
		DECL_API_TEMPLATE_VARIANT(api, queue, type)
#endif

#ifndef DECL_OBJECT_VARIANT
#define DECL_OBJECT_VARIANT(type) DECL_API_OBJECT_VARIANT(,type)
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
DECL_VARIANT(UID)
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
DECL_VARIANT(Transform)

#ifndef DECL_OBJ_VARIANT
#define DECL_OBJ_VARIANT(type) TEMPLATE_EXTERN template<> struct ASTARESFRAMEWORK_API VariantTypeId<type> { static VariantType GetType() { return VariantType::Object; } static std::string GetTypeName() { return #type; } static int64 GetCustomType() {return (int64)std::hash<string>()(GetTypeName());}};
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
	void Get(T& outValue) const {
		if (VariantTypeId<T>::GetType() == type || type == VariantType::unknown)
		{
			std::istream stream(buffer.rdbuf());
			stream >> outValue;
		}
	}

	template<>
	void Get<string>(string& outValue) const {
		if (VariantTypeId<string>::GetType() == type || type == VariantType::unknown)
		{
			std::istream stream(buffer.rdbuf());
			stream >> outValue;
		}
		StringHelper::Decode(outValue);
	}

	VariantType GetVariantType() const;
	int64 GetType() const;
	string GetName() const;
	size_t GetSize() const;
	int64 GetCustomType() const;
	string Value() const;

	friend WriteStream& operator << (WriteStream& out, const Variant& variant);
	friend ReadStream& operator >> (ReadStream& in, Variant& variant);
};

#endif