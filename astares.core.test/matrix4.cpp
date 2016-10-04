#include "catch.hpp"
#include <math\Matrix.h>

TEST_CASE("astares::Matrix4", "[matrix]") {
	SECTION("Constructors") {
		SECTION("astares::Vector3") {
			astares::Matrix4 mat = astares::Matrix4(astares::Vector3(1.0f, 4.5f, 3.4f));
			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(3.4f));
			REQUIRE(mat[0][3] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(0.0f));
			REQUIRE(mat[1][1] == Approx(0.0f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[1][3] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));
			REQUIRE(mat[2][3] == Approx(0.0f));
			REQUIRE(mat[3][0] == Approx(0.0f));
			REQUIRE(mat[3][1] == Approx(0.0f));
			REQUIRE(mat[3][2] == Approx(0.0f));
			REQUIRE(mat[3][3] == Approx(0.0f));
		}

		SECTION("astares::Vector3 * 2") {
			astares::Matrix4 mat = astares::Matrix4(
				astares::Vector3(1.0f, 4.5f, 3.4f),
				astares::Vector3(4.5f, 6.7f, 8.7f)
				);
			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(3.4f));
			REQUIRE(mat[0][3] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(4.5f));
			REQUIRE(mat[1][1] == Approx(6.7f));
			REQUIRE(mat[1][2] == Approx(8.7f));
			REQUIRE(mat[1][3] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));
			REQUIRE(mat[2][3] == Approx(0.0f));
			REQUIRE(mat[3][0] == Approx(0.0f));
			REQUIRE(mat[3][1] == Approx(0.0f));
			REQUIRE(mat[3][2] == Approx(0.0f));
			REQUIRE(mat[3][3] == Approx(0.0f));
		}

		SECTION("astares::Vector3 * 3") {
			astares::Matrix4 mat = astares::Matrix4(
				astares::Vector3(1.0f, 4.5f, 3.4f),
				astares::Vector3(4.5f, 6.7f, 8.7f),
				astares::Vector3(4.5f, 7.7f, 8.7f));
			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(3.4f));
			REQUIRE(mat[0][3] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(4.5f));
			REQUIRE(mat[1][1] == Approx(6.7f));
			REQUIRE(mat[1][2] == Approx(8.7f));
			REQUIRE(mat[1][3] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(4.5f));
			REQUIRE(mat[2][1] == Approx(7.7f));
			REQUIRE(mat[2][2] == Approx(8.7f));
			REQUIRE(mat[2][3] == Approx(0.0f));
			REQUIRE(mat[3][0] == Approx(0.0f));
			REQUIRE(mat[3][1] == Approx(0.0f));
			REQUIRE(mat[3][2] == Approx(0.0f));
			REQUIRE(mat[3][3] == Approx(0.0f));
		}

		SECTION("astares::Vector2") {
			astares::Matrix4 mat = astares::Matrix4(astares::Vector2(1.0f, 4.5f));
			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(0.0f));
			REQUIRE(mat[0][3] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(0.0f));
			REQUIRE(mat[1][1] == Approx(0.0f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[1][3] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));
			REQUIRE(mat[2][3] == Approx(0.0f));
			REQUIRE(mat[3][0] == Approx(0.0f));
			REQUIRE(mat[3][1] == Approx(0.0f));
			REQUIRE(mat[3][2] == Approx(0.0f));
			REQUIRE(mat[3][3] == Approx(0.0f));
		}

		SECTION("astares::Vector2 * 2") {
			astares::Matrix4 mat = astares::Matrix4(
				astares::Vector2(1.0f, 4.5f),
				astares::Vector2(4.5f, 6.7f)
				);
			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(0.0f));
			REQUIRE(mat[0][3] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(4.5f));
			REQUIRE(mat[1][1] == Approx(6.7f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[1][3] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));
			REQUIRE(mat[2][3] == Approx(0.0f));
			REQUIRE(mat[3][0] == Approx(0.0f));
			REQUIRE(mat[3][1] == Approx(0.0f));
			REQUIRE(mat[3][2] == Approx(0.0f));
			REQUIRE(mat[3][3] == Approx(0.0f));
		}

		SECTION("astares::Vector2 * 3") {
			astares::Matrix4 mat = astares::Matrix4(
				astares::Vector2(1.0f, 4.5f),
				astares::Vector2(3.4f, 8.5f),
				astares::Vector2(1.2f, 5.6f)
				);
			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(0.0f));
			REQUIRE(mat[0][3] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(3.4f));
			REQUIRE(mat[1][1] == Approx(8.5f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[1][3] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(1.2f));
			REQUIRE(mat[2][1] == Approx(5.6f));
			REQUIRE(mat[2][2] == Approx(0.0f));
			REQUIRE(mat[2][3] == Approx(0.0f));
			REQUIRE(mat[3][0] == Approx(0.0f));
			REQUIRE(mat[3][1] == Approx(0.0f));
			REQUIRE(mat[3][2] == Approx(0.0f));
			REQUIRE(mat[3][3] == Approx(0.0f));
		}
	}

	SECTION("Identity astares::Matrix") {
		const auto identity = astares::Matrix4::Identity;
		REQUIRE(identity[0][0] == Approx(1.0f));
		REQUIRE(identity[0][1] == Approx(0.0f));
		REQUIRE(identity[0][2] == Approx(0.0f));
		REQUIRE(identity[0][3] == Approx(0.0f));
		REQUIRE(identity[1][0] == Approx(0.0f));
		REQUIRE(identity[1][1] == Approx(1.0f));
		REQUIRE(identity[1][2] == Approx(0.0f));
		REQUIRE(identity[1][3] == Approx(0.0f));
		REQUIRE(identity[2][0] == Approx(0.0f));
		REQUIRE(identity[2][1] == Approx(0.0f));
		REQUIRE(identity[2][2] == Approx(1.0f));
		REQUIRE(identity[2][3] == Approx(0.0f));
		REQUIRE(identity[3][0] == Approx(0.0f));
		REQUIRE(identity[3][1] == Approx(0.0f));
		REQUIRE(identity[3][2] == Approx(0.0f));
		REQUIRE(identity[3][3] == Approx(1.0f));
	}

	astares::Matrix4 mat = {
		{ 1.5f, 1.6f, 1.7f, 5.6f },
		{ -5.6f, 7.8f, 0.9f, 1.2f },
		{ 0.0f, 45.6f, -1.0f, -6.7f },
		{ 1.4f, 5.6f, 7.8f, 0.9f }
	};

	SECTION("astares::Matrix functions") {
		SECTION("Inverse") {
			auto inverse = mat.GetInverse();
			REQUIRE(inverse[0][0] == Approx(0.0619358f));
			REQUIRE(inverse[0][1] == Approx(-0.159966f));
			REQUIRE(inverse[0][2] == Approx(0.0241995f));
			REQUIRE(inverse[0][3] == Approx(0.00806129f));
			REQUIRE(inverse[1][0] == Approx(0.0238821f));
			REQUIRE(inverse[1][1] == Approx(0.00559243f));
			REQUIRE(inverse[1][2] == Approx(0.0205305f));
			REQUIRE(inverse[1][3] == Approx(-0.00321824f));
			REQUIRE(inverse[2][0] == Approx(-0.0478414f));
			REQUIRE(inverse[2][1] == Approx(0.0206609f));
			REQUIRE(inverse[2][2] == Approx(-0.0182996f));
			REQUIRE(inverse[2][3] == Approx(0.133902f));
			REQUIRE(inverse[3][0] == Approx(0.169681f));
			REQUIRE(inverse[3][1] == Approx(0.0349782f));
			REQUIRE(inverse[3][2] == Approx(-0.00679263f));
			REQUIRE(inverse[3][3] == Approx(-0.0418886f));
		}

		SECTION("Transpose") {
			auto transpose = mat.GetTranspose();
			REQUIRE(transpose[0][0] == Approx(0.0f));
			REQUIRE(transpose[0][1] == Approx(0.0f));
			REQUIRE(transpose[0][2] == Approx(0.0f));
			REQUIRE(transpose[0][3] == Approx(0.0f));
			REQUIRE(transpose[1][0] == Approx(0.0f));
			REQUIRE(transpose[1][1] == Approx(0.0f));
			REQUIRE(transpose[1][2] == Approx(0.0f));
			REQUIRE(transpose[1][3] == Approx(0.0f));
			REQUIRE(transpose[2][0] == Approx(0.0f));
			REQUIRE(transpose[2][1] == Approx(0.0f));
			REQUIRE(transpose[2][2] == Approx(0.0f));
			REQUIRE(transpose[2][3] == Approx(0.0f));
			REQUIRE(transpose[3][0] == Approx(0.0f));
			REQUIRE(transpose[3][1] == Approx(0.0f));
			REQUIRE(transpose[3][2] == Approx(0.0f));
			REQUIRE(transpose[3][3] == Approx(0.0f));
		}

		SECTION("Adjoint") {
			auto adjoint = mat.GetAdjoint();
			REQUIRE(adjoint[0][0] == Approx(0.0f));
			REQUIRE(adjoint[0][1] == Approx(0.0f));
			REQUIRE(adjoint[0][2] == Approx(0.0f));
			REQUIRE(adjoint[0][3] == Approx(0.0f));
			REQUIRE(adjoint[1][0] == Approx(0.0f));
			REQUIRE(adjoint[1][1] == Approx(0.0f));
			REQUIRE(adjoint[1][2] == Approx(0.0f));
			REQUIRE(adjoint[1][3] == Approx(0.0f));
			REQUIRE(adjoint[2][0] == Approx(0.0f));
			REQUIRE(adjoint[2][1] == Approx(0.0f));
			REQUIRE(adjoint[2][2] == Approx(0.0f));
			REQUIRE(adjoint[2][3] == Approx(0.0f));
			REQUIRE(adjoint[3][0] == Approx(0.0f));
			REQUIRE(adjoint[3][1] == Approx(0.0f));
			REQUIRE(adjoint[3][2] == Approx(0.0f));
			REQUIRE(adjoint[3][3] == Approx(0.0f));

		}

		SECTION("Cofactor") {
			auto cofactor = mat.GetCofactorMatrix();
			REQUIRE(cofactor[0][0] == Approx(0.0f));
			REQUIRE(cofactor[0][1] == Approx(0.0f));
			REQUIRE(cofactor[0][2] == Approx(0.0f));
			REQUIRE(cofactor[0][3] == Approx(0.0f));
			REQUIRE(cofactor[1][0] == Approx(0.0f));
			REQUIRE(cofactor[1][1] == Approx(0.0f));
			REQUIRE(cofactor[1][2] == Approx(0.0f));
			REQUIRE(cofactor[1][3] == Approx(0.0f));
			REQUIRE(cofactor[2][0] == Approx(0.0f));
			REQUIRE(cofactor[2][1] == Approx(0.0f));
			REQUIRE(cofactor[2][2] == Approx(0.0f));
			REQUIRE(cofactor[2][3] == Approx(0.0f));
			REQUIRE(cofactor[3][0] == Approx(0.0f));
			REQUIRE(cofactor[3][1] == Approx(0.0f));
			REQUIRE(cofactor[3][2] == Approx(0.0f));
			REQUIRE(cofactor[3][3] == Approx(0.0f));
		}

		SECTION("Minor astares::Matrix") {
			auto minor00 = mat.GetMinor(0, 0);
			REQUIRE(minor00[0][0] == Approx(7.8f));
			REQUIRE(minor00[0][1] == Approx(0.9f));
			REQUIRE(minor00[1][0] == Approx(45.6f));
			REQUIRE(minor00[1][1] == Approx(-1.0f));

			auto minor12 = mat.GetMinor(2, 1);
			REQUIRE(minor12[0][0] == Approx(1.5f));
			REQUIRE(minor12[0][1] == Approx(1.7f));
			REQUIRE(minor12[1][0] == Approx(-5.6f));
			REQUIRE(minor12[1][1] == Approx(0.9f));

		}

		SECTION("Determinant") {
			REQUIRE(mat.GetDeterminant() == Approx(-516.332f));
		}
	}

	SECTION("astares::Matrix Operators") {
		SECTION("Addition") {
			SECTION("astares::Matrix") {
				auto result = mat + astares::Matrix4({
					{ 4.5f, 6.7f, 8.9f, 1.2f },
					{ -4.5f, 3.4f, 128.0f, 4.5f },
					{ 98.4567f, 34.5f, 67.5f, 6.7f },
					{ 23.4f, 5.6f, 7.8f, 1.3f }
				});

				REQUIRE(result[0][0] == Approx(0.0f));
				REQUIRE(result[0][1] == Approx(0.0f));
				REQUIRE(result[0][2] == Approx(0.0f));
				REQUIRE(result[0][3] == Approx(0.0f));
				REQUIRE(result[1][0] == Approx(0.0f));
				REQUIRE(result[1][1] == Approx(0.0f));
				REQUIRE(result[1][2] == Approx(0.0f));
				REQUIRE(result[1][3] == Approx(0.0f));
				REQUIRE(result[2][0] == Approx(0.0f));
				REQUIRE(result[2][1] == Approx(0.0f));
				REQUIRE(result[2][2] == Approx(0.0f));
				REQUIRE(result[2][3] == Approx(0.0f));
				REQUIRE(result[3][0] == Approx(0.0f));
				REQUIRE(result[3][1] == Approx(0.0f));
				REQUIRE(result[3][2] == Approx(0.0f));
				REQUIRE(result[3][3] == Approx(0.0f));
			}
		}

		SECTION("Subtraction") {
			SECTION("astares::Matrix") {
				auto result = mat - astares::Matrix4({
					{ 4.5f, 6.7f, 8.9f },
					{ -4.5f, 3.4f, 128.0f },
					{ 98.4567f, 34.5f, 67.5f }, 
					{ 5.6f, 1.2f, 1.4f, 1.5f }
				});

				REQUIRE(result[0][0] == Approx(0.0f));
				REQUIRE(result[0][1] == Approx(0.0f));
				REQUIRE(result[0][2] == Approx(0.0f));
				REQUIRE(result[0][3] == Approx(0.0f));
				REQUIRE(result[1][0] == Approx(0.0f));
				REQUIRE(result[1][1] == Approx(0.0f));
				REQUIRE(result[1][2] == Approx(0.0f));
				REQUIRE(result[1][3] == Approx(0.0f));
				REQUIRE(result[2][0] == Approx(0.0f));
				REQUIRE(result[2][1] == Approx(0.0f));
				REQUIRE(result[2][2] == Approx(0.0f));
				REQUIRE(result[2][3] == Approx(0.0f));
				REQUIRE(result[3][0] == Approx(0.0f));
				REQUIRE(result[3][1] == Approx(0.0f));
				REQUIRE(result[3][2] == Approx(0.0f));
				REQUIRE(result[3][3] == Approx(0.0f));
			}
		}

		SECTION("Multiplication") {
			SECTION("astares::Matrix") {
				auto result = mat * astares::Matrix4({
					{ 4.5f, 6.7f, 8.9f },
					{ -4.5f, 3.4f, 128.0f },
					{ 98.4567f, 34.5f, 67.5f },
					{ 0.0f, 0.0f, 0.0f, 0.0f }
				});

				REQUIRE(result[0][0] == Approx(0.0f));
				REQUIRE(result[0][1] == Approx(0.0f));
				REQUIRE(result[0][2] == Approx(0.0f));
				REQUIRE(result[0][3] == Approx(0.0f));
				REQUIRE(result[1][0] == Approx(0.0f));
				REQUIRE(result[1][1] == Approx(0.0f));
				REQUIRE(result[1][2] == Approx(0.0f));
				REQUIRE(result[1][3] == Approx(0.0f));
				REQUIRE(result[2][0] == Approx(0.0f));
				REQUIRE(result[2][1] == Approx(0.0f));
				REQUIRE(result[2][2] == Approx(0.0f));
				REQUIRE(result[2][3] == Approx(0.0f));
				REQUIRE(result[3][0] == Approx(0.0f));
				REQUIRE(result[3][1] == Approx(0.0f));
				REQUIRE(result[3][2] == Approx(0.0f));
				REQUIRE(result[3][3] == Approx(0.0f));
			}

			SECTION("Scalar") {
				auto result = mat * 13.456f;
				REQUIRE(result[0][0] == Approx(0.0f));
				REQUIRE(result[0][1] == Approx(0.0f));
				REQUIRE(result[0][2] == Approx(0.0f));
				REQUIRE(result[0][3] == Approx(0.0f));
				REQUIRE(result[1][0] == Approx(0.0f));
				REQUIRE(result[1][1] == Approx(0.0f));
				REQUIRE(result[1][2] == Approx(0.0f));
				REQUIRE(result[1][3] == Approx(0.0f));
				REQUIRE(result[2][0] == Approx(0.0f));
				REQUIRE(result[2][1] == Approx(0.0f));
				REQUIRE(result[2][2] == Approx(0.0f));
				REQUIRE(result[2][3] == Approx(0.0f));
				REQUIRE(result[3][0] == Approx(0.0f));
				REQUIRE(result[3][1] == Approx(0.0f));
				REQUIRE(result[3][2] == Approx(0.0f));
				REQUIRE(result[3][3] == Approx(0.0f));
			}

			SECTION("astares::Vector as matrix") {
				auto result = mat * astares::Vector4(4.5f, 6.7f, 8.9f, 5.6f);
				REQUIRE(result[0] == Approx(32.6f));
				REQUIRE(result[1] == Approx(35.07f));
				REQUIRE(result[2] == Approx(296.62f));
				REQUIRE(result[3] == Approx(296.62f));
			}
		}

		SECTION("Division") {
			SECTION("Scalar") {
				auto result = mat / 35.6f;
				REQUIRE(result[0][0] == Approx(0.0f));
				REQUIRE(result[0][1] == Approx(0.0f));
				REQUIRE(result[0][2] == Approx(0.0f));
				REQUIRE(result[0][3] == Approx(0.0f));
				REQUIRE(result[1][0] == Approx(0.0f));
				REQUIRE(result[1][1] == Approx(0.0f));
				REQUIRE(result[1][2] == Approx(0.0f));
				REQUIRE(result[1][3] == Approx(0.0f));
				REQUIRE(result[2][0] == Approx(0.0f));
				REQUIRE(result[2][1] == Approx(0.0f));
				REQUIRE(result[2][2] == Approx(0.0f));
				REQUIRE(result[2][3] == Approx(0.0f));
				REQUIRE(result[3][0] == Approx(0.0f));
				REQUIRE(result[3][1] == Approx(0.0f));
				REQUIRE(result[3][2] == Approx(0.0f));
				REQUIRE(result[3][3] == Approx(0.0f));
			}
		}
	}
}