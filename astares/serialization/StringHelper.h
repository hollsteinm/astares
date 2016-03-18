#ifndef STRING_H
#define STRING_H

#include "../core/Types.h"
struct StringHelper {
	static void MakeEncoded(string& str);
	static void MakeDecoded(string& str);

	static string Encode(const string& str);
	static string Decode(const string& str);
};

#endif