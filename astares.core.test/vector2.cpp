#include "catch.hpp"
#include <math/Vector.h>

TEST_CASE("astares::Vector2", "[vectors]") {
	SECTION("Constructors") {
		astares::Vector2 vec = astares::Vector2();
		REQUIRE(vec.data[0] == Approx(0.0f));
		REQUIRE(vec.data[1] == Approx(0.0f));

		vec = astares::Vector2(1.57f, 9.0f);
		REQUIRE(vec.data[0] == Approx(1.57f));
		REQUIRE(vec.data[1] == Approx(9.0f));

		vec = astares::Vector2(1.0f);
		REQUIRE(vec.data[0] == Approx(1.0f));
		REQUIRE(vec.data[1] == Approx(0.0f));

		auto vec2 = astares::Vector2(87.0f, 123.45f);
		vec = astares::Vector2(vec2);
		REQUIRE(vec.data[0] == vec2.data[0]);
		REQUIRE(vec.data[1] == vec2.data[1]);
	}

	SECTION("Accessor") {
		astares::Vector2 vec(1.0f, 4.0f);
		REQUIRE(vec[0] == 1.0f);
		REQUIRE(vec[1] == 4.0f);
	}

	SECTION("Data") {
		SECTION("Buffer") {
			astares::f32 buff[2] = { 0.0f, 0.0f };
			astares::Vector2 vec(5.0f, 3.4f);
			int ret = vec.ToBuffer(buff);
			REQUIRE(buff[0] == vec[0]);
			REQUIRE(buff[1] == vec[1]);
			REQUIRE(ret == 2);
		}
	}

	SECTION("Mathematicial Operators") {
		SECTION("astares::Vectors") {
			SECTION("Addition") {
				astares::Vector2 first(1.0f, 2.0f);
				astares::Vector2 second(5.0f, 4.0f);

				astares::Vector2 third = first + second;
				REQUIRE(third[_X] == 6.0f);
				REQUIRE(third[_Y] == 6.0f);

				astares::Vector2 fourth = first + third;
				REQUIRE(fourth[_X] == first.data[0] + third.data[0]);
				REQUIRE(fourth[_Y] == first.data[1] + third.data[1]);

				first += second;
				REQUIRE(first[0] == 6.0f);
				REQUIRE(first[1] == 6.0f);
			}

			SECTION("Subtraction") {
				astares::Vector2 first(1.0f, 2.0f);
				astares::Vector2 second(5.0f, 4.0f);

				astares::Vector2 third = first - second;
				REQUIRE(third[_X] == -4.0f);
				REQUIRE(third[_Y] == -2.0f);

				astares::Vector2 fourth = first - third;
				REQUIRE(fourth[_X] == first.data[0] - third.data[0]);
				REQUIRE(fourth[_Y] == first.data[1] - third.data[1]);

				first -= second;
				REQUIRE(first[0] == -4.0f);
				REQUIRE(first[1] == -2.0f);
			}
		}

		SECTION("Real Numbers") {
			SECTION("Addition") {
				astares::Vector2 vec(5.0f, -1.0f);
				astares::Vector2 result = vec + 4.0f;

				REQUIRE(result[0] == 9.0f);
				REQUIRE(result[1] == 3.0f);

				vec += 3.4f;
				REQUIRE(vec[0] == 8.4f);
				REQUIRE(vec[1] == 2.4f);
			}

			SECTION("Subtraction") {
				astares::Vector2 vec(5.0f, -1.0f);
				astares::Vector2 result = vec - 4.0f;

				REQUIRE(result[0] == 1.0f);
				REQUIRE(result[1] == -5.0f);

				vec -= 0.45f;
				REQUIRE(vec[0] == 4.55f);
				REQUIRE(vec[1] == -1.45f);
			}

			SECTION("Division") {
				astares::Vector2 vec(5.0f, -3.0f);
				astares::Vector2 result = vec / 4.0f;

				REQUIRE(result[0] == Approx(1.25f));
				REQUIRE(result[1] == Approx(-0.75f));

				vec /= -2.0f;
				REQUIRE(vec[0] == -2.5f);
				REQUIRE(vec[1] == 1.5f);
			}

			SECTION("Multiplication") {
				astares::Vector2 vec(5.0f, -3.0f);
				astares::Vector2 result = vec * 4.0f;

				REQUIRE(result[0] == Approx(20.0f));
				REQUIRE(result[1] == Approx(-12.0f));

				vec *= 10.0f;
				REQUIRE(vec[0] == 50.0f);
				REQUIRE(vec[1] == -30.0f);
			}
		}

		SECTION("astares::Vector Math") {
			astares::Vector2 vec(1.0f, 8.0f);
			astares::Vector2 first(4.0f, -5.0f);
			astares::Vector2 second(12.45f, 30.0f);

			REQUIRE(first.GetMagnitude() == Approx(6.40312));
			REQUIRE(first.GetLengthSquared() == Approx(40.9999457));

			astares::Vector2 normalized = vec.GetNormalized();
			REQUIRE(normalized[0] == Approx(0.124035));
			REQUIRE(normalized[1] == Approx(0.992278f));

			astares::Vector2 quote_inverted_quote = vec.GetInverse();
			REQUIRE(quote_inverted_quote[0] == -1.0f);
			REQUIRE(quote_inverted_quote[1] == -8.0f);

			REQUIRE(first.GetDot(second) == Approx(-100.2f));
			REQUIRE(first.GetDistance(second) == Approx(36.00559f));
			REQUIRE(first.GetDistanceSquared(second) == Approx(1296.40251125f));

			second.Normalize();
			REQUIRE(second[0] == Approx(0.383303f));
			REQUIRE(second[1] == Approx(0.923623f));

			second.Invert();
			REQUIRE(second[0] == Approx(-0.383303f));
			REQUIRE(second[1] == Approx(-0.923623f));
		}
	}
}