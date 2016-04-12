#ifndef PROPERTYVARIANT_H
#define PROPERTYVARIANT_H

#include "Variant.h"

namespace astares
{
	template<typename>
	struct IsVector : std::false_type {};

	template<typename T, typename A>
	struct IsVector<std::vector<T, A>> : std::true_type{};

	template<typename>
	struct IsQueue : std::false_type {};

	template<typename T, typename A>
	struct IsQueue<std::queue<T, A>> : std::true_type{};

	struct Details
	{
		Details(const Details& o) = delete;
		Details(size_t size, VariantType innerType, int64 innerCustomType)
			:size(size),
			innerType(innerType),
			innerCustomType(innerCustomType)
		{}

		size_t size = 0;
		VariantType innerType;
		int64 innerCustomType;
	};

	template<typename T>
	struct CollectionDetails : public Details
	{
		CollectionDetails(const T& val)
			: Details(0, VariantType::unknown, 0)
		{}
	};

	template<typename T, typename A>
	struct CollectionDetails<std::vector<T, A>> : public Details
	{
		CollectionDetails(const std::vector<T, A>& val)
		: Details(val.size(), VariantTypeId<T>::GetType(), VariantTypeId<T>::GetCustomType())
		{}
	};

	template<typename T, typename A>
	struct CollectionDetails<std::queue<T, A>> : public Details
	{
		CollectionDetails(const std::queue<T, A>& val)
		: Details(val.size(), VariantTypeId<T>::GetType(), VariantTypeId<T>::GetCustomType())
		{}
	};
}

class ASTARESFRAMEWORK_API PropertyVariant : public Variant
{
private:
	string propName;

public:
	PropertyVariant();
	PropertyVariant(const VariantType& type);
	PropertyVariant(const VariantType& type, const int64& customType);
	PropertyVariant(const VariantType& type, const int64& customType, const string& variantName);
	PropertyVariant(const string& propertyName, const VariantType& type, const int64& customType, const string& variantName);
	PropertyVariant(const PropertyVariant& other);
	PropertyVariant(const Variant& other);
	virtual ~PropertyVariant();

	template<typename Obj, typename Prop>
	PropertyVariant(const string& propertyName, const Obj* owner, Prop Obj::*Property) :
		PropertyVariant(propertyName, VariantTypeId<Prop>::GetType(), VariantTypeId<Prop>::GetCustomType(), VariantTypeId<Prop>::GetTypeName())
	{
		size = sizeof(Prop);
		buffer << owner->*Property;
		bIsCollection = astares::IsVector<Prop>::value || astares::IsQueue<Prop>::value;
		if (bIsCollection)
		{
			astares::CollectionDetails<Prop> specs(owner->*Property);
			collectionSize = specs.size;
			collectionType = specs.innerType;
			collectionCustomType = specs.innerCustomType;
		}
	}

	string GetPropertyName() const { return propName; }

	friend WriteStream& operator << (WriteStream& out, const PropertyVariant& variant);
	friend ReadStream& operator >> (ReadStream& in, PropertyVariant& variant);
};

#endif