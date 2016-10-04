#ifndef MATH_H
#define MATH_H

#include "../astares.core.h"
#include "../core/Types.h"

namespace astares
{
	struct ASTARESCORE_API Math {
		static const f32 Epsilon;

		static bool LargerThanAlmostZero(f32 value);

		static f32 SquareRoot(f32 value);
		static f32 InverseSquareRoot(f32 value);
		static void Correct(f32& value);
	};

	namespace math {
		static double inline __declspec (naked) __fastcall dsqrt(double n)
		{
			_asm fld qword ptr[esp + 4]
			_asm fsqrt
			_asm ret 8
		}
	}
}

#endif