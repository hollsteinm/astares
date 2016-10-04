#include "catch.hpp"
#include <math\Math.h>

TEST_CASE("Basic math functions", "[math]") {
	
	SECTION("Detect epsilon compared values") {
		REQUIRE_FALSE(astares::Math::LargerThanAlmostZero(astares::Math::Epsilon));
		REQUIRE(astares::Math::LargerThanAlmostZero(astares::Math::Epsilon + 0.00001f));
		REQUIRE(astares::Math::LargerThanAlmostZero(-1.0f * (astares::Math::Epsilon + 0.00001f)));
	}

	SECTION("Square root") {
		astares::f32 result = astares::Math::SquareRoot(4.0f);
		REQUIRE(result == Approx(2.0f));
	}

	SECTION("Inverse Square Root") {
		astares::f32 result = astares::Math::InverseSquareRoot(512.0f);
		REQUIRE(result == Approx(0.04419417382f));
	}

	SECTION("make zero on almost zero") {
		astares::f32 value = astares::Math::Epsilon;
		astares::Math::Correct(value);
		REQUIRE(value == Approx(0.0f));
	}
}