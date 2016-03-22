#ifndef UID_H
#define UID_H

#include "Types.h"

class ASTARESCORE_API UID {
public:
	~UID();
	UID();

	static UID Make();

	int64 GetValue() const;
	string ToString() const;

	friend ASTARESCORE_API ReadStream& operator >> (ReadStream& in, UID& out);
	friend ASTARESCORE_API WriteStream& operator << (WriteStream& out, const UID& in);

	bool operator==(const UID& rhs) const;
	bool operator!=(const UID& rhs) const;

	bool operator<(const UID& rhs) const;
	bool operator>(const UID& rhs) const;

private:
	UID(const int64& val);

	int64 value;
};


#endif