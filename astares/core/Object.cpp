#include "Object.h"
#include "../reflection/IProperty.h"
#include "../reflection/Serialization.h"
#include "../reflection/Property.h"
#include "ObjectFactory.h"
#include "../reflection/MetaGraph.h"



Object Object::Object__static;

Object& Object::StaticInstance() {
	Object::StaticClass();
	return Object__static;
}

Class& Object::StaticClass() {
	static Class Object__class("Object", TYPEOF(Object));
	Object__class.Add(new Property<Object, long>("instanceId", &Object::instanceId));
	MetaGraph::Get().Add(&Object__class);
	return Object__class;
}

//////////////////////////////////////////
//Must be overriden by inherited classes//
//////////////////////////////////////////
Object* Object::CreateSelf() const {
	return new Object();
}

IProperty* Object::GetProperty(std::string name) const {
	return Object::StaticClass().GetProperty(name);
}

std::vector<IProperty*> Object::GetProperties() const {
	return Object::StaticClass().GetProperties();
}

const std::string Object::GetName() const {
	return Object::StaticClass().GetName();
}

const long Object::GetTypeId() const {
	return TYPEOF(Object);
}

bool Object::InternalWrite(std::ostream& out) {
	return Object::StaticClass().Write(this, out, VERSION);
}

bool Object::InternalRead(std::istream& in) {
	return Object::StaticClass().Read(this, in, VERSION);
}
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
bool Object::Write(std::ostream& out) {
	PreSerialize(out);
	bool res = InternalWrite(out);
	PostSerialize(out);
	return res;
}

bool Object::Read(std::istream& in) {
	PreDeserialize(in);
	bool res = InternalRead(in);
	PostDeserialize(in);
	return res;
}

Object::Object() {
	instanceId = ++GInstances;
	ObjectFactory* factory = &ObjectFactory::Get();
	factory->Add("Object", &Object__static);
	factory->Register(this);
}

bool Object::InstanceOf(Object* other) {
	return other->instanceId == instanceId;
}

const IType* Object::GetType() {
	return TypeGraph::Get().Get(GetTypeId());
}

long Object::GetId() const {
	return instanceId;
}

std::ostream& operator<<(std::ostream& out, Object& self) {
	self.Write(out);
	return out;
}

std::istream& operator>>(std::istream& in, Object& self) {
	self.Read(in);
	return in;
}

Object::~Object(){
	ObjectFactory::Get().Unregister(this);
}

void Object::PostDeserialize(std::istream& in) {

}

void Object::PreDeserialize(std::istream& in) {

}

void Object::PostSerialize(std::ostream& out) {

}

void Object::PreSerialize(std::ostream& out) {

}