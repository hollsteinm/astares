#include "Class.h"
#include "Meta.h"
#include "IField.h"
#include "MetaGraph.h"


Class::Class(String name, unsigned long typeId) :
	Meta(name, typeId),
	Fields()
{
	MetaGraph::Get().Add(this);
}

Class::~Class() {
	for (auto kvp : Fields) {
		delete kvp.second;
	}
	Fields.clear();
}

void Class::Add(IField* field) {
	if (field)
	{
		const String name = field->GetName();
		if (Fields.size() <= 0 || Fields.find(name) == Fields.cend())
			Fields[name] = field;
		else
			delete field;
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

std::vector<IField*> Class::GetFields() const {
	std::vector<IField*> fields;
	for (auto parent : ParentTypes) {
		Class* pClass = (Class*)MetaGraph::Get().Get(parent);
		if (pClass != nullptr) {
			for (auto field : pClass->GetFields()) {
				fields.push_back(field);
			}
		}
	}
	for (auto kvp : Fields) {
		fields.push_back(kvp.second);
	}
	return fields;
}

IField* Class::GetField(String name) const {
	if (Fields.find(name) != Fields.end()){
		return Fields.at(name);
	}
	else {
		for (auto parent : ParentTypes) {
			const Class* pClass = (Class*)MetaGraph::Get().Get(parent);
			if (pClass != nullptr) {
				auto field = pClass->GetField(name);
				if (field != nullptr) {
					return field;
				}
			}
		}
		return nullptr;
	}
}

bool Class::Read(void* obj, std::istream& in, int version) {
	if (Meta::Read(obj, in, version)){
		bool result = true;
		std::vector<IField*> fields = GetFields();
		int count = fields.size();
		for (int i = 0; i < count; ++i) {
			result &= fields[i]->Read(obj, in, version);
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
		std::vector<IField*> fields = GetFields();
		int count = fields.size();
		for (int i = 0; i < count; ++i) {
			result &= fields[i]->Write(obj, out, version);
		}
		return result;
	}
	else {
		return false;
	}
}