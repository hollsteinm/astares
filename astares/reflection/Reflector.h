#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "IReflectionInfo.h"
#include "IReflector.h"

class Reflector : public IReflector, IReflectionInfo {
public:
	Reflector();
	~Reflector();

	virtual void SetType(const Variant& variant) override;
	virtual void AddProperty(const PropertyVariant& variant) override;

	virtual Variant& GetProperty(string name) override;
	virtual void SetProperty(string name, const Variant& newValue) override;
	virtual std::vector<PropertyVariant> GetProperties() override;


	virtual int64 GetCustomType() const override;
	virtual int64 GetType() const override;
	virtual string GetName() const override;

private:
	Variant Type;

	std::map<string, PropertyVariant> Properties;
};


#endif