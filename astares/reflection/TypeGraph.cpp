#include "TypeGraph.h"
#include "IType.h"
#include <sstream>

TypeGraph* TypeGraph::__instance;

TypeGraph::TypeGraph() {
	for (auto kvp : idTypeMap) {
		delete kvp.second;
	}
	idTypeMap.clear();

	delete __instance;
	__instance = nullptr;
}

TypeGraph& TypeGraph::Get() {
	if (__instance == nullptr){
		__instance = new TypeGraph();
	}
	return *__instance;
}

void TypeGraph::Add(IType* type) {
	if (idTypeMap.find(type->GetTypeId()) == idTypeMap.cend())
	{
		idTypeMap[type->GetTypeId()] = type;
	}
	else {
		printf("Collision: (%i, %s)\r\n", type->GetTypeId(), type->GetTypeName().c_str());
	}
}


const IType* TypeGraph::Get(unsigned long typeId) const {
	if (idTypeMap.find(typeId) != idTypeMap.end()) {
		return idTypeMap.at(typeId);
	}
	else {
		return nullptr;
	}
}

String TypeGraph::ToString() const {
	std::stringstream ss;

	ss << "All Registered Types:" << std::endl;

	for (auto kvp : idTypeMap) {
		ss << "{" << (unsigned long)kvp.first << "}"
			<< std::endl
			<< "\t" << "Name: " << kvp.second->GetTypeName() << std::endl
			<< "\t" << "Size: " << kvp.second->GetSize() << std::endl << std::endl;
	}

	return ss.str();
}

TypeGraph::~TypeGraph() {
}