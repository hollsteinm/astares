#ifndef REFLECTION_H
#define REFLECTION_H

#include "Types.h"
#include "IField.h"
#include "Class.h"
#include "Field.h"
#include "../core/ObjectFactory.h"
#include "../core/Object.h"
#include "Serialization.h"
#include "MetaGraph.h"
#include "../core/Pointer.h"
#include "../core/Array.h"

#define DECL_PTR_TYPE(T) TYPE(ObjectPtr<T>)
#define DECL_ARR_TYPE(T) TYPE(ObjectArray<T>)

#define PROP_FLAG_NONE			(int)FieldFlags::None
#define PROP_FLAG_SERIALIGNORE	(int)FieldFlags::SerialIgnore
#define PROP_FLAG_ALL			(int)FieldFlags::All

#define VERSION 0

#define DECL_CLASS(C) class C; TYPE(C) DECL_PTR_TYPE(C) DECL_ARR_TYPE(C) class C
#define DECL_CLASS_BASE(C) DECL_CLASS(C) : public Object
#define DECL_BODY(C) private: \
		static C C##__static; \
		typedef C Me;\
	protected:\
		virtual bool InternalWrite(std::ostream& out) override;\
		virtual bool InternalRead(std::istream& in) override; \
	public:\
		C();\
		virtual ~C();\
		static Class& StaticClass();\
		static C& StaticInstance();\
		virtual Object* CreateSelf() const override;\
		virtual IField* GetField(String name) const override;\
		virtual std::vector<IField*> GetFields() const override;\
		virtual const String GetName() const override;\
		virtual const long GetTypeId() const override;

#define DEF_STATIC_CLASS(C) C C::C##__static;

#define CTOR_REGISTER(C) ObjectFactory::Get().Add(#C, &C##__static);

#define FIELD_PARAMS(PROPTYPE, NAME, FLAGS) staticInst->Add(new Field<Me, PROPTYPE> (#NAME, &Me::NAME, FLAGS));
#define FIELD(PROP, NAME) FIELD_PARAMS(PROP, NAME, PROP_FLAG_NONE)
#define PARENT(PARENTTYPE) staticInst->Add(TYPEOF(PARENTTYPE));

#define REFLECTION_BEGIN(C) DEF_STATIC_CLASS(C) \
		C& C::StaticInstance() { C::StaticClass(); return C##__static; } \
		Object* C::CreateSelf() const { \
			return new C();\
		}\
		IField* C::GetField(String name) const {\
			return C::StaticClass().GetField(name);\
		}\
		std::vector<IField*> C::GetFields() const {\
			return C::StaticClass().GetFields();\
		}\
		const String C::GetName() const {\
			return C::StaticClass().GetName();\
		}\
		const long C::GetTypeId() const {\
			return TYPEOF(C); \
		}\
		bool C::InternalWrite(std::ostream& out) {\
			return C::StaticClass().Write(this, out, VERSION);\
		}\
		bool C::InternalRead(std::istream& in) {\
			return C::StaticClass().Read(this, in, VERSION);\
		}\
		Class& C::StaticClass() {\
			static Class C##__class(#C, TYPEOF(C)); \
			TYPEOF(ObjectPtr<C>);\
			TYPEOF(ObjectArray<C>);\
			Class* staticInst = &C##__class;\
			MetaGraph* metaSystem = &MetaGraph::Get();

#define REFLECTION_END(C) metaSystem->Add(staticInst);\
			return C##__class;\
		}

#endif