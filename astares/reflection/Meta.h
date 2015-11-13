#ifndef META_H
#define META_H

#include "ISerializer.h"
#include "../core/String.h"

struct Meta : public ISerializer {
	Meta(String name, unsigned long typeId);

	virtual ~Meta();

	const String GetName() const;
	const long GetTypeId() const;

	virtual bool Read(void* obj, std::istream& in, int version) override;
	virtual bool Write(void* obj, std::ostream& out, int version) const override;

private:
	String name;
	unsigned long typeId;
};

#endif