#include "ObjectFactory.h"
#include "../reflection/IType.h"
#include "../reflection/MetaGraph.h"
#include "Object.h"

#include <sstream>


ObjectFactory* ObjectFactory::__instance;

ObjectFactory& ObjectFactory::Get() {
	if (__instance == nullptr) {
		__instance = new ObjectFactory();
	}
	return *__instance;
}

Object* ObjectFactory::GetDefault(String name) {
	if (Graph.find(name) != Graph.end()) {
		return Graph.at(name);
	}
	else {
		return nullptr;
	}
}

Object* ObjectFactory::CreateNew(String name) {
	Object* original = GetDefault(name);
	if (original != nullptr) {
		return original->CreateSelf();
	}
	else {
		return nullptr;
	}
}

Object* ObjectFactory::GetDefault(unsigned long typeId) {
	auto c = MetaGraph::Get().Get(typeId);
	if (c) {
		return GetDefault(c->GetName());
	}
	else {
		return nullptr;
	}
}

Object* ObjectFactory::CreateNew(unsigned long typeId) {
	auto c = MetaGraph::Get().Get(typeId);
	if (c) {
		return CreateNew(c->GetName());
	}
	else {
		return nullptr;
	}
}

void ObjectFactory::Add(String name, Object* obj) {
	if (obj)
	{
		if (Graph.find(name) == Graph.end()) {
			Graph[name] = obj;
		}
	}
}

void ObjectFactory::Register(class Object* obj) {
	long id = obj->GetId();
	if (LiveObjectGraph.find(id) == LiveObjectGraph.cend()) {
		LiveObjectGraph[id] = obj;
	}
}

void ObjectFactory::Unregister(class Object* obj) {
	long id = obj->GetId();
	if (LiveObjectGraph.find(id) != LiveObjectGraph.cend()) {
		LiveObjectGraph.erase(id);
	}
}

Object* ObjectFactory::GetLive(long id) const {
	if (LiveObjectGraph.find(id) != LiveObjectGraph.cend()) {
		return LiveObjectGraph.at(id);
	}
	else {
		return nullptr;
	}
}

bool ObjectFactory::TryGetLive(long id, Object* obj) const {
	obj = GetLive(id);
	return obj != nullptr;
}

ObjectFactory::~ObjectFactory() {
	for (auto kvp : LiveObjectGraph) {
		delete kvp.second;
	}

	for (auto kvp : Graph) {
		delete kvp.second;
	}

	LiveObjectGraph.clear();
	Graph.clear();

	delete __instance;
	__instance = nullptr;
}

ObjectFactory::ObjectFactory() {
}

String ObjectFactory::ToString() const {
	std::stringstream ss;

	String s = "Registered Object Types:\n";
	
	for (auto kvp : Graph) {
		s.append("\t").append(kvp.first).append("\n");
	}

	s.append("\nLive Objects:\n")
		.append("Count:\t")
		.append(std::to_string(LiveObjectGraph.size()))
		.append("\tTotal Memory (bytes):\t");

	size_t size = 0;

	for (auto kvp : Graph) {
		size += sizeof(*kvp.second);
		kvp.second->Write(ss);
		ss << std::endl << std::endl;
	}

	s.append(std::to_string(size))
		.append("\n\n")
		.append(ss.str())
		.append("\n");

	ss.clear();

	return s;	
}