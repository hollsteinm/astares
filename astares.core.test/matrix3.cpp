#include "catch.hpp"
#include <math/Matrix.h>

TEST_CASE("Matrix3", "[matrix]") {
	SECTION("Constructors") {
		SECTION("Vector3") {
			Matrix3 mat = Matrix3(Vector3(1.0f, 4.5f, 3.4f));

			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(3.4f));
			REQUIRE(mat[1][0] == Approx(0.0f));
			REQUIRE(mat[1][1] == Approx(0.0f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));

		}

		SECTION("Vector3 * 2") {
			Matrix3 mat = Matrix3(
				Vector3(1.0f, 4.5f, 3.4f),
				Vector3(4.5f, 6.7f, 8.7f)
				);

			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(3.4f));
			REQUIRE(mat[1][0] == Approx(4.5f));
			REQUIRE(mat[1][1] == Approx(6.7f));
			REQUIRE(mat[1][2] == Approx(8.7f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));
		}

		SECTION("Vector3 * 3") {
			Matrix3 mat = Matrix3(
				Vector3(1.0f, 4.5f, 3.4f),
				Vector3(4.5f, 6.7f, 8.7f),
				Vector3(4.5f, 7.7f, 8.7f));

			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(3.4f));
			REQUIRE(mat[1][0] == Approx(4.5f));
			REQUIRE(mat[1][1] == Approx(6.7f));
			REQUIRE(mat[1][2] == Approx(8.7f));
			REQUIRE(mat[2][0] == Approx(4.5f));
			REQUIRE(mat[2][1] == Approx(7.7f));
			REQUIRE(mat[2][2] == Approx(8.7f));
		}

		SECTION("Vector2") {
			Matrix3 mat = Matrix3(Vector2(1.0f, 4.5f));

			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(0.0f));
			REQUIRE(mat[1][1] == Approx(0.0f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));
		}

		SECTION("Vector2 * 2") {
			Matrix3 mat = Matrix3(
				Vector2(1.0f, 4.5f),
				Vector2(4.5f, 6.7f)
				);

			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(4.5f));
			REQUIRE(mat[1][1] == Approx(6.7f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(0.0f));
			REQUIRE(mat[2][1] == Approx(0.0f));
			REQUIRE(mat[2][2] == Approx(0.0f));
		}

		SECTION("Vector2 * 3") {
			Matrix3 mat = Matrix3(
				Vector2(1.0f, 4.5f),
				Vector2(3.4f, 8.5f),
				Vector2(1.2f, 5.6f)
				);

			REQUIRE(mat[0][0] == Approx(1.0f));
			REQUIRE(mat[0][1] == Approx(4.5f));
			REQUIRE(mat[0][2] == Approx(0.0f));
			REQUIRE(mat[1][0] == Approx(3.4f));
			REQUIRE(mat[1][1] == Approx(8.5f));
			REQUIRE(mat[1][2] == Approx(0.0f));
			REQUIRE(mat[2][0] == Approx(1.2f));
			REQUIRE(mat[2][1] == Approx(5.6f));
			REQUIRE(mat[2][2] == Approx(0.0f));
		}
	}

	SECTION("Identity Matrix") {
		const auto identity = Matrix3::Identity;

		REQUIRE(identity[0][0] == Approx(1.0f));
		REQUIRE(identity[0][1] == Approx(0.0f));
		REQUIRE(identity[0][2] == Approx(0.0f));
		REQUIRE(identity[1][0] == Approx(0.0f));
		REQUIRE(identity[1][1] == Approx(1.0f));
		REQUIRE(identity[1][2] == Approx(0.0f));
		REQUIRE(identity[2][0] == Approx(0.0f));
		REQUIRE(identity[2][1] == Approx(0.0f));
		REQUIRE(identity[2][2] == Approx(1.0f));
	}

	Matrix3 mat = {
		{ 1.5f, 1.6f, 1.7f },
		{ -5.6f, 7.8f, 0.9f },
		{ 0.0f, 45.6f, -1.0f }
	};

	SECTION("Matrix functions") {
		SECTION("Inverse") {
			auto inverse = mat.GetInverse();
			REQUIRE(inverse[0][0] == Approx(0.0945903f));
			REQUIRE(inverse[0][1] == Approx(-0.153235f));
			REQUIRE(inverse[0][2] == Approx(0.0228922f));
			REQUIRE(inverse[1][0] == Approx(0.0108457f));
			REQUIRE(inverse[1][1] == Approx(0.00290511f));
			REQUIRE(inverse[1][2] == Approx(0.0210523f));
			REQUIRE(inverse[2][0] == Approx(0.494566f));
			REQUIRE(inverse[2][1] == Approx(0.132473f));
			REQUIRE(inverse[2][2] == Approx(-0.040013f));
		}

		SECTION("Transpose") {
			auto transpose = mat.GetTranspose();
			REQUIRE(transpose[0][0] == Approx(1.5f));
			REQUIRE(transpose[0][1] == Approx(-5.6f));
			REQUIRE(transpose[0][2] == Approx(0.0f));
			REQUIRE(transpose[1][0] == Approx(1.6f));
			REQUIRE(transpose[1][1] == Approx(7.8f));
			REQUIRE(transpose[1][2] == Approx(45.6f));
			REQUIRE(transpose[2][0] == Approx(1.7f));
			REQUIRE(transpose[2][1] == Approx(0.9f));
			REQUIRE(transpose[2][2] == Approx(-1.0f));
		}

		SECTION("Adjoint") {
			auto adjoint = mat.GetAdjoint();
			REQUIRE(adjoint[0][0] == Approx(-48.84f));
			REQUIRE(adjoint[0][1] == Approx(79.12f));
			REQUIRE(adjoint[0][2] == Approx(-11.82f));
			REQUIRE(adjoint[1][0] == Approx(-5.6f));
			REQUIRE(adjoint[1][1] == Approx(-1.5f));
			REQUIRE(adjoint[1][2] == Approx(-10.87f));
			REQUIRE(adjoint[2][0] == Approx(-255.36f));
			REQUIRE(adjoint[2][1] == Approx(-68.4f));
			REQUIRE(adjoint[2][2] == Approx(20.66f));

		}

		SECTION("Cofactor") {
			auto cofactor = mat.GetCofactorMatrix();
			REQUIRE(cofactor[0][0] == Approx(-48.84f));
			REQUIRE(cofactor[0][1] == Approx(-5.6f));
			REQUIRE(cofactor[0][2] == Approx(-255.36f));
			REQUIRE(cofactor[1][0] == Approx(79.12f));
			REQUIRE(cofactor[1][1] == Approx(-1.5f));
			REQUIRE(cofactor[1][2] == Approx(-68.4f));
			REQUIRE(cofactor[2][0] == Approx(-11.82f));
			REQUIRE(cofactor[2][1] == Approx(-10.87f));
			REQUIRE(cofactor[2][2] == Approx(20.66f));
		}

		SECTION("Minor Matrix") {
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

	SECTION("Matrix Operators") {
		SECTION("Addition") {
			SECTION("Matrix") {
				auto result = mat + Matrix3({
					{ 4.5f, 6.7f, 8.9f },
					{ -4.5f, 3.4f, 128.0f },
					{ 98.4567f, 34.5f, 67.5f }
				});

				REQUIRE(result[0][0] == Approx(6.0f));
				REQUIRE(result[0][1] == Approx(8.3f));
				REQUIRE(result[0][2] == Approx(10.6f));
				REQUIRE(result[1][0] == Approx(-10.1f));
				REQUIRE(result[1][1] == Approx(11.2f));
				REQUIRE(result[1][2] == Approx(128.9f));
				REQUIRE(result[2][0] == Approx(98.4567f));
				REQUIRE(result[2][1] == Approx(80.1f));
				REQUIRE(result[2][2] == Approx(66.5f));
			}
		}

		SECTION("Subtraction") {
			SECTION("Matrix") {
				auto result = mat - Matrix3({
					{ 4.5f, 6.7f, 8.9f },
					{ -4.5f, 3.4f, 128.0f },
					{ 98.4567f, 34.5f, 67.5f }
				});

				REQUIRE(result[0][0] == Approx(-3.0f));
				REQUIRE(result[0][1] == Approx(-5.1f));
				REQUIRE(result[0][2] == Approx(-7.2f));
				REQUIRE(result[1][0] == Approx(-1.1f));
				REQUIRE(result[1][1] == Approx(4.4f));
				REQUIRE(result[1][2] == Approx(-127.1f));
				REQUIRE(result[2][0] == Approx(-98.4567f));
				REQUIRE(result[2][1] == Approx(11.1f));
				REQUIRE(result[2][2] == Approx(-68.5f));
			}
		}

		SECTION("Multiplication") {
			SECTION("Matrix") {
				auto result = mat * Matrix3({
					{ 4.5f, 6.7f, 8.9f },
					{ -4.5f, 3.4f, 128.0f },
					{ 98.4567f, 34.5f, 67.5f }
				});

				REQUIRE(result[0][0] == Approx(166.926f));
				REQUIRE(result[0][1] == Approx(74.14f));
				REQUIRE(result[0][2] == Approx(332.9f));
				REQUIRE(result[1][0] == Approx(28.311f));
				REQUIRE(result[1][1] == Approx(20.05f));
				REQUIRE(result[1][2] == Approx(1009.31f));
				REQUIRE(result[2][0] == Approx(-303.657f));
				REQUIRE(result[2][1] == Approx(120.54f));
				REQUIRE(result[2][2] == Approx(5769.3f));
			}

			SECTION("Scalar") {
				auto result = mat * 13.456f;
				REQUIRE(result[0][0] == Approx(20.184f));
				REQUIRE(result[0][1] == Approx(21.5296f));
				REQUIRE(result[0][2] == Approx(22.8752f));
				REQUIRE(result[1][0] == Approx(-75.3536f));
				REQUIRE(result[1][1] == Approx(104.957f));
				REQUIRE(result[1][2] == Approx(12.1104f));
				REQUIRE(result[2][0] == Approx(0.0f));
				REQUIRE(result[2][1] == Approx(613.594f));
				REQUIRE(result[2][2] == Approx(-13.456f));
			}

			SECTION("Vector as matrix") {
				auto result = mat * Vector3(4.5f, 6.7f, 8.9f);
				REQUIRE(result[0] == Approx(32.6f));
				REQUIRE(result[1] == Approx(35.07f));
				REQUIRE(result[2] == Approx(296.62f));
			}
		}

		SECTION("Division") {
			SECTION("Scalar") {
				auto result = mat / 35.6f;
				REQUIRE(result[0][0] == Approx(0.0421348f));
				REQUIRE(result[0][1] == Approx(0.0449438f));
				REQUIRE(result[0][2] == Approx(0.0477528f));
				REQUIRE(result[1][0] == Approx(-0.157303f));
				REQUIRE(result[1][1] == Approx(0.219101f));
				REQUIRE(result[1][2] == Approx(0.0252809f));
				REQUIRE(result[2][0] == Approx(0.0f));
				REQUIRE(result[2][1] == Approx(1.2809f));
				REQUIRE(result[2][2] == Approx(-0.0280899f));
			}
		}
	}
}