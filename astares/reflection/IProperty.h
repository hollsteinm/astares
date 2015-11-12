#ifndef IPROPERTY_H
#define IPROPERTY_H

#include <string>
#include "Meta.h"


namespace flags {
	static const int SERIAL_IGNORE = 0;
};

enum class PropertyFlags {
	None = 0,
	SerialIgnore = (1 << flags::SERIAL_IGNORE),
	All = ~0
};

struct IProperty : public Meta {
	IProperty(std::string name, unsigned long typeId, int flags = (int)PropertyFlags::None);

	virtual void* Get(void* obj) const = 0;
	virtual void Set(void* obj, void* value) = 0;

	virtual ~IProperty();

	bool HasFlag(PropertyFlags flag) const;

private:
	int Flags;
};

#endif