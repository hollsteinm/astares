#ifndef MATH_H
#define MATH_H



struct Math {
	static const float Epsilon;

	static bool LargerThanAlmostZero(float value);

	static float SquareRoot(float value);
	static float InverseSquareRoot(float value);
	static void Correct(float& value);
};

namespace math {
	static double inline __declspec (naked) __fastcall dsqrt(double n)
	{
		_asm fld qword ptr[esp + 4]
		_asm fsqrt
		_asm ret 8
	}
}


#endif