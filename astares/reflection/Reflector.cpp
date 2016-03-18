#include "Reflector.h"

Reflector::Reflector()
	: Type(VariantType::unknown)
{

}

Reflector::~Reflector()
{

}

void Reflector::SetType(const Variant& variant) {
	if (Type.GetVariantType() == VariantType::unknown)
	{
		Type.Set(variant);
	}
}

void Reflector::AddProperty(const PropertyVariant& variant){
	if (Properties.find(variant.GetPropertyName()) == Properties.cend()) {
		Properties.emplace(std::make_pair(variant.GetPropertyName(), variant));
	}
}

std::vector<PropertyVariant> Reflector::GetProperties(){
	std::vector<PropertyVariant> results;
	for (auto kvp : Properties) {
		results.push_back(kvp.second);
	}
	return results;
}


Variant& Reflector::GetProperty(string name){
	return Properties.at(name);
}

void Reflector::SetProperty(string name, const Variant& newValue) {
	if (Properties.find(name) == Properties.cend()) {
		Properties[name].Set(newValue);
	}
}


int64 Reflector::GetCustomType() const {
	return Type.GetCustomType();
}

int64 Reflector::GetType() const {
	return Type.GetType();
}

string Reflector::GetName() const {
	return Type.GetName();
}