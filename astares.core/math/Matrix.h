#ifndef MATRIX_H
#define MATRIX_H

#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Matrix2& vec);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Matrix2& vec);

ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Matrix3& vec);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Matrix3& vec);

ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Matrix4& vec);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Matrix4& vec);

#endif