#ifndef VECTOR_H
#define VECTOR_H

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"
#include "../reflection/Reflection.h"

#include <iostream>


std::ostream& operator<<(std::ostream& out, const Vector2& vec);
std::istream& operator>>(std::istream& in, Vector2& vec);

std::ostream& operator<<(std::ostream& out, const Vector3& vec);
std::istream& operator>>(std::istream& in, Vector3& vec);

std::ostream& operator<<(std::ostream& out, const Vector4& vec);
std::istream& operator>>(std::istream& in, Vector4& vec);

std::ostream& operator<<(std::ostream& out, const Quaternion& vec);
std::istream& operator>>(std::istream& in, Quaternion& vec);


TYPE(Vector2)
TYPE(Vector3)
TYPE(Vector4)
TYPE(Quaternion)

#define GREEDY_LOAD_VECTOR_TYPES TYPEOF(Vector2); TYPEOF(Vector3); TYPEOF(Vector4); TYPEOF(Quaternion);

#ifndef X
#define X 0
#endif

#ifndef Y
#define Y 1
#endif

#ifndef Z
#define Z 2
#endif

#ifndef W
#define W 3
#endif

#ifndef UP
#define UP Y
#endif

#ifndef LEFT
#define LEFT X
#endif

#ifndef FORWARD
#define FORWARD Z
#endif

#endif