#include "catch.hpp"
#include <math\Vector.h>

TEST_CASE("Vector4", "[vectors]") {
	SECTION("Constructors") {
		Vector4 vec = Vector4();
		REQUIRE(vec.data[0] == Approx(0.0f));
		REQUIRE(vec.data[1] == Approx(0.0f));
		REQUIRE(vec.data[2] == Approx(0.0f));
		REQUIRE(vec.data[3] == Approx(0.0f));

		vec = Vector4(1.57f, 9.0f);
		REQUIRE(vec.data[0] == Approx(1.57f));
		REQUIRE(vec.data[1] == Approx(9.0f));
		REQUIRE(vec.data[2] == Approx(0.0f));

		vec = Vector4(1.57f, 9.0f, 8.0f);
		REQUIRE(vec.data[0] == Approx(1.57f));
		REQUIRE(vec.data[1] == Approx(9.0f));
		REQUIRE(vec.data[2] == Approx(8.0f));
		REQUIRE(vec.data[3] == Approx(0.0f));

		vec = Vector4(1.0f);
		REQUIRE(vec.data[0] == Approx(1.0f));
		REQUIRE(vec.data[1] == Approx(0.0f));
		REQUIRE(vec.data[2] == Approx(0.0f));

		auto vec2 = Vector2(87.0f, 123.45f);
		vec = Vector4(vec2);
		REQUIRE(vec.data[0] == vec2.data[0]);
		REQUIRE(vec.data[1] == vec2.data[1]);
		REQUIRE(vec.data[2] == Approx(0.0f));

		auto vec3 = Vector3(86.5f, 65.7f, 1.2f);
		vec = Vector4(vec3);
		REQUIRE(vec[0] == 86.5f);
		REQUIRE(vec[1] == 65.7f);
		REQUIRE(vec[2] == 1.2f);
		REQUIRE(vec[3] == 0.0f);

		vec = Vector4(1.43f, 5.67f, -90.1f, 1.0f);
		REQUIRE(vec.data[0] == Approx(1.43f));
		REQUIRE(vec.data[1] == Approx(5.67f));
		REQUIRE(vec.data[2] == Approx(-90.1f));
		REQUIRE(vec.data[3] == Approx(1.0f));

		auto vec3 = Vector4(87.0f, 123.45f, 56.7f);
		vec = Vector4(vec3);
		REQUIRE(vec.data[0] == Approx(87.0f));
		REQUIRE(vec.data[1] == Approx(123.45f));
		REQUIRE(vec.data[2] == Approx(56.7f));
		REQUIRE(vec.data[3] == Approx(0.0f));
	}

	SECTION("Accessor") {
		Vector4 vec(1.0f, 4.0f, 3.4f, 4.34f);
		REQUIRE(vec[0] == 1.0f);
		REQUIRE(vec[1] == 4.0f);
		REQUIRE(vec[2] == 3.4f);
		REQUIRE(vec[3] == 4.34f);
	}

	SECTION("Data") {
		SECTION("Buffer") {
			f32 buff[3] = { 0.0f, 0.0f, -1000000.0f };
			Vector4 vec(5.0f, 3.4f, 32.4564f);
			int ret = vec.ToBuffer(buff);
			REQUIRE(buff[0] == vec[0]);
			REQUIRE(buff[1] == vec[1]);
			REQUIRE(buff[2] == vec[2]);
			REQUIRE(ret == 3);
		}
	}

	SECTION("Mathematicial Operators") {
		SECTION("Vectors") {
			SECTION("Addition") {
				Vector4 first(1.0f, 2.0f, 32.4f);
				Vector4 second(5.0f, 4.0f, 1.0f);

				Vector4 third = first + second;
				REQUIRE(third[_X] == 6.0f);
				REQUIRE(third[_Y] == 6.0f);
				REQUIRE(third[_Z] == 33.4f);

				Vector4 fourth = first + third;
				REQUIRE(fourth[_X] == first.data[0] + third.data[0]);
				REQUIRE(fourth[_Y] == first.data[1] + third.data[1]);
				REQUIRE(fourth[_Z] == first.data[2] + third.data[2]);

				first += second;
				REQUIRE(first[0] == 6.0f);
				REQUIRE(first[1] == 6.0f);
				REQUIRE(first[2] == 33.4f);
			}

			SECTION("Subtraction") {
				Vector4 first(1.0f, 2.0f, 4.0f);
				Vector4 second(5.0f, 4.0f, 4.0f);

				Vector4 third = first - second;
				REQUIRE(third[_X] == -4.0f);
				REQUIRE(third[_Y] == -2.0f);
				REQUIRE(third[_Z] == 0.0f);

				Vector4 fourth = first - third;
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
				Vector4 vec(5.0f, -1.0f, 8.7f);
				Vector4 result = vec + 4.0f;

				REQUIRE(result[0] == 9.0f);
				REQUIRE(result[1] == 3.0f);
				REQUIRE(result[2] == 12.7f);

				vec += 3.4f;
				REQUIRE(vec[0] == 8.4f);
				REQUIRE(vec[1] == 2.4f);
				REQUIRE(vec[2] == 12.1f);
			}

			SECTION("Subtraction") {
				Vector4 vec(5.0f, -1.0f, 2.0f);
				Vector4 result = vec - 4.0f;

				REQUIRE(result[0] == 1.0f);
				REQUIRE(result[1] == -5.0f);
				REQUIRE(result[2] == -2.0f);

				vec -= 0.45f;
				REQUIRE(vec[0] == 4.55f);
				REQUIRE(vec[1] == -1.45f);
				REQUIRE(vec[2] == 1.55f);
			}

			SECTION("Division") {
				Vector4 vec(5.0f, -3.0f, 4.0f);
				Vector4 result = vec / 4.0f;

				REQUIRE(result[0] == Approx(1.25f));
				REQUIRE(result[1] == Approx(-0.75f));
				REQUIRE(result[2] == Approx(1.0f));

				vec /= -2.0f;
				REQUIRE(vec[0] == -2.5f);
				REQUIRE(vec[1] == 1.5f);
				REQUIRE(vec[2] == -2.0f);
			}

			SECTION("Multiplication") {
				Vector4 vec(5.0f, -3.0f, 0.1f);
				Vector4 result = vec * 4.0f;

				REQUIRE(result[0] == Approx(20.0f));
				REQUIRE(result[1] == Approx(-12.0f));
				REQUIRE(result[2] == Approx(0.4f));

				vec *= 10.0f;
				REQUIRE(vec[0] == 50.0f);
				REQUIRE(vec[1] == -30.0f);
				REQUIRE(vec[2] == 1.0f);
			}
		}

		SECTION("Vector Math") {
			Vector4 vec(1.0f, 8.0f, 3.4f);
			Vector4 first(4.0f, -5.0f, 8.5f);
			Vector4 second(12.45f, 30.0f, -123.45f);

			//TODO: start from here on Friday
			REQUIRE(vec.GetLength() == Approx(8.7498571416909430590509453489801f));
			REQUIRE(vec.GetLengthSquared() == Approx(76.56f));

			Vector4 normalized = vec.GetNormalized();
			REQUIRE(normalized[0] == Approx(0.114288f));
			REQUIRE(normalized[1] == Approx(0.914301f));
			REQUIRE(normalized[2] == Approx(0.388578f));

			Vector4 quote_inverted_quote = vec.GetInverse();
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