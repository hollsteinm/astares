#include "catch.hpp"
#include <core\Types.h>
#include <Core.h>

#ifndef TEXT_COMPLEX
#define TEST_COMPLEX(type) SECTION(#type){  \
	REQUIRE(astares::TypeInfo<astares::type>::Name() == #type); \
	REQUIRE_FALSE(astares::TypeInfo<astares::type>::IsCollection()); \
	REQUIRE_FALSE(astares::TypeInfo<astares::type>::IsPointer()); \
	REQUIRE_FALSE(astares::TypeInfo<astares::type>::IsPrimitive()); }
#endif

#ifndef TEXT_PRIMITIVE
#define TEST_PRIMITIVE(type) SECTION(#type){  \
	REQUIRE(astares::TypeInfo<astares::type>::Name() == #type); \
	REQUIRE_FALSE(astares::TypeInfo<astares::type>::IsCollection()); \
	REQUIRE_FALSE(astares::TypeInfo<astares::type>::IsPointer()); \
	REQUIRE(astares::TypeInfo<astares::type>::IsPrimitive()); }
#endif

TEST_CASE("Core Types Info", "[core]") {

	SECTION("Primitives") {
		TEST_PRIMITIVE(int8);
		TEST_PRIMITIVE(int16);
		TEST_PRIMITIVE(int32);
		TEST_PRIMITIVE(int64);
		TEST_PRIMITIVE(uint8);
		TEST_PRIMITIVE(uint16);
		TEST_PRIMITIVE(uint32);
		TEST_PRIMITIVE(uint64);
		TEST_PRIMITIVE(f32);
		TEST_PRIMITIVE(f64);
	}

	SECTION("Complex") {	
		TEST_COMPLEX(string)
		TEST_COMPLEX(Box)
		TEST_COMPLEX(Hull)
		TEST_COMPLEX(Matrix2)
		TEST_COMPLEX(Matrix3)
		TEST_COMPLEX(Matrix4)
		TEST_COMPLEX(Plane)
		TEST_COMPLEX(Quaternion)
		TEST_COMPLEX(Ray2)
		TEST_COMPLEX(Ray3)
		TEST_COMPLEX(Sphere)
		TEST_COMPLEX(Transform)
		TEST_COMPLEX(Vector2)
		TEST_COMPLEX(Vector3)
		TEST_COMPLEX(Vector4)
		TEST_COMPLEX(UID)
	}

	SECTION("Type Query") {
		astares::Matrix4 mat;
		auto type = astares::TypeQuery::Query(mat);
		REQUIRE(strcmp(type.GetName(), "Matrix4")); 
		REQUIRE_FALSE(type.GetIsCollection()); 
		REQUIRE_FALSE(type.GetIsPointer()); 
		REQUIRE_FALSE(type.GetIsPrimitive());
	}
}