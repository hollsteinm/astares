#ifndef VECTOR_H
#define VECTOR_H

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

#include <iosfwd>


std::ostream& operator<<(std::ostream& out, const Vector2& vec);
std::istream& operator>>(std::istream& in, Vector2& vec);

std::ostream& operator<<(std::ostream& out, const Vector3& vec);
std::istream& operator>>(std::istream& in, Vector3& vec);

std::ostream& operator<<(std::ostream& out, const Vector4& vec);
std::istream& operator>>(std::istream& in, Vector4& vec);

std::ostream& operator<<(std::ostream& out, const Quaternion& vec);
std::istream& operator>>(std::istream& in, Quaternion& vec);


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