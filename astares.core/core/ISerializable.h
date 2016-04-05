#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include "Types.h"

struct ASTARESCORE_API ISerializable
{
	ISerializable();
	ISerializable(const ISerializable& other);
	virtual ~ISerializable();
	virtual void Serialize(WriteStream& out, const int32& version) const = 0;
	virtual void Deserialize(ReadStream& in, const int32& version) = 0;
};


#endif