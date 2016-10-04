#ifndef HULL_H
#define HULL_H

#include "Vector3.h"

namespace astares {

	DECL_CORE_STL(Vector3)

	struct ASTARESCORE_API Hull {
		Hull();
		Hull(const std::vector<Vector3>& points);

		std::vector<Vector3> Points;
	};
}
#endif