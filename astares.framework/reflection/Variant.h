#ifndef VARIANT_H
#define VARIANT_H

#include "..\astares.framework.h"
#include <Core.h>

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

template<typename T> static const VariantTypeId<T> TypeOf() { return VariantTypeId<T>(); }

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

#ifndef CTOR_VARIANT
#define CTOR_VARIANT(T) Variant(const T& newValue); void Get(T& value);
#endif

#ifndef CTOR_VARIANT_VECTOR
#define CTOR_VARIANT_VECTOR(T) Variant(const vector<T>& newValue); void Get(vector<T>& value);
#endif

#ifndef CTOR_VARIANT_QUEUE
#define CTOR_VARIANT_QUEUE(T) Variant(const queue<T>& newValue); void Get(queue<T>& value);
#endif

//TODO: maps...

class ASTARESFRAMEWORK_API Variant
{
protected:
	string name;
	size_t size = 0;
	int64 customType;
	VariantType type;
	Stream buffer;

	bool bIsCollection;
	VariantType collectionType;
	int64 collectionCustomType;
	size_t collectionSize;

public:
	Variant(const VariantType& type);
	Variant(const VariantType& type, const int64& customType);
	Variant(const VariantType& type, const int64& customType, const string& name);
	Variant(const Variant& other);
	virtual ~Variant();

	template<template<typename, typename> class Container, typename T>
	Variant(const Container<T, std::allocator<T>>& value)
		: Variant(VariantTypeId<Container<T, std::allocator<T>>::GetType(), 
		VariantTypeId<Container<T, std::allocator<T>>::GetCustomType(),
		VariantTypeId<Container<T, std::allocator<T>>::GetTypeName())
	{
		bIsCollection = true;
		collectionType = VariantTypeId<T>::GetType();
		customType = VariantTypeId<T>::GetCustomType();
		collectionSize = value.size();
		buffer << newValue;
	}

	template<template<typename, typename> class Container, typename T>
	Variant(const Container<T, std::deque<T>>& value)
		: Variant(VariantTypeId<Container<T, std::allocator<T>>::GetType(),
		VariantTypeId<Container<T, std::allocator<T>>::GetCustomType(),
		VariantTypeId<Container<T, std::allocator<T>>::GetTypeName())
	{
		bIsCollection = true;
		collectionType = VariantTypeId<T>::GetType();
		customType = VariantTypeId<T>::GetCustomType();
		collectionSize = value.size();
		buffer << newValue;
	}

	template<typename T>
	Variant(const T& serializable, gate compilerHack)
		: Variant(VariantTypeId<T>::GetType(),
		VariantTypeId<T>::GetCustomType(),
		VariantTypeId<T>::GetTypeName())
	{
		((ISerializable*)&serializable)->Serialize(buffer, 0);
	}

	CTOR_VARIANT(int8)
	CTOR_VARIANT(int16)
	CTOR_VARIANT(int32)
	CTOR_VARIANT(int64)
	CTOR_VARIANT(uint8)
	CTOR_VARIANT(uint16)
	CTOR_VARIANT(uint32)
	CTOR_VARIANT(uint64)
	CTOR_VARIANT(f32)
	CTOR_VARIANT(f64)
	CTOR_VARIANT(gate)
	CTOR_VARIANT(string)
	CTOR_VARIANT(UID)
	CTOR_VARIANT(Vector2)
	CTOR_VARIANT(Vector3)
	CTOR_VARIANT(Vector4)
	CTOR_VARIANT(Matrix2)
	CTOR_VARIANT(Matrix3)
	CTOR_VARIANT(Matrix4)
	CTOR_VARIANT(Quaternion)
	CTOR_VARIANT(Plane)
	CTOR_VARIANT(Ray2)
	CTOR_VARIANT(Ray3)
	CTOR_VARIANT(Sphere)
	CTOR_VARIANT(Hull)
	CTOR_VARIANT(Box)
	CTOR_VARIANT(Transform)

