#ifndef UID_H
#define UID_H

#include "Types.h"

namespace astares
{
	class ASTARESCORE_API UID {
	public:
		~UID();
		UID();
		UID(const int64& val);

		static UID Make();

		int64 GetValue() const;
		cstring ToString() const;

		bool operator==(const UID& rhs) const;
		bool operator!=(const UID& rhs) const;

		bool operator<(const UID& rhs) const;
		bool operator>(const UID& rhs) const;

	private:
		int64 value;
	};
}

#endif