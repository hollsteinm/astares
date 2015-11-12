#include "SerializationTests.h"
#include "../../core/ObjectFactory.h"
#include "../../core/Object.h"
#include "../MetaGraph.h"
#include "../Serialization.h"

#include <sstream>

void test::serial::Console() {
	for (auto id : MetaGraph::Get().AllTypeIds()) {
		Object* obj = ObjectFactory::Get().CreateNew(id);
		if (obj != nullptr) {
			std::stringstream first(std::ios::in | std::ios::out | std::ios::binary);
			first << *obj;

			std::stringstream second(std::ios::in | std::ios::out | std::ios::binary);
			first >> *obj;
			second << *obj;

			std::cout << (unsigned long)id << std::endl << first.str() << std::endl << second.str() << std::endl << std::endl;

			first.clear();
			second.clear();
		}
		delete obj;
	}
}