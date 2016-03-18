#include "Math.h"

#include <cmath>
#include "../core/Types.h"

const f32 Math::Epsilon = 0.00000001f;

//We all know where this came from.
f32 Math::InverseSquareRoot(f32 value) {
	static_assert(sizeof(value) == 4, "not 32-bit");

	long i;
	f32 x2, y;
	const f32 threehalfs = 1.5f;

	x2 = value * 0.5f;
	y = value;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(f32 *)&i;
	y = y * (threehalfs - (x2 * y * y));  

	return y;
}

f32 Math::SquareRoot(f32 value) {
	return (f32)math::dsqrt((f64)value);
}

bool Math::LargerThanAlmostZero(f32 value) {
	value = std::fabsf(value);
	return value > Epsilon;
}

void Math::Correct(f32& value) {
	if (!LargerThanAlmostZero(value)) {
		value = 0.0f;
	}
}