	CTOR_VARIANT_VECTOR(int8)
	CTOR_VARIANT_VECTOR(int16)
	CTOR_VARIANT_VECTOR(int32)
	CTOR_VARIANT_VECTOR(int64)
	CTOR_VARIANT_VECTOR(uint8)
	CTOR_VARIANT_VECTOR(uint16)
	CTOR_VARIANT_VECTOR(uint32)
	CTOR_VARIANT_VECTOR(uint64)
	CTOR_VARIANT_VECTOR(f32)
	CTOR_VARIANT_VECTOR(f64)
	CTOR_VARIANT_VECTOR(gate)
	CTOR_VARIANT_VECTOR(string)
	CTOR_VARIANT_VECTOR(UID)
	CTOR_VARIANT_VECTOR(Vector2)
	CTOR_VARIANT_VECTOR(Vector3)
	CTOR_VARIANT_VECTOR(Vector4)
	CTOR_VARIANT_VECTOR(Matrix2)
	CTOR_VARIANT_VECTOR(Matrix3)
	CTOR_VARIANT_VECTOR(Matrix4)
	CTOR_VARIANT_VECTOR(Quaternion)
	CTOR_VARIANT_VECTOR(Plane)
	CTOR_VARIANT_VECTOR(Ray2)
	CTOR_VARIANT_VECTOR(Ray3)
	CTOR_VARIANT_VECTOR(Sphere)
	CTOR_VARIANT_VECTOR(Hull)
	CTOR_VARIANT_VECTOR(Box)
	CTOR_VARIANT_VECTOR(Transform)

	CTOR_VARIANT_QUEUE(int8)
	CTOR_VARIANT_QUEUE(int16)
	CTOR_VARIANT_QUEUE(int32)
	CTOR_VARIANT_QUEUE(int64)
	CTOR_VARIANT_QUEUE(uint8)
	CTOR_VARIANT_QUEUE(uint16)
	CTOR_VARIANT_QUEUE(uint32)
	CTOR_VARIANT_QUEUE(uint64)
	CTOR_VARIANT_QUEUE(f32)
	CTOR_VARIANT_QUEUE(f64)
	CTOR_VARIANT_QUEUE(gate)
	CTOR_VARIANT_QUEUE(string)
	CTOR_VARIANT_QUEUE(UID)
	CTOR_VARIANT_QUEUE(Vector2)
	CTOR_VARIANT_QUEUE(Vector3)
	CTOR_VARIANT_QUEUE(Vector4)
	CTOR_VARIANT_QUEUE(Matrix2)
	CTOR_VARIANT_QUEUE(Matrix3)
	CTOR_VARIANT_QUEUE(Matrix4)
	CTOR_VARIANT_QUEUE(Quaternion)
	CTOR_VARIANT_QUEUE(Plane)
	CTOR_VARIANT_QUEUE(Ray2)
	CTOR_VARIANT_QUEUE(Ray3)
	CTOR_VARIANT_QUEUE(Sphere)
	CTOR_VARIANT_QUEUE(Hull)
	CTOR_VARIANT_QUEUE(Box)
	CTOR_VARIANT_QUEUE(Transform)

	void Get(ISerializable* value);

	template<template<typename, typename> class Container, typename T>
	void Get(Container<T, std::allocator<T>>& value)
	{
		buffer >> value;
	}

	template<template<typename, typename> class Container, typename T>
	void Get(Container<T, std::deque<T>>& value)
	{
		buffer >> value;
	}

	template<template<typename, typename> class Container, typename T>
	void Get(Container<T*, std::allocator<T*>>& value)
	{
		buffer >> value;
	}

	template<template<typename, typename> class Container, typename T>
	void Get(Container<T*, std::deque<T*>>& value)
	{
		buffer >> value;
	}

	bool IsCollection() const;
	VariantType GetCollectionType() const;
	int64 GetCollectionCustomType() const;
	size_t Count() const;

	VariantType GetVariantType() const;
	int64 GetType() const;
	string GetName() const;
	size_t GetSize() const;
	int64 GetCustomType() const;
	string Value() const;

	friend WriteStream& operator << (WriteStream& out, const Variant& variant);
	friend ReadStream& operator >> (ReadStream& in, Variant& variant);

	void operator=(const Variant& other);
	bool operator==(const Variant& other);
	bool operator!=(const Variant& other);
};

#endif