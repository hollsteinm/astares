#ifndef FIELD_H
#define FIELD_H

#include "IField.h"
#include "Types.h"

template<typename C, typename P>
struct Field : public IField {
	Field(String name, P C::*fielderty, int flags = 0) :
		IField(name, TYPEOF(P), flags),
		fielderty(fielderty)
	{}

	void* Get(void* obj) const override {
		P ret = InternalGet(*(C*)obj);
		P* ptr = &ret;
		return (void*)ptr;
	}

	void Set(void* obj, void* value) override {
		return InternalSet(*(C*)obj, *(P*)value);
	}

	virtual bool Read(void* obj, std::istream& in, int version) override {
		if (HasFlag(FieldFlags::SerialIgnore)) return true;
		if (IField::Read(obj, in, version)) {
			P v;
			in >> v;
			InternalSet(*(C*)obj, v);
			return true;
		}
		else {
			return false;
		}
	}

	virtual bool Write(void* obj, std::ostream& out, int version) const override {
		if (HasFlag(FieldFlags::SerialIgnore)) return true;
		if (IField::Write(obj, out, version)) {
			P v = InternalGet(*(C*)obj);
			out << v << ' ';
			return true;
		}
		else {
			return false;
		}
	}

protected:
	P InternalGet(C& obj) const {
		return obj.*fielderty;
	}

	void InternalSet(C& obj, P value) {
		obj.*fielderty = value;
	}

private:
	P C::*fielderty;
};
#endif