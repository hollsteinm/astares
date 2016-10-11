#include "catch.hpp"
#include <core\String.h>

TEST_CASE("String", "[core]")
{
	SECTION("Queries")
	{
		astares::String s("const char*");
		REQUIRE(s.Length() == 11);
		REQUIRE(std::strcmp(s.ToCString(), "const char*") == 0);
		REQUIRE(s.Compare("const char*") == 0);
		REQUIRE(s.Contains("st ch"));
		REQUIRE_FALSE(s.Contains("x y z"));
		REQUIRE_FALSE(s.IsDecimal());
		REQUIRE(s.IsBoolean());
		REQUIRE_FALSE(s.IsNumeric());
		REQUIRE_FALSE(s.IsWhitespace());

		s = astares::String();
		REQUIRE(s.IsEmpty());
		REQUIRE(s.IsWhitespace());

		s = "       ";
		REQUIRE_FALSE(s.IsEmpty());
		REQUIRE(s.IsWhitespace());

		s = "1006";
		REQUIRE(s.IsNumeric());
		REQUIRE_FALSE(s.IsDecimal());

		s = "-234";
		REQUIRE(s.IsNumeric());
		REQUIRE_FALSE(s.IsDecimal());

		s = "12.5";
		REQUIRE(s.IsNumeric());
		REQUIRE(s.IsDecimal());

		s = "-12.4434343";
		REQUIRE(s.IsNumeric());
		REQUIRE(s.IsDecimal());

		s = "234.4.5";
		REQUIRE(s.IsNumeric());
		REQUIRE_FALSE(s.IsDecimal());

		s = "-234.4.-5";
		REQUIRE(s.IsNumeric());
		REQUIRE_FALSE(s.IsDecimal());
	}

	SECTION("Numeric Conversions")
	{
		astares::String s = "1006";
		REQUIRE(s.ToInt16() == 1006);
		REQUIRE(s.ToInt32() == 1006);
		REQUIRE(s.ToInt64() == 1006);

		s = "8";
		REQUIRE(s.ToInt8() == 8);
		REQUIRE(s.ToUint8() == 8);

		s = "-13";
		REQUIRE(s.ToInt8() == -13);

		s = "-234";
		REQUIRE(s.ToInt16() == -234);
		REQUIRE(s.ToInt32() == -234);
		REQUIRE(s.ToInt64() == -234);

		s = "12.5";
		REQUIRE(s.ToF32() == Approx(12.5f));
		REQUIRE(s.ToF64() == Approx(12.5));

		s = "-12.4434343";
		REQUIRE(s.ToF32() == Approx(-12.4434343f));
		REQUIRE(s.ToF64() == Approx(-12.4434343));
	}

	SECTION("Boolean Conversions")
	{
		astares::String truthy = "True";
		astares::String falsy = "asp9d8f7 bav";
		REQUIRE(truthy.ToBoolean());
		REQUIRE_FALSE(falsy.ToBoolean());
	}

	SECTION("Boolean Operators")
	{
		astares::String A = "ABC";
		astares::String B = "XyZ";

		REQUIRE_FALSE(A == B);
		REQUIRE(A != B);

		REQUIRE_FALSE(A > B);
		REQUIRE(B > A);

		REQUIRE(A < B);
		REQUIRE_FALSE(B < A);

		REQUIRE(A <= B);
		REQUIRE_FALSE(B <= A);

		REQUIRE_FALSE(A >= B);
		REQUIRE(B >= A);
	}

	SECTION("Numeric Parsing")
	{
		REQUIRE(astares::String::FromF32(43.5f) == "43.5");
		REQUIRE(astares::String::FromF64(43.678906) == "43.678906");
		REQUIRE(astares::String::FromF32(-49.5f) == "-49.5");
		REQUIRE(astares::String::FromF64(-3.678906) == "-3.678906");
	}

	SECTION("Mutable Functions")
	{

	}
}