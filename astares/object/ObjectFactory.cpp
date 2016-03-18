#include "ObjectFactory.h"
#include "Object.h"
#include <sstream>

std::shared_ptr<ObjectFactory> ObjectFactory::__instance;

#ifndef null_ptr
#define null_ptr std::weak_ptr < Object >()
#endif

ObjectFactory& ObjectFactory::Get() {
	if (__instance) {
		__instance = std::shared_ptr<ObjectFactory>(new ObjectFactory());
		auto var = Variant(Object());
		__instance->Add(var.GetName(), var.GetCustomType(), new Object());
	}
	return *__instance;
}

std::weak_ptr<Object> ObjectFactory::GetDefault(std::string name) {
	if (NameIdGraph.find(name) != NameIdGraph.end()) {
		return GetDefault(NameIdGraph[name]);
	}
	else {
		return null_ptr;
	}
}

std::shared_ptr<Object> ObjectFactory::CreateNew(std::string name) {
	if (NameIdGraph.find(name) != NameIdGraph.end()) {
		return CreateNew(NameIdGraph[name]);
	}
	else {
		return nullptr;
	}
}

std::weak_ptr<Object> ObjectFactory::GetDefault(int64 typeId) {
	if (Graph.find(typeId) != Graph.end()) {
		return Graph.at(typeId);
	}
	else {
		return null_ptr;
	}
}

std::shared_ptr<Object> ObjectFactory::CreateNew(int64 typeId) {
	auto original = std::shared_ptr<Object>(GetDefault(typeId));
	if (original._Get() != nullptr) {
		return std::shared_ptr<Object>(original->CreateDefault());
	}
	else {
		return nullptr;
	}
}

void ObjectFactory::Add(std::string name, int64 typeId, Object* obj) {
	if (obj)
	{
		if (Graph.find(typeId) == Graph.end())
		{
			Graph[typeId] = std::shared_ptr<Object>(obj);
			NameIdGraph[name] = typeId;
		}
	}
}

void ObjectFactory::Register(Object* obj) {
	if (obj)
	{
		long id = obj->GetInstanceId();
		if (LiveObjectGraph.find(id) == LiveObjectGraph.cend()) {
			LiveObjectGraph[id] = std::shared_ptr<Object>(obj);
		}
	}
}

void ObjectFactory::Unregister(Object* obj) {
	if (obj)
	{
		long id = obj->GetInstanceId();
		if (LiveObjectGraph.find(id) != LiveObjectGraph.cend()) {
			LiveObjectGraph.erase(id);
		}
	}
}

std::weak_ptr<Object> ObjectFactory::GetLive(long id) const {
	if (LiveObjectGraph.find(id) != LiveObjectGraph.cend()) {
		return LiveObjectGraph.at(id);
	}
	else {
		return null_ptr;
	}
}

bool ObjectFactory::TryGetLive(long id, std::weak_ptr<Object>& obj) const {
	obj = GetLive(id);
	return obj._Get() != nullptr;
}

ObjectFactory::~ObjectFactory() {
	LiveObjectGraph.clear();
	Graph.clear();
}

ObjectFactory::ObjectFactory() {
}

std::string ObjectFactory::ToString() const {
	std::stringstream ss;

	std::string s = "Registered Object Types:\n";
	
	for (auto kvp : Graph) {
		s.append("\t")
			.append(std::to_string(kvp.first))
			.append("\n");
	}

	s.append("\nLive Objects:\n")
		.append("Count:\t")
		.append(std::to_string(LiveObjectGraph.size()))
		.append("\tTotal Memory (bytes):\t");

	size_t size = 0;

	for (auto kvp : Graph) {
		size += sizeof(*kvp.second);
		kvp.second->Serialize(ss, 0);
		ss << std::endl << std::endl;
	}

	s.append(std::to_string(size))
		.append("\n\n")
		.append(ss.str())
		.append("\n");

	ss.clear();

	return s;	
}