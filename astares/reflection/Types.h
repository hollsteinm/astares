#ifndef TYPES_H
#define TYPES_H

#include "TypeGraph.h"
#include "IType.h"
#include "Type.h"

namespace type {
	template<typename T>
	inline const IType* GetType() {
		static const Type<T> Zero__type("Zero");
		return &Zero__type;
	}
}


#define TYPE(T) namespace type{ \
	template<> \
	inline const IType* GetType<T>() { \
		static const Type<T> thetype(#T);\
		return &thetype; \
	}\
}

#define TYPEOF(T) type::GetType<T>()->GetTypeId()
#define TYPENAME(T) type::GetType<T>()->GetTypeName()
#define TYPESIZE(T) type::GetType<T>()->GetSize()

struct Null{};

TYPE(Null)
TYPE(int)
TYPE(long)
TYPE(char)
TYPE(bool)
TYPE(float)
TYPE(double)

namespace type {
	__forceinline static const IType* GetType(unsigned long typeId) { return TypeGraph::Get().Get(typeId); }
	__forceinline static const String GetName(unsigned long typeId) { return TypeGraph::Get().Get(typeId)->GetTypeName(); }
}

#define GREEDY_LOAD_CORE_TYPES TYPEOF(Null); TYPEOF(int); TYPEOF(long); TYPEOF(char); TYPEOF(bool); TYPEOF(float); TYPEOF(double);


#endif