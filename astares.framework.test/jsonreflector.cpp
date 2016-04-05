#include "catch.hpp"
#include <reflection\JSONReflector.h>
#include "JSONTestObjectContainer.h"
#include <object\ObjectFactory.h>

TEST_CASE("JSONReflector", "[reflection]") {
	SECTION("Validate JSON") {
		REGISTER_TYPE(JSONTestObject)
		REGISTER_TYPE(JSONTestObjectContainer)
		JSONReflector reflector;
		JSONTestObjectContainer obj;
		obj.Reflect(&reflector);
		string wouldLike = reflector.ToString();
		REQUIRE(reflector.ToString() == "");
	}
}