#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <core/Types.h>
#include <core/UID.h>

class ObjectFactory {
public:
	static ObjectFactory& Get();

	std::weak_ptr<class Object> GetDefault(string name);
	std::shared_ptr<class Object> CreateNew(string name);
	std::weak_ptr<class Object> GetDefault(int64 typeId);
	std::shared_ptr<class Object> CreateNew(int64 typeId);

	template<typename T>
	std::shared_ptr<T> CreateNew() {
		return CreateNew(VariantTypeId<T>::GetCustomType());
	}

	void Add(string name, int64 typeId, class Object* defaultObject);

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

#ifndef DECL_DEFAULT_INSTANCE
#define DECL_DEFAULT_INSTANCE(o) auto var = Variant(o()); ObjectFactory::Get().Add(var.GetName(), var.GetCustomType(), new o());
#endif

template<typename T>
static inline std::weak_ptr<T> NewObject()
{
	auto res = ObjectFactory::Get().CreateNew<T>();
	ObjectFactory::Get().Register(res);
	return res;
}

#ifndef REGISTER_TYPE
#define REGISTER_TYPE(type) ObjectFactory::Get().Add(VariantTypeId<type>::GetTypeName(), VariantTypeId<type>::GetCustomType(), new type());
#endif

#ifndef NEW
#define NEW(type) NewObject<type>()
#endif

#ifndef DEL
#define DEL(obj) ObjectFactory::Get().Unregister(obj)
#endif

#endif