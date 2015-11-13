#include "MetaGraph.h"
#include "Class.h"
#include "Types.h"

MetaGraph* MetaGraph::__instance;

MetaGraph::MetaGraph() {
}

MetaGraph::~MetaGraph() {
	for (auto kvp : Classes) {
		delete kvp.second;
	}
	Classes.clear();

	delete __instance;
	__instance = nullptr;
}

MetaGraph& MetaGraph::Get() {
	if (__instance == nullptr){
		__instance = new MetaGraph();
	}
	return *__instance;
}

void MetaGraph::Add(Meta* Class) {
	unsigned long typeId = Class->GetTypeId();
	if (Classes.find(typeId) == Classes.end()){
		Classes[typeId] = Class;
	}
}

Meta* MetaGraph::Get(unsigned long typeId) const {
	if (Classes.find(typeId) != Classes.end()) {
		return Classes.at(typeId);
	}
	else {
		return nullptr;
	}
}

Meta* MetaGraph::Get(String name) const {
	for (auto C : Classes) {
		if (C.second->GetName() == name) {
			return C.second;
		}
	}
	return nullptr;
}

Array<long> MetaGraph::AllTypeIds() const {
	Array<long> res;
	for (auto C : Classes) {
		res.push_back(C.first);
	}
	return res;
}