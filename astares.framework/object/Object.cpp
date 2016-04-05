#include "Object.h"
#include "../reflection/Reflection.h"
#include <iostream>
#include "../serialization/StringHelper.h"

void Object::Serialize(WriteStream& out, const int32& version) const {
	PreSerialize(out, version);
	InternalSerialize(out, version);
	PostSerialize(out, version);
}

void Object::Deserialize(ReadStream& in, const int32& version) {
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
	return string(Variant(*this, true).GetName())
		.append("__")
		.append(instanceId.ToString());
}

const UID& Object::GetInstanceId() const { return instanceId; }

Object* Object::CreateDefault() const
{
	return new Object();
}

void Object::PostSerialize(WriteStream& out, const int32& version) const
{

}

void Object::PreSerialize(WriteStream& out, const int32& version) const
{

}

void Object::PostDeserialize(ReadStream& in, const int32& version)
{

}

void Object::PreDeserialize(ReadStream& in, const int32& version)
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

WriteStream& operator << (WriteStream& out, const vector<Object*>& arr) {
	out << arr.size() << ' ';
	for (auto* elem : arr) 
	{
		elem->Serialize(out, 0);
		out << ' ';
	}
	return out;
}

ReadStream& operator >> (ReadStream& in, vector<Object*>& arr) {
	size_t size = 0;
	in >> size;
	if (arr.size() == size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			arr[i]->Deserialize(in, 0);
		}
	}
	return in;
}

WriteStream& operator << (WriteStream& out, const string& arr)
{
	string temp = StringHelper::Encode(arr);
	out.write(temp.c_str(), sizeof(string::_Alloc::value_type) * temp.size());
	return out;
}

ReadStream& operator >> (ReadStream& in, string& arr)
{
	string temp;
	char c;
	in.readsome(&c, 1);
	in.readsome(&c, 1);
	while (c != ' ')
	{
		temp.push_back(c);
		in.readsome(&c, 1);
	}
	arr = StringHelper::Decode(temp);
	return in;
}