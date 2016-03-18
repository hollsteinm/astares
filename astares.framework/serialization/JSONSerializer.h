#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "IObjectSerializer.h"

class JSONSerializer : public IObjectSerializer {
public:
	JSONSerializer(gate compact = false, gate includeObjectType = true);
	~JSONSerializer();

	virtual void Serialize(const class Object* input, std::ostream& output) const override;
	virtual void Deserialize(class Object* output, std::istream& input) const override;

private:
	gate bCompact;
	gate bIncludeType;

	void BeginObject(std::ostream& output, int32 depth) const;
	void WriteObject(const class Object* object, std::ostream& output, int32 depth) const;
	void WriteArray(const string& arr, std::ostream& output, int32 depth) const;
	void WriteHash(const string& hash, std::ostream& output, int32 depth) const;
	void WritePair(const string& name, const string& value, std::ostream& output, int32 depth) const;
	void EndObject(std::ostream& output, int32 depth) const;
	void Tab(std::ostream& out, int32 depth) const;

	void RemoveLastOf(string& value, char val) const;

public:
	static const int8 OpenToken;
	static const int8 CloseToken;
	static const int8 ArrayStartToken;
	static const int8 ArrayEndToken;
	static const int8 PropertyToken;
	static const int8 SeperatorToken;
	static const int8 QuoteToken;
	static const string TypeProperty;
};


#endif