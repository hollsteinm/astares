#include "Object.h"
#include <iostream>
#include "../serialization/StringHelper.h"

using namespace astares;

Object::Object()
{
	instanceId = UID::Make();
}

Object::~Object()
{

}

string Object::ToString() const {
	return string()
		.append("__")
		.append(instanceId.ToString());
}

const UID& Object::GetInstanceId() const { return instanceId; }

std::unique_ptr<Object> Object::CreateDefault() const
{
	return std::make_unique<Object>();
}

void Object::PostSerialize(std::ostream& out, const int32& version) const
{

}

void Object::PreSerialize(std::ostream& out, const int32& version) const
{

}

void Object::PostDeserialize(std::istream& in, const int32& version)
{

}

void Object::PreDeserialize(std::istream& in, const int32& version)
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