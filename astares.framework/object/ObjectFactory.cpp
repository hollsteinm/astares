#include "ObjectFactory.h"
#include "Object.h"
#include <sstream>

std::shared_ptr<ObjectFactory> ObjectFactory::__instance;

#ifndef null_ptr
#define null_ptr std::shared_ptr < Object >()
#endif

std::shared_ptr<ObjectFactory> ObjectFactory::Get() {
	if (!__instance) {
		__instance = std::shared_ptr<ObjectFactory>(new ObjectFactory());
		auto var = Variant(Object(), true);
		__instance->Add(var.GetName(), var.GetCustomType(), std::make_shared<Object>());
	}
	return __instance;
}

std::shared_ptr<Object> ObjectFactory::GetDefault(std::string name) {
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

std::shared_ptr<Object> ObjectFactory::GetDefault(int64 typeId) {
	if (Graph.find(typeId) != Graph.end()) {
		return Graph.at(typeId);
	}
	else {
		return null_ptr;
	}
}

std::shared_ptr<Object> ObjectFactory::CreateNew(int64 typeId) {
	auto original = std::shared_ptr<Object>(GetDefault(typeId));
	if (original) {
		auto newObj = std::shared_ptr<Object>(original->CreateDefault());
		LiveObjectGraph.emplace(std::make_pair(newObj->GetInstanceId(), newObj));
		return newObj;
	}
	else {
		return nullptr;
	}
}

void ObjectFactory::Add(std::string name, int64 typeId, std::shared_ptr<Object> obj) {
	if (obj._Get() != nullptr)
	{
		if (Graph.find(typeId) == Graph.end())
		{
			Graph[typeId] = obj;
			NameIdGraph[name] = typeId;
		}
	}
}

void ObjectFactory::Register(std::shared_ptr<Object> obj) {
	if (obj)
	{
		auto id = obj->GetInstanceId();
		if (LiveObjectGraph.find(id) == LiveObjectGraph.cend()) {
			LiveObjectGraph[id] = obj;
		}
	}
}

void ObjectFactory::Unregister(std::shared_ptr<Object> obj) {
	if (obj)
	{
		auto id = obj->GetInstanceId();
		if (LiveObjectGraph.find(id) != LiveObjectGraph.cend()) {
			LiveObjectGraph.erase(id);
		}
	}
}

std::shared_ptr<Object> ObjectFactory::GetLive(const UID& id) const {
	if (LiveObjectGraph.find(id) != LiveObjectGraph.cend()) {
		return LiveObjectGraph.at(id);
	}
	else {
		return null_ptr;
	}
}

bool ObjectFactory::TryGetLive(const UID& id, std::shared_ptr<Object>& obj) const {
	obj = GetLive(id);
	return obj ? true : false;
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