#include "Serialization.h"
#include "../core/ObjectFactory.h"
#include "../core/Object.h"

static inline std::string GetClassName(std::istream& in) {
	char str[256];
	in.get(str, 256, ' ');
	std::string className(str);
	className.shrink_to_fit();
	int ugc = className.size();
	for (int i = 0; i < ugc; ++i){
		in.unget();
	}
	return className;
}

Object* Deserialize(std::istream& in) {
	std::string parseName = GetClassName(in);

	Object* o = ObjectFactory::Get().CreateNew(parseName);
	if (o != nullptr) {
		if (o->Read(in)){
			return o;
		}
		else {
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
}