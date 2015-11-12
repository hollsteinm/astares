#include "Math.h"

#include <cmath>

const float Math::Epsilon = 0.00000001f;

//We all know where this came from.
float Math::InverseSquareRoot(float value) {
	static_assert(sizeof(value) == 4, "not 32-bit");

	long i;
	float x2, y;
	const float threehalfs = 1.5f;

	x2 = value * 0.5f;
	y = value;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));  

	return y;
}

float Math::SquareRoot(float value) {
	return (float)math::dsqrt((double)value);
}

bool Math::LargerThanAlmostZero(float value) {
	value = std::fabsf(value);
	return value > Epsilon;
}

void Math::Correct(float& value) {
	if (!LargerThanAlmostZero(value)) {
		value = 0.0f;
	}
}