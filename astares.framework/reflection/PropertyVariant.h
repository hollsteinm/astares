#ifndef PROPERTYVARIANT_H
#define PROPERTYVARIANT_H

#include "Variant.h"

class PropertyVariant : public Variant
{
private:

	struct IPropertyInfo {

	};

	template<typename Obj, typename Prop>
	struct PropertyInfo : public IPropertyInfo {
		Prop Obj::*Property;
		typedef Prop PropertyType;
		typedef Obj OwnerType;

		PropertyInfo(Prop Obj::*prop) :
			Property(prop)
		{}

		PropertyInfo(const PropertyInfo<Obj, Prop>& other) :
			info(other.info)
		{}
	};

	string propName;
	std::shared_ptr<IPropertyInfo> info;

public:
	PropertyVariant();
	PropertyVariant(VariantType type);
	PropertyVariant(VariantType type, int64 customType);
	virtual ~PropertyVariant();
	PropertyVariant(const PropertyVariant& other);

	template<typename Obj, typename Prop>
	PropertyVariant(const string& propertyName, const Obj* owner, Prop Obj::*Property) :
		PropertyVariant(VariantTypeId<Prop>::GetType(), (int64)std::hash<string>()(VariantTypeId<Prop>::GetTypeName()))
	{
		size = sizeof(Prop);
		name = VariantTypeId<Prop>::GetTypeName();
		Set(owner->*Property);
		info = std::shared_ptr<IPropertyInfo>(new PropertyInfo<Obj, Prop>(Property));
		propName = propertyName;
	}

	template<typename T>
	void Set(const T& other) {
		Variant::Set<T>(other);
	}

	template<>
	void Set<PropertyVariant>(const PropertyVariant& newValue){
		type = newValue.type;
		size = newValue.size;
		name = newValue.name;
		customType = newValue.customType;
		buffer = std::stringstream(newValue.buffer.str(), std::ios::binary | std::ios::in | std::ios::out);
		info = newValue.info;
		propName = newValue.propName;
	}

	string GetPropertyName() const { return propName; }

	friend WriteStream& operator << (WriteStream& out, const PropertyVariant& variant);
	friend ReadStream& operator >> (ReadStream& in, PropertyVariant& variant);
};


#endif