#ifndef TYPE_H
#define TYPE_H

#include "IType.h"

static long MakeTypeHash(std::string constantName) {
	return std::hash<std::string>()(constantName);
}

template<typename T>
struct Type : public IType {
	Type(String constantName) :
		name(constantName),
		typeId(MakeTypeHash(constantName)),
		size(sizeof(T))
	{
		TypeGraph::Get().Add(this);
	}

	long GetTypeId() const override { return typeId; }
	String GetTypeName() const override { return name; }
	size_t GetSize() const override { return size; }

	bool IsTypeOf(IType* other) const override {
		return other->GetTypeId() == typeId;
	}

private:
	unsigned long typeId;
	String name;
	size_t size;
};



#endif