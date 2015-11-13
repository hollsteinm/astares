#ifndef HULL_H
#define HULL_H

#include "Vector3.h"
#include "../core/Array.h"

struct Hull {
	Hull(const Array<Vector3>& points, int count);

	Array<Vector3> Points;
};


#endif