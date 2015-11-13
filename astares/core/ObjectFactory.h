#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "../core/String.h"
#include <map>


class ObjectFactory {
public:
	static ObjectFactory& Get();

	class Object* GetDefault(String name);
	class Object* CreateNew(String name);
				
	class Object* GetDefault(unsigned long typeId);
	class Object* CreateNew(unsigned long typeId);

	void Add(String name, class Object* obj);

	~ObjectFactory();

	ObjectFactory(const ObjectFactory& rhs) = delete;
	ObjectFactory& operator = (const ObjectFactory & rhs) = delete;

	void Register(class Object* obj);
	void Unregister(class Object* obj);

	Object* GetLive(long id) const;
	bool TryGetLive(long id, class Object* obj) const;

	String ToString() const;

private:
	ObjectFactory();

	static ObjectFactory* __instance;
	std::map<std::string, class Object*> Graph;

	std::map<long, class Object*> LiveObjectGraph;
};

#endif