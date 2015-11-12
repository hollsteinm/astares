#ifndef META_H
#define META_H

#include "ISerializer.h"
#include <string>

struct Meta : public ISerializer {
	Meta(std::string name, unsigned long typeId);

	virtual ~Meta();

	const std::string GetName() const;
	const long GetTypeId() const;

	virtual bool Read(void* obj, std::istream& in, int version) override;
	virtual bool Write(void* obj, std::ostream& out, int version) const override;

private:
	std::string name;
	unsigned long typeId;
};

#endif