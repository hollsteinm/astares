#include "Hull.h"

using namespace astares;

Hull::Hull()
	:Points()
{}

Hull::Hull(const std::vector<Vector3>& points) : Points(points)
{}