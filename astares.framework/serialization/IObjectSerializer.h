#ifndef IOBJECTSERIALIZER_H
#define IOBJECTSERIALIZER_H

#include <core/Types.h>
#include "../astares.framework.h"

struct ASTARESFRAMEWORK_API IObjectSerializer
{
	virtual ~IObjectSerializer(){}
	virtual void Serialize(const class Object* input, std::ostream& output) const = 0;
	virtual void Deserialize(class Object* output, std::istream& input) const = 0;
};


#endif