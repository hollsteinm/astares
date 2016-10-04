#ifndef OBJECT_H
#define OBJECT_H

#include "../astares.framework.h"
#include <Core.h>

#ifndef API_TYPE
#define API_TYPE(api, type) \
DECL_API_TYPE(api, type) \
DECL_API_STL_PTR(api, type) \
DECL_API_STL(api, type)
#endif

#ifndef TYPE
#define TYPE(type) namespace astares { API_TYPE(,type) }
#endif

#ifndef BIND
#define BIND(self) TypeQuery self::GetType() const { return TypeQuery::Query(self); } \
typedef Self self; \
void self::InternalBind(std::shared_ptr<IBinder> binder) const {
#endif

#ifndef BIND_PARENT
#define BIND_PARENT(parent) parent::InternalBind(binder);
#endif

#ifndef PROPERTY
#define PROPERTY(Property) binder->Apply(#Property, this, &self::Property);
#endif

#ifndef END_BIND
#define END_BIND binder->Apply(GetType()); }
#endif

#ifndef BINDABLE
#define BINDABLE protected: virtual void InternalBind(std::shared_ptr<struct IBinder> binder) override; public: virtual TypeQuery GetType() const override;
#endif

namespace astares
{
	class ASTARESFRAMEWORK_API Object : public IBindable {
	private:
		UID instanceId;

	public:
		Object();
		virtual ~Object();

		const UID& GetInstanceId() const;
		virtual string ToString() const;
		virtual TypeQuery GetType() const;

		bool operator==(const Object& rhs) const;
		bool operator!=(const Object& rhs) const;

		void BindTo(std::shared_ptr<struct IBinder> binder) const override;
		virtual TypeQuery GetType() const override;

	protected:
		virtual void InternalBind(std::shared_ptr<struct IBinder> binder);
	};

	API_TYPE(ASTARESFRAMEWORK_API, Object)
}

#endif