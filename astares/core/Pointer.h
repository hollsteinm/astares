#ifndef POINTER_H
#define POINTER_H

#include "../core/Object.h"
#include "../core/ObjectFactory.h"

template<typename T>
class ObjectPtr {
public:
	ObjectPtr() :
		selfManaged(false),
		Pointer(nullptr)
	{
	}

	ObjectPtr(Object* ptr) :
		selfManaged(false),
		Pointer(ptr)
	{
	}

	~ObjectPtr() {
		Delete();
	}

	void New() {
		selfManaged = true;
		Pointer = new T();
	}

	void MakeLazy() {
		selfManaged = true;
	}

	void Delete() {
		if (selfManaged && Pointer != nullptr) {
			delete Pointer;
			Pointer = nullptr;
		}
	}

	bool IsValid() const {
		return Pointer != nullptr;
	}

	T* const Get() const {
		return (T*)Pointer;
	}

	void Set(Object* NewValue) {
		Delete();
		selfManaged = false;
		Pointer = NewValue;
	}

	friend std::ostream& operator<<(std::ostream& out, ObjectPtr<T>& self) {
		if (self.IsValid())
		{
			self.Pointer->Write(out);
		}
		else {
			out << 0;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, ObjectPtr<T>& self) {
		char first;
		in >> first;

		if (first != '0') {
			
			in.unget();
			T* obj = Deserialize<T>(in);

			self.Set(ObjectFactory::Get().GetLive(obj->GetId()));
			if (self.IsValid()) {
				delete obj;
				obj = nullptr;
			}
			else {
				self.Set(obj);
			}
		}
		return in;
	}

private:
	Object* Pointer;
	bool selfManaged;

protected:
};

TYPE(ObjectPtr<Object>)

#endif