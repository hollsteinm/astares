#ifndef HULL_H
#define HULL_H

#include "Vector3.h"

DECL_CORE_STL(Vector3)

struct ASTARESCORE_API Hull {
	Hull(const vector<Vector3>& points, int32 count);

	vector<Vector3> Points;
};


#endif