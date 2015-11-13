#ifndef IFIELD_H
#define IFIELD_H

#include <string>
#include "Meta.h"


namespace flags {
	static const int SERIAL_IGNORE = 0;
};

enum class FieldFlags {
	None = 0,
	SerialIgnore = (1 << flags::SERIAL_IGNORE),
	All = ~0
};

struct IField : public Meta {
	IField(std::string name, unsigned long typeId, int flags = (int)FieldFlags::None);

	virtual void* Get(void* obj) const = 0;
	virtual void Set(void* obj, void* value) = 0;

	virtual ~IField();

	bool HasFlag(FieldFlags flag) const;

private:
	int Flags;
};

#endif