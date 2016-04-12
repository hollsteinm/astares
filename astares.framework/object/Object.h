#ifndef OBJECT_H
#define OBJECT_H

#include "../reflection/Variant.h"
#include <functional>

class ASTARESFRAMEWORK_API Object : public ISerializable{
private:
	UID instanceId;

public:
	Object();
	virtual ~Object();

	const UID& GetInstanceId() const;

	virtual std::unique_ptr<Object> CreateDefault() const;

	virtual string ToString() const;

	void Serialize(WriteStream& out, const int32& version) const override;
	void Deserialize(ReadStream& in, const int32& version) override;

	void Reflect(std::shared_ptr<struct IReflector> reflector) const;

	friend ASTARESFRAMEWORK_API WriteStream& operator << (WriteStream& out, const Object& obj);
	friend ASTARESFRAMEWORK_API ReadStream& operator >> (ReadStream& in, Object& obj);

	bool operator==(const Object& rhs) const;
	bool operator!=(const Object& rhs) const;

protected:
	virtual void PostSerialize(WriteStream& out, const int32& version) const;
	virtual void PreSerialize(WriteStream& out, const int32& version) const;
	virtual void InternalSerialize(WriteStream& out, const int32& version) const;

	virtual void InternalDeserialize(ReadStream& in, const int32& version);
	virtual void PostDeserialize(ReadStream& in, const int32& version);
	virtual void PreDeserialize(ReadStream& in, const int32& version);

	virtual void InternalReflect(std::shared_ptr<struct IReflector> reflector) const;
};

DECL_VARIANT(Object)

#ifndef PRODUCTABLE
#define PRODUCTABLE virtual std::unique_ptr<Object> CreateDefault() const override;
#endif

#ifndef PRODUCE
#define PRODUCE(type) std::unique_ptr<Object> type::CreateDefault() const { return std::make_unique<type>(type()); }
#endif

#ifndef REFLECTABLE
#define REFLECTABLE virtual void InternalReflect(std::shared_ptr<struct IReflector> reflector) const override;
#endif

#ifndef SERIALIZEABLE
#define SERIALIZEABLE(type) virtual void InternalDeserialize(ReadStream& in, const int32& version) override; \
	virtual void InternalSerialize(WriteStream& out, const int32& version) const override; \
	friend WriteStream& operator<<(WriteStream& out, const type& obj); \
	friend ReadStream& operator>>(ReadStream& in, type& obj);
#endif

#ifndef START_SERIAL
#define START_SERIAL(type) WriteStream& operator <<(WriteStream& out, const type& obj) { obj.Serialize(out, 0); return out; } \
	void type::InternalSerialize(WriteStream& out, const int32& version) const { out << VariantTypeId<type>().GetCustomType() << ' ';
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
	void type::InternalDeserialize(ReadStream& in, const int32& version) { int64 whattoDo; in >> whattoDo;
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

ASTARESFRAMEWORK_API
WriteStream& operator << (WriteStream& out, const vector<Object*>& arr);

ASTARESFRAMEWORK_API
ReadStream& operator >> (ReadStream& in, vector<Object*>& arr);

ASTARESFRAMEWORK_API
WriteStream& operator << (WriteStream& out, const string& arr);

ASTARESFRAMEWORK_API
ReadStream& operator >> (ReadStream& in, string& arr);

#endif