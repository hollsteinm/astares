#ifndef OBJECT_H
#define OBJECT_H

#include "../reflection/Types.h"
#include "../reflection/Class.h"


static long GInstances = 0;

class Object;
TYPE(Object)

class Object {
private:
	static Object Object__static;
	long instanceId;

public:
	static Object& StaticInstance();
	static Class& StaticClass();

	//////////////////////////////////////////
	//Must be overriden by inherited classes//
	//////////////////////////////////////////
	virtual Object* CreateSelf() const;
	virtual IProperty* GetProperty(std::string name) const;
	virtual std::vector<IProperty*> GetProperties() const;
	virtual const std::string GetName() const;
	virtual const long GetTypeId() const;
	//////////////////////////////////////////
	//////////////////////////////////////////
	//////////////////////////////////////////

	bool Write(std::ostream& out);
	bool Read(std::istream& in);

	Object();

	bool InstanceOf(Object* other);
	const IType* GetType();

	long GetId() const;

	friend std::ostream& operator<<(std::ostream& out, Object& self);
	friend std::istream& operator>>(std::istream& in, Object& self);

	virtual ~Object();

protected:
	//////////////////////////////////////////
	//Optional Overrides//////////////////////
	//////////////////////////////////////////
	virtual void PostDeserialize(std::istream& in);
	virtual void PreDeserialize(std::istream& in);
	virtual void PostSerialize(std::ostream& out);
	virtual void PreSerialize(std::ostream& out);
	//////////////////////////////////////////
	//////////////////////////////////////////
	//////////////////////////////////////////

	//////////////////////////////////////////
	//Must be overriden by inherited classes//
	//////////////////////////////////////////
	virtual bool InternalWrite(std::ostream& out);
	virtual bool InternalRead(std::istream& in);
	//////////////////////////////////////////
	//////////////////////////////////////////
	//////////////////////////////////////////
};
#endif