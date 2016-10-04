#include <core/UID.h>
#include "catch.hpp"
#include <iostream>

TEST_CASE("UID", "[core]") {
	SECTION("Comparisons & Uniqueness") {
		astares::UID first = astares::UID::Make();
		astares::UID second = astares::UID::Make();

		REQUIRE_FALSE(first == second);
		REQUIRE(first != second);
	}
}