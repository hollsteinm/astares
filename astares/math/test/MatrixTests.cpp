#include "MatrixTests.h"
#include "../Matrix.h"

void test::matrix::Console() {
	Matrix3 m(
		Vector3(4, 3, 9),
		Vector3(0, 2, 8),
		Vector3(5, 1, 0));

	Matrix2 t(
		Vector2(1, 3),
		Vector2(9, 5));

	Matrix4 f(
		Vector4(5, 6, 4, 0),
		Vector4(1, 4, 3, 9),
		Vector4(0, 0, 2, 8),
		Vector4(2, 5, 1, 0));

	std::cout << "Matrix2" << std::endl << std::endl;
	std::cout << "Original\n=======\n" << t.ToString() << std::endl << std::endl;
	std::cout << "Determinant\n=======\n" << t.GetDeterminant() << std::endl << std::endl;
	std::cout << "Transpose\n=======\n" << t.GetTranspose().ToString() << std::endl << std::endl;
	std::cout << "Cofactor\n=======\n" << t.GetCofactorMatrix().ToString() << std::endl << std::endl;
	std::cout << "Adjoint\n=======\n" << t.GetAdjoint().ToString() << std::endl << std::endl;
	std::cout << "Inverse\n=======\n" << t.GetInverse().ToString() << std::endl << std::endl;
	std::cout << "Proof of Inverse\n=======\n" << (t * t.GetInverse()).ToString() << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "Matrix3" << std::endl << std::endl;
	std::cout << "Original\n=======\n" << m.ToString() << std::endl << std::endl;
	std::cout << "Determinant\n=======\n" << m.GetDeterminant() << std::endl << std::endl;
	std::cout << "Transpose\n=======\n" << m.GetTranspose().ToString() << std::endl << std::endl;
	std::cout << "Cofactor\n=======\n" << m.GetCofactorMatrix().ToString() << std::endl << std::endl;
	std::cout << "Adjoint\n=======\n" << m.GetAdjoint().ToString() << std::endl << std::endl;
	std::cout << "Inverse\n=======\n" << m.GetInverse().ToString() << std::endl << std::endl;
	std::cout << "Proof of Inverse\n=======\n" << (m * m.GetInverse()).ToString() << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "Matrix4" << std::endl << std::endl;
	std::cout << "Original\n=======\n" << f.ToString() << std::endl << std::endl;
	std::cout << "Determinant\n=======\n" << f.GetDeterminant() << std::endl << std::endl;
	std::cout << "Transpose\n=======\n" << f.GetTranspose().ToString() << std::endl << std::endl;
	std::cout << "Cofactor\n=======\n" << f.GetCofactorMatrix().ToString() << std::endl << std::endl;
	std::cout << "Adjoint\n=======\n" << f.GetAdjoint().ToString() << std::endl << std::endl;
	std::cout << "Inverse\n=======\n" << f.GetInverse().ToString() << std::endl << std::endl;
	std::cout << "Proof of Inverse\n=======\n" << (f * f.GetInverse()).ToString() << std::endl;
}