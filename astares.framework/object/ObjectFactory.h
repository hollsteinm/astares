#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "../astares.framework.h"
#include <core/UID.h>

class ObjectFactory;
class Object;
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, ObjectFactory)
DECL_API_STL_MAP(ASTARESFRAMEWORK_API, string, int64)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, Object)
typedef std::shared_ptr<Object> ObjectPtr;
DECL_API_STL_MAP(ASTARESFRAMEWORK_API, int64, ObjectPtr)
DECL_API_STL_MAP(ASTARESFRAMEWORK_API, UID, ObjectPtr)

class ASTARESFRAMEWORK_API ObjectFactory {
public:
	static std::shared_ptr<ObjectFactory> Get();

	std::weak_ptr<class Object> GetDefault(string name);
	std::shared_ptr<class Object> CreateNew(string name);
	std::weak_ptr<class Object> GetDefault(int64 typeId);
	std::shared_ptr<class Object> CreateNew(int64 typeId);

	template<typename T>
	std::shared_ptr<T> CreateNew() {
		return std::dynamic_pointer_cast<T>(CreateNew(VariantTypeId<T>::GetCustomType()));
	}

	void Add(string name, int64 typeId, std::weak_ptr<Object> defaultObject);

	~ObjectFactory();

	ObjectFactory(const ObjectFactory& rhs) = delete;
	ObjectFactory& operator = (const ObjectFactory & rhs) = delete;

	void Register(class Object* obj);
	void Unregister(class Object* obj);

	std::weak_ptr<class Object> GetLive(const UID& id) const;
	gate TryGetLive(const UID& id, std::weak_ptr<class Object>& obj) const;

	string ToString() const;

private:
	ObjectFactory();

	static std::shared_ptr<ObjectFactory> __instance;
	std::map<string, int64> NameIdGraph;
	std::map<int64, std::shared_ptr<class Object>> Graph;
	std::map<UID, std::shared_ptr<class Object>> LiveObjectGraph;
};

template<typename T>
static inline std::shared_ptr<T> NewObject()
{
	auto res = ObjectFactory::Get()->CreateNew<T>();
	ObjectFactory::Get()->Register(res.get());
	return res;
}

#ifndef REGISTER_TYPE
#define REGISTER_TYPE(type) ObjectFactory::Get()->Add(#type, VariantTypeId<type>::GetCustomType(), std::make_shared<type>(type()));
#endif

#ifndef NEW
#define NEW(type) NewObject<type>()
#endif

#ifndef DEL
#define DEL(obj) ObjectFactory::Get()->Unregister(obj.get())
#endif

#endif