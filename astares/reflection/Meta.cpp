#include "Meta.h"
#include "MetaGraph.h"


Meta::Meta(String name, unsigned long typeId) : 
	name(name),
	typeId(typeId)
{
	MetaGraph::Get().Add(this);
}

Meta::~Meta() {

}

const String Meta::GetName() const {
	return name; 
}

const long Meta::GetTypeId() const { 
	return typeId; 
}

bool Meta::Read(void* obj, std::istream& in, int version) {
	in >> name >> typeId;
	return true;
}

bool Meta::Write(void* obj, std::ostream& out, int version) const {
	out << name << ' ' << typeId << ' ';
	return true;
}