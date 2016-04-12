#ifndef TYPES_H
#define TYPES_H

#include "../astares.core.h"

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <iosfwd>
#include <cstdint>
#include <type_traits>

typedef char			int8;
typedef int16_t			int16;
typedef int32_t			int32;
typedef int64_t			int64;
typedef uint8_t			uint8;
typedef uint16_t		uint16;
typedef uint32_t		uint32;
typedef uint64_t		uint64;
typedef float			f32;
typedef double			f64;
typedef std::string		string;
typedef bool			gate;

typedef std::iostream	Stream;
typedef std::istream	ReadStream;
typedef std::ostream	WriteStream;

template<typename T>
using vector = std::vector<T, std::allocator<T>>;

template<typename K, typename V>
using map = std::map<K, V>;

template<typename T>
using queue = std::queue<T>;

#ifdef FUTURE_WORK
namespace astares
{
	template<typename T>
	struct Detail
	{
		typedef T ValueType;
		typedef const T ConstValueType;
		typedef T* PointerType;
		typedef const T* ConstPointerType;
		typedef T& ReferenceType;
		typedef const T& ConstReferenceType;
	};

	template<typename>
	struct IsCollectionType : std::false_type{};

	template<typename T, typename A>
	struct IsCollectionType<std::vector<T, A>> : std::true_type{};

	template<typename T, typename A>
	struct IsCollectionType<std::queue<T, A>> : std::true_type{};
}

template<typename T>
struct TypeInfo
{
	static string Name() { static_assert(false, "not defined"); return "invalid"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<T>::Name())); }
	static const astares::Detail<T> Details;
	static int64 Size() { return sizeof(T); }
	static bool IsCollection() { astares::IsCollectionType<T>::value; }
	static bool IsPrimitive() { return false; }

	template<typename A>
	static TypeInfo<A> Get(const A& a) { return TypeInfo<A>(); }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<int8>
{
	static string Name() { return "int8"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<int8>::Name())); }
	static const astares::Detail<int8> Details;
	static int64 Size() { return sizeof(int8); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<int16>
{
	static string Name() { return "int16"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<int16>::Name())); }
	static const astares::Detail<int16> Details;
	static int64 Size() { return sizeof(int16); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<int32>
{
	static string Name() { return "int32"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<int32>::Name())); }
	static const astares::Detail<int32> Details;
	static int64 Size() { return sizeof(int32); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<int64>
{
	static string Name() { return "int64"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<int64>::Name())); }
	static const astares::Detail<int64> Details;
	static int64 Size() { return sizeof(int64); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<uint8>
{
	static string Name() { return "uint8"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<uint8>::Name())); }
	static const astares::Detail<uint8> Details;
	static int64 Size() { return sizeof(uint8); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<uint16>
{
	static string Name() { return "uint16"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<uint16>::Name())); }
	static const astares::Detail<uint16> Details;
	static int64 Size() { return sizeof(uint16); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<uint32>
{
	static string Name() { return "uint32"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<uint32>::Name())); }
	static const astares::Detail<uint32> Details;
	static int64 Size() { return sizeof(uint32); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<uint64>
{
	static string Name() { return "uint64"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<uint64>::Name())); }
	static const astares::Detail<uint64> Details;
	static int64 Size() { return sizeof(uint64); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<f32>
{
	static string Name() { return "f32"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<f32>::Name())); }
	static const astares::Detail<f32> Details;
	static int64 Size() { return sizeof(f32); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<f64>
{
	static string Name() { return "f64"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<f64>::Name())); }
	static const astares::Detail<f64> Details;
	static int64 Size() { return sizeof(f64); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return true; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<string>
{
	static string Name() { return "string"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<string>::Name())); }
	static const astares::Detail<string> Details;
	static int64 Size() { return sizeof(string); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return false; }
};

TEMPLATE_EXTERN template<> struct ASTARESCORE_API TypeInfo<gate>
{
	static string Name() { return "gate"; }
	static int64 TypeId() { return (int64)(std::hash<string>()(TypeInfo<gate>::Name())); }
	static const astares::Detail<gate> Details;
	static int64 Size() { return sizeof(gate); }
	static bool IsCollection() { return false; }
	static bool IsPrimitive() { return false; }
};

