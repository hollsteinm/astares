#ifndef OBJECT_H
#define OBJECT_H

#include "../reflection/Variant.h"

class Object {
private:
	int64 instanceId;

public:
	Object();
	virtual ~Object();

	const int64 GetInstanceId() const;

	virtual Object* CreateDefault() const;

	virtual string ToString() const;

	void Serialize(std::ostream& out, int32 version) const;
	void Deserialize(std::istream& in, int32 version);

	void Reflect(struct IReflector* reflector) const;

	friend std::ostream& operator << (std::ostream& out, const Object& obj);
	friend std::istream& operator >> (std::istream& in, Object& obj);

protected:
	virtual void PostSerialize(std::ostream& out, int32 version) const;
	virtual void PreSerialize(std::ostream& out, int32 version) const;
	virtual void InternalSerialize(std::ostream& out, int32 version) const;

	virtual void InternalDeserialize(std::istream& in, int32 version);
	virtual void PostDeserialize(std::istream& in, int32 version);
	virtual void PreDeserialize(std::istream& in, int32 version);

	virtual void InternalReflect(struct IReflector* reflector) const;
};

DECL_VARIANT(Object)

#ifndef REFLECTABLE
#define REFLECTABLE virtual void InternalReflect(struct IReflector* reflector) const override;
#endif

#ifndef SERIALIZEABLE
#define SERIALIZEABLE(type) virtual void InternalDeserialize(std::istream& in, int32 version) override; \
	virtual void InternalSerialize(std::ostream& out, int32 version) const override; \
	friend std::ostream& operator << (std::ostream& out, const type& obj); \
	friend std::istream& operator >> (std::istream& in, type& obj);
#endif

#ifndef START_SERIAL
#define START_SERIAL(type) std::ostream& operator <<(std::ostream& out, const type& obj) { obj.Serialize(out, 0); return out; } \
	void type::InternalSerialize(std::ostream& out, int32 version) const { out << VariantTypeId<type>().GetCustomType() << ' ';
#endif

#ifndef PARENT_SERIAL
#define PARENT_SERIAL(o) o::InternalSerialize(out, version);
#endif

#ifndef WRITE
#define WRITE(prop) out << prop << ' ';
#endif

#ifndef END_SERIAL
#define END_SERIAL }
#endif

#ifndef START_DESERIAL
#define START_DESERIAL(type) std::istream& operator >> (std::istream& in, type& obj) { obj.Deserialize(in, 0); return in; } \
	void type::InternalDeserialize(std::istream& in, int32 version) { int64 whattoDo; in >> whattoDo;
#endif

#ifndef PARENT_DESERIAL
#define PARENT_DESERIAL(o) o::InternalDeserialize(in, version);
#endif

#ifndef READ
#define READ(prop) in >> prop;
#endif

#ifndef END_DESERIAL
#define END_DESERIAL }
#endif

#endif