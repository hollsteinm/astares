#include "catch.hpp"
#include <math/Vector.h>

TEST_CASE("astares::Vector3", "[vectors]") {
	SECTION("Constructors") {
		astares::Vector3 vec = astares::Vector3();
		REQUIRE(vec.data[0] == Approx(0.0f));
		REQUIRE(vec.data[1] == Approx(0.0f));
		REQUIRE(vec.data[2] == Approx(0.0f));

		vec = astares::Vector3(1.57f, 9.0f);
		REQUIRE(vec.data[0] == Approx(1.57f));
		REQUIRE(vec.data[1] == Approx(9.0f));
		REQUIRE(vec.data[2] == Approx(0.0f));

		vec = astares::Vector3(1.0f);
		REQUIRE(vec.data[0] == Approx(1.0f));
		REQUIRE(vec.data[1] == Approx(0.0f));
		REQUIRE(vec.data[2] == Approx(0.0f));

		auto vec2 = astares::Vector2(87.0f, 123.45f);
		vec = astares::Vector3(vec2);
		REQUIRE(vec.data[0] == vec2.data[0]);
		REQUIRE(vec.data[1] == vec2.data[1]);
		REQUIRE(vec.data[2] == Approx(0.0f));

		vec = astares::Vector3(1.43f, 5.67f, -90.1f);
		REQUIRE(vec.data[0] == Approx(1.43f));
		REQUIRE(vec.data[1] == Approx(5.67f));
		REQUIRE(vec.data[2] == Approx(-90.1f));

		auto vec3 = astares::Vector3(87.0f, 123.45f, 56.7f);
		vec = astares::Vector3(vec3);
		REQUIRE(vec.data[0] == Approx(87.0f));
		REQUIRE(vec.data[1] == Approx(123.45f));
		REQUIRE(vec.data[2] == Approx(56.7f));
	}

	SECTION("Accessor") {
		astares::Vector3 vec(1.0f, 4.0f, 3.4f);
		REQUIRE(vec[0] == 1.0f);
		REQUIRE(vec[1] == 4.0f);
		REQUIRE(vec[2] == 3.4f);
	}

	SECTION("Data") {
		SECTION("Buffer") {
			astares::f32 buff[3] = { 0.0f, 0.0f, -1000000.0f };
			astares::Vector3 vec(5.0f, 3.4f, 32.4564f);
			int ret = vec.ToBuffer(buff);
			REQUIRE(buff[0] == vec[0]);
			REQUIRE(buff[1] == vec[1]);
			REQUIRE(buff[2] == vec[2]);
			REQUIRE(ret == 3);
		}
	}

	SECTION("Mathematicial Operators") {
		SECTION("astares::Vectors") {
			SECTION("Addition") {
				astares::Vector3 first(1.0f, 2.0f, 32.4f);
				astares::Vector3 second(5.0f, 4.0f, 1.0f);

				astares::Vector3 third = first + second;
				REQUIRE(third[_X] == 6.0f);
				REQUIRE(third[_Y] == 6.0f);
				REQUIRE(third[_Z] == 33.4f);

				astares::Vector3 fourth = first + third;
				REQUIRE(fourth[_X] == first.data[0] + third.data[0]);
				REQUIRE(fourth[_Y] == first.data[1] + third.data[1]);
				REQUIRE(fourth[_Z] == first.data[2] + third.data[2]);

				first += second;
				REQUIRE(first[0] == 6.0f);
				REQUIRE(first[1] == 6.0f);
				REQUIRE(first[2] == 33.4f);
			}

			SECTION("Subtraction") {
				astares::Vector3 first(1.0f, 2.0f, 4.0f);
				astares::Vector3 second(5.0f, 4.0f, 4.0f);

				astares::Vector3 third = first - second;
				REQUIRE(third[_X] == -4.0f);
				REQUIRE(third[_Y] == -2.0f);
				REQUIRE(third[_Z] == 0.0f);

				astares::Vector3 fourth = first - third;
				REQUIRE(fourth[_X] == first.data[0] - third.data[0]);
				REQUIRE(fourth[_Y] == first.data[1] - third.data[1]);
				REQUIRE(fourth[_Z] == first.data[2] - third.data[2]);

				first -= second;
				REQUIRE(first[0] == -4.0f);
				REQUIRE(first[1] == -2.0f);
				REQUIRE(first[2] == 0.0f);
			}
		}

		SECTION("Real Numbers") {
			SECTION("Addition") {
				astares::Vector3 vec(5.0f, -1.0f, 8.7f);
				astares::Vector3 result = vec + 4.0f;

				REQUIRE(result[0] == 9.0f);
				REQUIRE(result[1] == 3.0f);
				REQUIRE(result[2] == 12.7f);

				vec += 3.4f;
				REQUIRE(vec[0] == 8.4f);
				REQUIRE(vec[1] == 2.4f);
				REQUIRE(vec[2] == 12.1f);
			}

			SECTION("Subtraction") {
				astares::Vector3 vec(5.0f, -1.0f, 2.0f);
				astares::Vector3 result = vec - 4.0f;

				REQUIRE(result[0] == 1.0f);
				REQUIRE(result[1] == -5.0f);
				REQUIRE(result[2] == -2.0f);

				vec -= 0.45f;
				REQUIRE(vec[0] == 4.55f);
				REQUIRE(vec[1] == -1.45f);
				REQUIRE(vec[2] == 1.55f);
			}

			SECTION("Division") {
				astares::Vector3 vec(5.0f, -3.0f, 4.0f);
				astares::Vector3 result = vec / 4.0f;

				REQUIRE(result[0] == Approx(1.25f));
				REQUIRE(result[1] == Approx(-0.75f));
				REQUIRE(result[2] == Approx(1.0f));

				vec /= -2.0f;
				REQUIRE(vec[0] == -2.5f);
				REQUIRE(vec[1] == 1.5f);
				REQUIRE(vec[2] == -2.0f);
			}

			SECTION("Multiplication") {
				astares::Vector3 vec(5.0f, -3.0f, 0.1f);
				astares::Vector3 result = vec * 4.0f;

				REQUIRE(result[0] == Approx(20.0f));
				REQUIRE(result[1] == Approx(-12.0f));
				REQUIRE(result[2] == Approx(0.4f));

				vec *= 10.0f;
				REQUIRE(vec[0] == 50.0f);
				REQUIRE(vec[1] == -30.0f);
				REQUIRE(vec[2] == 1.0f);
			}
		}

		SECTION("astares::Vector Math") {
			astares::Vector3 vec(1.0f, 8.0f, 3.4f);
			astares::Vector3 first(4.0f, -5.0f, 8.5f);
			astares::Vector3 second(12.45f, 30.0f, -123.45f);

			//TODO: start from here on Friday
			REQUIRE(vec.GetMagnitude() == Approx(8.7498571416909430590509453489801f));
			REQUIRE(vec.GetLengthSquared() == Approx(76.56f));

			astares::Vector3 normalized = vec.GetNormalized();
			REQUIRE(normalized[0] == Approx(0.114288f));
			REQUIRE(normalized[1] == Approx(0.914301f));
			REQUIRE(normalized[2] == Approx(0.388578f));

			astares::Vector3 quote_inverted_quote = vec.GetInverse();
			REQUIRE(quote_inverted_quote[0] == -1.0f);
			REQUIRE(quote_inverted_quote[1] == -8.0f);
			REQUIRE(quote_inverted_quote[2] == -3.4f);

			REQUIRE(first.GetDot(second) == Approx(-1149.525f));
			REQUIRE(first.GetDistance(second) == Approx(136.774f));
			REQUIRE(first.GetDistanceSquared(second) == Approx(18707.127076f));

			second.Normalize();
			REQUIRE(second[0] == Approx(0.0975312f));
			REQUIRE(second[1] == Approx(0.235015f));
			REQUIRE(second[2] == Approx(-0.967086f));

			second.Invert();
			REQUIRE(second[0] == Approx(-0.0975312f));
			REQUIRE(second[1] == Approx(-0.235015f));
			REQUIRE(second[2] == Approx(0.967086f));
		}
	}
}