#ifndef DECL_API_EXTERN_TYPE
#define DECL_API_EXTERN_TYPE(api, type, ext)                             \
	ext template<> struct api TypeInfo<type>						\
{																							\
	static string Name() { #type; }															\
	static int64 TypeId() { return (int64)(std::hash<string>()(#type)); }					\
	static const astares::Detail<type> Details;												\
	static int64 Size() { return sizeof(type); }											\
	static bool IsCollection() { return false; }											\
	static bool IsPrimitive() { return false; }												\
};																							
#endif

#ifndef DECL_API_TYPE
#define DECL_API_TYPE(api, type) DECL_API_EXTERN_TYPE(api, type, TEMPLATE_EXTERN) 
#endif

#ifndef DECL_TYPE
#define DECL_TYPE(type) DECL_API_EXTERN_TYPE(,type,)
#endif
#endif

#ifndef DECL_API_STL
#define DECL_API_STL(api, type) TEMPLATE_EXTERN template class api std::vector<type>;	\
 TEMPLATE_EXTERN template class api std::deque<type>;	\
 TEMPLATE_EXTERN template class api std::queue<type>;
#endif

#ifndef DECL_API_STL_MAP
#define DECL_API_STL_MAP(api, key, value) TEMPLATE_EXTERN template class api std::map<key, value>;
#endif

#ifndef DECL_API_STL_PTR
#define DECL_API_STL_PTR(api, type) TEMPLATE_EXTERN template class api std::shared_ptr<type>; TEMPLATE_EXTERN template class api std::weak_ptr<type>; TEMPLATE_EXTERN template class api std::unique_ptr<type>;
#endif

#ifndef DECL_CORE_STL
#define DECL_CORE_STL(type) DECL_API_STL(ASTARESCORE_API, type)
#endif

#ifndef DECL_CORE_STL_MAP
#define DECL_CORE_STL_MAP(key, value) DECL_API_STL_MAP(ASTARESCORE_API, key, value)
#endif

#ifndef DECL_CORE_STL_PTR
#define DECL_CORE_STL_PTR(type) DECL_API_STL_PTR(ASTARESCORE_API, type)
#endif

template<typename T>
WriteStream& operator << (WriteStream& out, const vector<T>& arr) {
	out << arr.size() << ' ';
	for (auto elem : arr) {
		out << elem << ' ';
	}
	return out;
}

template<typename T>
ReadStream& operator >> (ReadStream& in, vector<T>& arr) {
	size_t size = 0;
	in >> size;
	arr.clear();
	arr.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		T temp;
		in >> temp;
		arr.push_back(temp);
	}
	return in;
}

ASTARESCORE_API
WriteStream& operator << (WriteStream& out, const std::vector<int8>& arr);
ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, std::vector<int8>& arr);

ASTARESCORE_API
WriteStream& operator << (WriteStream& out, const std::vector<uint8>& arr);
ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, std::vector<uint8>& arr);

ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, int8& val);

ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, uint8& val);

template<typename T, typename V>
WriteStream& operator << (WriteStream& out, const map<T, V>& m) {
	out << m.size() << ' ';
	for (auto kvp : m) {
		out << kvp.first << ' ' << kvp.second << ' ';
	}
	return out;
}

template<typename T, typename V>
ReadStream& operator >> (ReadStream& in, map<T, V>& m) {
	size_t size = 0;
	in >> size;
	for (size_t i = 0; i < size; ++i) {
		T t;
		V v;
		in >> t >> v;
		m.emplace(std::make_pair(t, v));
	}
	return in;
}



template<typename T>
WriteStream& operator << (WriteStream& out, const queue<T>& q) {
	queue<T> copy(q);
	vector<T> output;
	while (!copy.empty())
	{
		output.push_back(copy.front());
		copy.pop();
	}
	out << output;
	return out;
}

template<typename T>
ReadStream& operator >> (ReadStream& in, queue<T>& q) {
	size_t size = 0;
	in >> size;
	while (!q.empty())
	{
		q.pop();
	}
	for (size_t i = 0; i < size; ++i) {
		T t;
		in >> t;
		q.push(t);
	}
	return in;
}

#include "Enum.h"

#endif