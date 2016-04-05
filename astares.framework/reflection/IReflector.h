#ifndef IREFLECTOR_H
#define IREFLECTOR_H

#include "PropertyVariant.h"

struct ASTARESFRAMEWORK_API IReflector {
	virtual void SetType(const Variant& variant) = 0;
	virtual void AddProperty(const PropertyVariant& variant) = 0;
};

#ifndef START_PROPERTIES
#define START_PROPERTIES(o) typedef o me; void o::InternalReflect(IReflector* reflector) const { reflector->SetType(Variant(*this, true));
#endif

#ifndef PARENT
#define PARENT(o) o::InternalReflect(reflector);
#endif

#ifndef PROPERTY
#define PROPERTY(name) reflector->AddProperty(PropertyVariant(#name, this, &me::name));
#endif

#ifndef END_PROPERTIES
#define END_PROPERTIES }
#endif

#endif