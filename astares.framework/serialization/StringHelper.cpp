#include "StringHelper.h"


string StringHelper::Encode(const string& src) {
	auto str = src;
	auto pos = str.find(" ");
	while (pos != std::string::npos) {
		str.replace(pos, 1, "%20");
		pos = str.find(" ");
	}
	return str;
}

string StringHelper::Decode(const string& src) {
	auto str = src;
	auto pos = str.find("%20");
	while (pos != std::string::npos) {
		str.replace(pos, 3, " ");
		pos = str.find("%20");
	}
	return str;
}

void StringHelper::MakeEncoded(string& str) {
	auto pos = str.find(" ");
	while (pos != std::string::npos) {
		str.replace(pos, 1, "%20");
		pos = str.find(" ");
	}
}

void StringHelper::MakeDecoded(string& str) {
	auto pos = str.find("%20");
	while (pos != std::string::npos) {
		str.replace(pos, 3, " ");
		pos = str.find("%20");
	}
}