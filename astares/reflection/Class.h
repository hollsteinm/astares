#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include "../core/String.h"
#include <map>
#include "Meta.h"


struct IField;

struct Class : public Meta {
	Class(String name, unsigned long typeId);
	~Class();

	void Add(IField* field);
	void Add(unsigned long parentType);

	std::vector<IField*> GetFields() const;
	IField* GetField(String name) const;

	virtual bool Read(void* obj, std::istream& in, int version) override;
	virtual bool Write(void* obj, std::ostream& out, int version) const override;

private:
	std::map<std::string, IField*> Fields;
	std::vector<unsigned long> ParentTypes;
};


#endif