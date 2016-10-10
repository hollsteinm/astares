#ifndef CORE_H
#define CORE_H

#include "astares.core.h"
#include "core\IConfig.h"
#include "core\IFile.h"
#include "core\ISubsystem.h"
#include "core\System.h"
#include "math\Geometry.h"
#include "math\Vector.h"
#include "math\Math.h"
#include "math\Matrix.h"
#include "core\UID.h"
#include "math\Transform.h"
#include "log\ILogger.h"
#include "log\CommonLogger.h"

namespace astares {
	DECL_CORE_TYPE(Box)
	DECL_CORE_TYPE(Hull)
	DECL_CORE_TYPE(Matrix2)
	DECL_CORE_TYPE(Matrix3)
	DECL_CORE_TYPE(Matrix4)
	DECL_CORE_TYPE(Plane)
	DECL_CORE_TYPE(Quaternion)
	DECL_CORE_TYPE(Ray2)
	DECL_CORE_TYPE(Ray3)
	DECL_CORE_TYPE(Sphere)
	DECL_CORE_TYPE(Transform)
	DECL_CORE_TYPE(Vector2)
	DECL_CORE_TYPE(Vector3)
	DECL_CORE_TYPE(Vector4)
	DECL_CORE_TYPE(UID)
}

#endif