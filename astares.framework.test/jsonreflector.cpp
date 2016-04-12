#include "catch.hpp"
#include <reflection\JSONReflector.h>
#include "JSONTestObjectContainer.h"
#include <object\ObjectFactory.h>

TEST_CASE("JSONReflector", "[reflection]") {
	SECTION("Validate JSON") {
		REGISTER_TYPE(JSONTestObject)
		REGISTER_TYPE(JSONTestObjectContainer)
		auto reflector = std::shared_ptr<JSONReflector>(new JSONReflector());
		JSONTestObjectContainer obj;
		obj.Reflect(reflector);
		REQUIRE(reflector->ToString().size() == 30470);
	}
}