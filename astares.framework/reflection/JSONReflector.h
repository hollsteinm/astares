#ifndef JSONREFLECTOR_H
#define JSONREFLECTOR_H

#include "IReflector.h"

class ASTARESFRAMEWORK_API JSONReflector : public IReflector
{
public:
	virtual void SetType(const Variant& variant) override;
	virtual void AddProperty(const PropertyVariant& variant) override;

	string ToString() const;
private:
	static string GetVectorContentString(const vector<string>& labels, const vector<f32>& data);

	void WriteNumeric(Variant& variant);
	void WriteString(Variant& variant);
	void WriteBoolean(Variant& variant);
	void WriteArrayType(Variant& variant);
	void WriteMapType(Variant& variant);
	void WriteObject(Variant& variant);
	void WriteHull(Variant& variant);
	void WriteSphere(Variant& variant);
	void WriteBox(Variant& variant);
	void WritePlane(Variant& variant);
	void WriteTransform(Variant& variant);
	void WriteQuaternion(Variant& variant);
	void WriteUID(Variant& variant);
	void WriteVariant(Variant& variant);
	void WriteObject(class Object* obj);

	string highestOrderType;
	vector<string> parents;
	string content;
};

#endif