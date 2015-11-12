#include "Class.h"
#include "Meta.h"
#include "IProperty.h"
#include "MetaGraph.h"


Class::Class(std::string name, unsigned long typeId) :
	Meta(name, typeId),
	Properties()
{
	MetaGraph::Get().Add(this);
}

Class::~Class() {
	for (auto kvp : Properties) {
		delete kvp.second;
	}
	Properties.clear();
}

void Class::Add(IProperty* prop) {
	if (prop)
	{
		const std::string name = prop->GetName();
		if (Properties.size() <= 0 || Properties.find(name) == Properties.cend())
			Properties[name] = prop;
		else
			delete prop;
	}
}

void Class::Add(unsigned long parentType) {
	bool goOn = true;
	for (auto p : ParentTypes) {
		goOn &= p != parentType;
	}
	if (goOn) {
		ParentTypes.push_back(parentType);
	}
}

std::vector<IProperty*> Class::GetProperties() const {
	std::vector<IProperty*> props;
	for (auto parent : ParentTypes) {
		Class* pClass = (Class*)MetaGraph::Get().Get(parent);
		if (pClass != nullptr) {
			for (auto prop : pClass->GetProperties()) {
				props.push_back(prop);
			}
		}
	}
	for (auto kvp : Properties) {
		props.push_back(kvp.second);
	}
	return props;
}

IProperty* Class::GetProperty(std::string name) const {
	if (Properties.find(name) != Properties.end()){
		return Properties.at(name);
	}
	else {
		for (auto parent : ParentTypes) {
			const Class* pClass = (Class*)MetaGraph::Get().Get(parent);
			if (pClass != nullptr) {
				auto prop = pClass->GetProperty(name);
				if (prop != nullptr) {
					return prop;
				}
			}
		}
		return nullptr;
	}
}

bool Class::Read(void* obj, std::istream& in, int version) {
	if (Meta::Read(obj, in, version)){
		bool result = true;
		std::vector<IProperty*> props = GetProperties();
		int count = props.size();
		for (int i = 0; i < count; ++i) {
			result &= props[i]->Read(obj, in, version);
		}
		return result;
	}
	else {
		return false;
	}
}

bool Class::Write(void* obj, std::ostream& out, int version) const {
	if (Meta::Write(obj, out, version)){
		bool result = true;
		std::vector<IProperty*> props = GetProperties();
		int count = props.size();
		for (int i = 0; i < count; ++i) {
			result &= props[i]->Write(obj, out, version);
		}
		return result;
	}
	else {
		return false;
	}
}