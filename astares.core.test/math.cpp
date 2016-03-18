#include "catch.hpp"
#include <math\Math.h>

TEST_CASE("Basic math functions", "[math]") {
	
	SECTION("Detect epsilon compared values") {
		REQUIRE_FALSE(Math::LargerThanAlmostZero(Math::Epsilon));
		REQUIRE(Math::LargerThanAlmostZero(Math::Epsilon + 0.00001f));
		REQUIRE(Math::LargerThanAlmostZero(-1.0f * (Math::Epsilon + 0.00001f)));
	}

	SECTION("Square root") {
		f32 result = Math::SquareRoot(4.0f);
		REQUIRE(result == Approx(2.0f));
	}

	SECTION("Inverse Square Root") {
		f32 result = Math::InverseSquareRoot(512.0f);
		REQUIRE(result == Approx(0.04419417382f));
	}

	SECTION("make zero on almost zero") {
		f32 value = Math::Epsilon;
		Math::Correct(value);
		REQUIRE(value == Approx(0.0f));
	}
}