#ifndef ITYPE_H
#define ITYPE_H

#include "../core/String.h"

struct IType {
	virtual ~IType() {}
	virtual long GetTypeId() const = 0;
	virtual bool IsTypeOf(IType* other) const = 0;
	virtual String GetTypeName() const = 0;
	virtual size_t GetSize() const = 0;
};
#endif