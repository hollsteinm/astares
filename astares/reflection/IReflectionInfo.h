#ifndef IREFLECTIONINFO_H
#define IREFLECTIONINFO_H

#include "PropertyVariant.h"

struct IReflectionInfo {
	virtual Variant& GetProperty(string name) = 0;
	virtual void SetProperty(string name, const Variant& newValue) = 0;

	virtual std::vector<PropertyVariant> GetProperties() = 0;

	virtual int64 GetCustomType() const = 0;
	virtual int64 GetType() const = 0;
	virtual string GetName() const = 0;
};

#endif