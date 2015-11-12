#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <string>
#include <map>
#include "Meta.h"


struct IProperty;

struct Class : public Meta {
	Class(std::string name, unsigned long typeId);
	~Class();

	void Add(IProperty* prop);
	void Add(unsigned long parentType);

	std::vector<IProperty*> GetProperties() const;
	IProperty* GetProperty(std::string name) const;

	virtual bool Read(void* obj, std::istream& in, int version) override;
	virtual bool Write(void* obj, std::ostream& out, int version) const override;

private:
	std::map<std::string, IProperty*> Properties;
	std::vector<unsigned long> ParentTypes;
};


#endif