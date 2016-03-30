#include "Object.h"
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
	this->InternalReflect(reflector);
}

Object::Object()
{
	instanceId = UID::Make();
}

Object::~Object()
{

}

string Object::ToString() const {
	return string(Variant(*this).GetName())
		.append("__")
		.append(instanceId.ToString());
}

const UID& Object::GetInstanceId() const { return instanceId; }

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

bool Object::operator==(const Object& rhs) const
{
	return instanceId == rhs.instanceId;
}

bool Object::operator!=(const Object& rhs) const
{
	return instanceId != rhs.instanceId;
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