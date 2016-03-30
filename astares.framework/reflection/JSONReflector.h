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

	void WriteNumeric(const Variant& variant);
	void WriteString(const Variant& variant);
	void WriteBoolean(const Variant& variant);
	void WriteArrayType(const Variant& variant);
	void WriteMapType(const Variant& variant);
	void WriteObject(const Variant& variant);
	void WriteHull(const Variant& variant);
	void WriteSphere(const Variant& variant);
	void WriteBox(const Variant& variant);
	void WritePlane(const Variant& variant);
	void WriteTransform(const Variant& variant);
	void WriteQuaternion(const Variant& variant);
	void WriteUID(const Variant& variant);
	void WriteVariant(const Variant& variant);

	string highestOrderType;
	vector<string> parents;
	string content;
};

#endif