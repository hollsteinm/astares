#ifndef TYPES_H
#define TYPES_H

#include "../astares.core.h"

#include <string>
#include <memory>
#include <vector>
#include <cstdint>
#include <type_traits>

namespace astares
{
	typedef int8_t			int8;
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
	typedef bool			boolean;
	typedef const char*		cstring;

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

	template<typename T>
	struct TypeInfo
	{
		static cstring Name() { static_assert(false, "not defined"); return "invalid"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()(TypeInfo<T>::Name())); }
		static const Detail<T> Details;
		static int64 Size() { return sizeof(T); }
		static bool IsCollection() { std::is_array<T>::value; }
		static bool IsPointer() { std::is_pointer<T>::value; }
		static bool IsPrimitive() { return false; }
	};

	template<> struct TypeInfo < int8 >
	{
		static cstring Name() { return "int8"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("int8")); }
		static const Detail<int8> Details;
		static int64 Size() { return sizeof(int8); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < int16 >
	{
		static cstring Name() { return "int16"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("int16")); }
		static const Detail<int16> Details;
		static int64 Size() { return sizeof(int16); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < int32 >
	{
		static cstring Name() { return "int32"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("int32")); }
		static const Detail<int32> Details;
		static int64 Size() { return sizeof(int32); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < int64 >
	{
		static cstring Name() { return "int64"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("int64")); }
		static const Detail<int64> Details;
		static int64 Size() { return sizeof(int64); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < uint8 >
	{
		static cstring Name() { return "uint8"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("uint8")); }
		static const Detail<uint8> Details;
		static int64 Size() { return sizeof(uint8); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < uint16 >
	{
		static cstring Name() { return "uint16"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("uint16")); }
		static const Detail<uint16> Details;
		static int64 Size() { return sizeof(uint16); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < uint32 >
	{
		static cstring Name() { return "uint32"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("uint32")); }
		static const Detail<uint32> Details;
		static int64 Size() { return sizeof(uint32); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < uint64 >
	{
		static cstring Name() { return "uint64"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("uint64")); }
		static const Detail<uint64> Details;
		static int64 Size() { return sizeof(uint64); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < f32 >
	{
		static cstring Name() { return "f32"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("f32")); }
		static const Detail<f32> Details;
		static int64 Size() { return sizeof(f32); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < f64 >
	{
		static cstring Name() { return "f64"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("f64")); }
		static const Detail<f64> Details;
		static int64 Size() { return sizeof(f64); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < string >
	{
		static cstring Name() { return "string"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("string")); }
		static const Detail<string> Details;
		static int64 Size() { return sizeof(string); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return false; }
	};

	template<> struct TypeInfo < boolean >
	{
		static cstring Name() { return "boolean"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("boolean")); }
		static const Detail<boolean> Details;
		static int64 Size() { return sizeof(boolean); }
		static bool IsCollection() { return false; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return true; }
	};

	template<> struct TypeInfo < cstring >
	{
		static cstring Name() { return "cstring"; }
		static int64 TypeId() { return (int64)(std::hash<cstring>()("cstring")); }
		static const Detail<boolean> Details;
		static int64 Size() { return sizeof(cstring); }
		static bool IsCollection() { return true; }
		static bool IsPointer() { return false; }
		static bool IsPrimitive() { return false; }
	};

	struct ASTARESCORE_API TypeQuery
	{
		cstring GetName() const;
		int64 GetTypeId() const;
		int64 GetSize() const;
		bool GetIsCollection() const;
		bool GetIsPointer() const;
		bool GetIsPrimitive() const;

		template<typename A>
		static TypeQuery Query(const A& a)
		{
			TypeQuery result;
			result.name = TypeInfo<A>::Name();
			result.typeId = TypeInfo<A>::TypeId();
			result.size = TypeInfo<A>::Size();
			result.isCollection = TypeInfo<A>::IsCollection();
			result.isPointer = TypeInfo<A>::IsPointer();
			result.isPrimitive = TypeInfo<A>::IsPrimitive();
			return result;
		}

	private:
		cstring name;
		int64 typeId;
		int64 size;
		bool isCollection;
		bool isPointer;
		bool isPrimitive;
	};

	template<typename T>
	static inline TypeQuery GetType(const T& t) {
		return TypeQuery::Query(t);
	}
}

#ifndef DECL_API_EXTERN_TYPE
#define DECL_TYPE(type) template<> struct TypeInfo<type>\
{\
	static cstring Name() { return #type; }\
	static int64 TypeId() { return (int64)(std::hash<cstring>()(#type)); }\
	static const Detail<type> Details;\
	static int64 Size() { return sizeof(type); }\
	static bool IsCollection() { return std::is_array<type>::value; }\
	static bool IsPointer() { return std::is_pointer<type>::value; }\
	static bool IsPrimitive() { return false; }\
};
#endif

#ifndef DECL_API_STL
#define DECL_API_STL(api, type) TEMPLATE_EXTERN template class api std::vector<type>;
#endif

#ifndef DECL_CORE_STL
#define DECL_CORE_STL(type) DECL_API_STL(ASTARESCORE_API, type)
#endif

#ifndef DECL_CORE_TYPE
#define DECL_CORE_TYPE(type) DECL_TYPE(type) DECL_CORE_STL(type)
#endif

#ifndef DECL_TYPE_FULL
#define DECL_TYPE_FULL(type) DECL_TYPE(type) DECL_API_STL(,type)
#endif

#include "Enum.h"

#endif