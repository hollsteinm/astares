#include "Object.h"
#include "../reflection/Reflection.h"

static int64 GInstances = 0;

#include "../reflection/Reflection.h"
#include <iostream>

void Object::Serialize(WriteStream& out, int32 version) const {
	PreSerialize(out, version);
	InternalSerialize(out, version);
	PostSerialize(out, version);
}

void Object::Deserialize(ReadStream& in, int32 version) {
	PreDeserialize(in, version);
	InternalDeserialize(in, version);
	PostDeserialize(in, version);
}

void Object::Reflect(struct IReflector* reflector) const
{
	InternalReflect(reflector);
}

Object::Object()
{
	instanceId = GInstances++;
}

Object::~Object()
{

}

string Object::ToString() const {
	return string(Variant(*this).GetName())
		.append("__")
		.append(std::to_string(instanceId));
}

const int64 Object::GetInstanceId() const { return instanceId; }

Object* Object::CreateDefault() const
{
	return new Object();
}

void Object::PostSerialize(WriteStream& out, int32 version) const
{

}

void Object::PreSerialize(WriteStream& out, int32 version) const
{

}

void Object::PostDeserialize(ReadStream& in, int32 version)
{

}

void Object::PreDeserialize(ReadStream& in, int32 version)
{

}


START_SERIAL(Object)
	WRITE(instanceId)
END_SERIAL

START_DESERIAL(Object)
	READ(instanceId)
END_SERIAL

START_PROPERTIES(Object)
	PROPERTY(instanceId)
END_PROPERTIES