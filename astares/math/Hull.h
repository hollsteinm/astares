#ifndef HULL_H
#define HULL_H

#include "Vector3.h"
#include <vector>

struct Hull {
	Hull(const std::vector<Vector3>& points, int count);

	std::vector<Vector3> Points;
};


#endif