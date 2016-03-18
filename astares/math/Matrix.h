#ifndef MATRIX_H
#define MATRIX_H

#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

std::ostream& operator<<(std::ostream& out, Matrix2& vec);
std::istream& operator>>(std::istream& in, Matrix2& vec);

std::ostream& operator<<(std::ostream& out, Matrix3& vec);
std::istream& operator>>(std::istream& in, Matrix3& vec);

std::ostream& operator<<(std::ostream& out, Matrix4& vec);
std::istream& operator>>(std::istream& in, Matrix4& vec);

#endif