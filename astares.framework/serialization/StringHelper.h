#ifndef STRING_H
#define STRING_H
#include "../astares.framework.h"
#include <core/Types.h>
struct  ASTARESFRAMEWORK_API StringHelper {
	static void MakeEncoded(string& str);
	static void MakeDecoded(string& str);

	static string Encode(const string& str);
	static string Decode(const string& str);
};

#endif