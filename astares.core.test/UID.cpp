#include <core/UID.h>
#include "catch.hpp"

TEST_CASE("UID", "[core]") {
	SECTION("Comparisons & Uniqueness") {
		UID first = UID::Make();
		UID second = UID::Make();

		REQUIRE_FALSE(first == second);
		REQUIRE(first != second);
	}
}