#include "IProperty.h"
#include "Meta.h"


IProperty::IProperty(std::string name, unsigned long typeId, int flags) :
	Meta(name, typeId),
	Flags(flags)
{}

IProperty::~IProperty() {

}

bool IProperty::HasFlag(PropertyFlags flag) const {
	return (Flags & (int)flag) > 0;
}