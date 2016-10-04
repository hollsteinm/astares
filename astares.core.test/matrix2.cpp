#include "catch.hpp"
#include <math\Matrix.h>

TEST_CASE("Matrix2", "[matrix]") {
	SECTION("Identity Matrix") {
		const astares::Matrix2& identity = astares::Matrix2::Identity;
		REQUIRE(identity[0][0] == 1.0f);
		REQUIRE(identity[0][1] == 0.0f);
		REQUIRE(identity[1][0] == 0.0f);
		REQUIRE(identity[1][1] == 1.0f);
	}

	SECTION("Constructors") {
		astares::Matrix2 mat;

		REQUIRE(mat[0][0] == 1.0f);
		REQUIRE(mat[0][1] == 0.0f);
		REQUIRE(mat[1][0] == 0.0f);
		REQUIRE(mat[1][1] == 1.0f);

		astares::Vector2 rows[2] = {
			astares::Vector2(0.1f, 5.0f),
			astares::Vector2(8.0f, 123.45f)
		};

		mat = astares::Matrix2(rows[0]);
		REQUIRE(mat[0][0] == rows[0][0]);
		REQUIRE(mat[0][1] == rows[0][1]);
		REQUIRE(mat[1][0] == 0.0f);
		REQUIRE(mat[1][1] == 0.0f);

		mat = astares::Matrix2(rows[0], rows[1]);
		REQUIRE(mat[0][0] == rows[0][0]);
		REQUIRE(mat[0][1] == rows[0][1]);
		REQUIRE(mat[1][0] == rows[1][0]);
		REQUIRE(mat[1][1] == rows[1][1]);

		mat = astares::Matrix2(astares::Matrix2({
			{ 0, 1.0f },
			{ 3.4f, 54.0f }
		}));

		REQUIRE(mat[0][0] == 0.0f);
		REQUIRE(mat[0][1] == 1.0f);
		REQUIRE(mat[1][0] == 3.4f);
		REQUIRE(mat[1][1] == 54.0f);
	}

	SECTION("Matrix Functions") {
		astares::Matrix2 mat = {
			{ 4.5f, 3.2f },
			{ 5.6f, 12.0f }
		};

		SECTION("Determinant") {
			REQUIRE(mat.GetDeterminant() == 36.08f);
		}

		SECTION("Adjoint") {
			auto adjoint = mat.GetAdjoint();
			REQUIRE(adjoint[0][0] == 12.0f);
			REQUIRE(adjoint[0][1] == -3.2f);
			REQUIRE(adjoint[1][0] == -5.6f);
			REQUIRE(adjoint[1][1] == 4.5f);
		}

		SECTION("Cofactor") {
			auto cofactor = mat.GetCofactorMatrix();
			REQUIRE(cofactor[0][0] == 12.0f);
			REQUIRE(cofactor[0][1] == -5.6f);
			REQUIRE(cofactor[1][0] == -3.2f);
			REQUIRE(cofactor[1][1] == 4.5f);
		}

		SECTION("Inverse") {
			auto inverse = mat.GetInverse();
			REQUIRE(inverse[0][0] == Approx(0.332594f));
			REQUIRE(inverse[0][1] == Approx(-0.0886918f));
			REQUIRE(inverse[1][0] == Approx(-0.155211f));
			REQUIRE(inverse[1][1] == Approx(0.124723f));
		}

		SECTION("Transpose") {
			auto transpose = mat.GetTranspose();
			REQUIRE(transpose[0][0] == 4.5f);
			REQUIRE(transpose[0][1] == 5.6f);
			REQUIRE(transpose[1][0] == 3.2f);
			REQUIRE(transpose[1][1] == 12.0f);
		}
	}

	SECTION("Buffer") {
		SECTION("Normal") {
			astares::f32 buffer[2][2] = {};
			astares::Matrix2 mat = {
				{ 4.5f, 3.2f },
				{ 5.6f, 12.0f }
			};
			REQUIRE(mat.ToBuffer(buffer) == 4);
			REQUIRE(buffer[0][0] == 4.5f);
			REQUIRE(buffer[0][1] == 3.2f);
			REQUIRE(buffer[1][0] == 5.6f);
			REQUIRE(buffer[1][1] == 12.0f);
		}
		SECTION("Transposed") {
			astares::f32 buffer[2][2] = {};
			astares::Matrix2 mat = {
				{ 4.5f, 3.2f },
				{ 5.6f, 12.0f }
			};
			REQUIRE(mat.ToBuffer(buffer, true) == 4);
			auto transposed = mat.GetTranspose();
			REQUIRE(buffer[0][0] == transposed[0][0]); 
			REQUIRE(buffer[0][1] == transposed[0][1]); 
			REQUIRE(buffer[1][0] == transposed[1][0]); 
			REQUIRE(buffer[1][1] == transposed[1][1]); 
		}
	}

	SECTION("Operators") {
		astares::Matrix2 mat = {
			{ 12.3f, 1.0f },
			{ 8.7f, 5.6f }
		};

		SECTION("Matrix plus Matrix") {
			auto result = mat + astares::Matrix2({
				{ 1.0f, 3.4f },
				{ 7.65f, 9.0f }
			});
			REQUIRE(result[0][0] == 13.3f);
			REQUIRE(result[0][1] == 4.4f);
			REQUIRE(result[1][0] == 16.35f);
			REQUIRE(result[1][1] == 14.6f);
		}

		SECTION("Matrix minus Matrix") {
			auto result = mat - astares::Matrix2({
				{ 1.0f, 3.4f },
				{ 7.65f, 9.0f }
			});
			REQUIRE(result[0][0] == Approx(11.3f));
			REQUIRE(result[0][1] == Approx(-2.4f));
			REQUIRE(result[1][0] == Approx(1.05f));
			REQUIRE(result[1][1] == Approx(-3.4f));
		}

		SECTION("Scalar multiplication") {
			auto result = mat * 2.5f;
			REQUIRE(result[0][0] == 30.75f);
			REQUIRE(result[0][1] == 2.5f);
			REQUIRE(result[1][0] == 21.75f);
			REQUIRE(result[1][1] == 14.0f);
		}

		SECTION("Matrix times Matrix") {
			auto result = mat * astares::Matrix2({
				{ 1.0f, 3.4f },
				{ 7.65f, 9.0f }
			});
			REQUIRE(result[0][0] == Approx(19.95f));
			REQUIRE(result[0][1] == Approx(50.82f));
			REQUIRE(result[1][0] == Approx(51.54f));
			REQUIRE(result[1][1] == Approx(79.98f));
		}

		SECTION("Scalar division") {
			auto result = mat / 2.3f;
			REQUIRE(result[0][0] == Approx(5.34783f));
			REQUIRE(result[0][1] == Approx(0.434783f));
			REQUIRE(result[1][0] == Approx(3.78261f));
			REQUIRE(result[1][1] == Approx(2.43478f));
		}

		SECTION("Vector Multiplication (column matrix)") {
			auto result = mat * astares::Vector2(3.4f, 5.6f);
			REQUIRE(result[0] == Approx(47.42f));
			REQUIRE(result[1] == Approx(60.94f));
		}
	}
}