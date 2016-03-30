#ifndef OBJECT_H
#define OBJECT_H

#include "../reflection/Variant.h"

class ASTARESFRAMEWORK_API Object {
private:
	UID instanceId;

public:
	Object();
	virtual ~Object();

	const UID& GetInstanceId() const;

	virtual Object* CreateDefault() const;

	virtual string ToString() const;

	void Serialize(WriteStream& out, int32 version) const;
	void Deserialize(ReadStream& in, int32 version);

	void Reflect(struct IReflector* reflector) const;

	friend ASTARESFRAMEWORK_API WriteStream& operator << (WriteStream& out, const Object& obj);
	friend ASTARESFRAMEWORK_API ReadStream& operator >> (ReadStream& in, Object& obj);

	bool operator==(const Object& rhs) const;
	bool operator!=(const Object& rhs) const;

protected:
	virtual void PostSerialize(WriteStream& out, int32 version) const;
	virtual void PreSerialize(WriteStream& out, int32 version) const;
	virtual void InternalSerialize(WriteStream& out, int32 version) const;

	virtual void InternalDeserialize(ReadStream& in, int32 version);
	virtual void PostDeserialize(ReadStream& in, int32 version);
	virtual void PreDeserialize(ReadStream& in, int32 version);

	virtual void InternalReflect(struct IReflector* reflector) const;
};

DECL_VARIANT(Object)

#ifndef REFLECTABLE
#define REFLECTABLE virtual void InternalReflect(struct IReflector* reflector) const override;
#endif

#ifndef SERIALIZEABLE
#define SERIALIZEABLE(type) virtual void InternalDeserialize(ReadStream& in, int32 version) override; \
	virtual void InternalSerialize(WriteStream& out, int32 version) const override; \
	friend WriteStream& operator<<(WriteStream& out, const type& obj); \
	friend ReadStream& operator>>(ReadStream& in, type& obj);
#endif

#ifndef START_SERIAL
#define START_SERIAL(type) WriteStream& operator <<(WriteStream& out, const type& obj) { obj.Serialize(out, 0); return out; } \
	void type::InternalSerialize(WriteStream& out, int32 version) const { out << VariantTypeId<type>().GetCustomType() << ' ';
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
#define START_DESERIAL(type) ReadStream& operator >> (ReadStream& in, type& obj) { obj.Deserialize(in, 0); return in; } \
	void type::InternalDeserialize(ReadStream& in, int32 version) { int64 whattoDo; in >> whattoDo;
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