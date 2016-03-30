#ifndef VECTOR_H
#define VECTOR_H

#include "../astares.core.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

#include <iosfwd>


ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Vector2& vec);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Vector2& vec);

ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Vector3& vec);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Vector3& vec);

ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Vector4& vec);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Vector4& vec);

ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Quaternion& vec);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Quaternion& vec);


#ifndef _X
#define _X 0
#endif

#ifndef _Y
#define _Y 1
#endif

#ifndef _Z
#define _Z 2
#endif

#ifndef _W
#define _W 3
#endif

#ifndef _UP
#define _UP Y
#endif

#ifndef _LEFT
#define _LEFT X
#endif

#ifndef _FORWARD
#define _FORWARD Z
#endif

#endif