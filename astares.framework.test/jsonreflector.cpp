#include "catch.hpp"
#include <reflection\JSONReflector.h>
#include <object\Object.h>
#include <object\ObjectFactory.h>

class JSONTestObject : public Object
{
public:
	JSONTestObject()
		: Object(),
		int8Val(1),
		int16Val(2),
		int32Val(3),
		int64Val(4),
		uint8Val(5),
		uint16Val(6),
		uint32Val(7),
		uint64Val(8),
		f32Val(1.1f),
		f64Val(2.2f),
		gateVal(false),
		stringVal("one ton bricks"),
		uidVal(),
		vector2Val({ 1.0f, 2.0f }),
		vector3Val({ 1.0f, 2.0f, 3.0f }),
		vector4Val({ 1.0f, 2.0f, 3.0f, 4.0f }),
		matrix2Val({
			{ 1.0f, 2.0f },
			{ 3.0f, 4.0f }
		}),
		matrix3Val({
			{ 1.0f, 2.0f, 3.0f },
			{ 4.0f, 5.0f, 6.0f },
			{ 7.0f, 8.0f, 9.0f }
		}),
		matrix4Val({
			{ 1.0f, 2.0f, 3.0f, 4.0f },
			{ 5.0f, 6.0f, 7.0f, 8.0f },
			{ 9.0f, 10.0f, 11.0f, 12.0f },
			{ 13.0f, 14.0f, 15.0f, 16.0f }
		}),
		quatVal({ 1.0f, 2.0f, 3.0f, 4.0f }),
		planVal({ 1.0f, 2.0f, 3.0f }, 10.0f),
		ray2Val({ 1.0f, 2.0f }, { 1.0f, 0.5f }),
		ray3Val({ 1.0f, 2.0f, 3.0f }, { 1.0f, 0.5f, 0.25f }),
		sphereVal({ 1.0f, 2.0f, 3.0f }, 32.0f),
		hullVal({
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f },
			{ 1.0f, 2.0f, 3.0f }
		}),
		boxVal({ 1.0f, 2.0f, 3.0f }, { 1.0f, 2.0f, 3.0f }),
		tformVal(),
		objVal()
	{}

	REFLECTABLE
	SERIALIZEABLE(JSONTestObject)
	Object		objVal;

private:
	int8		int8Val;
	int16		int16Val;
	int32		int32Val;
	int64		int64Val;
	uint8		uint8Val;
	uint16		uint16Val;
	uint32		uint32Val;
	uint64		uint64Val;
	f32			f32Val;
	f64			f64Val;
	gate		gateVal;
	string		stringVal;
	UID			uidVal;
	Vector2		vector2Val;
	Vector3		vector3Val;
	Vector4		vector4Val;
	Matrix2		matrix2Val;
	Matrix3		matrix3Val;
	Matrix4		matrix4Val;
	Quaternion	quatVal;
	Plane		planVal;
	Ray2		ray2Val;
	Ray3		ray3Val;
	Sphere		sphereVal;
	Hull		hullVal;
	Box			boxVal;
	Transform	tformVal;
	vector<int8>		vec_int8Val;
	vector<int16>		vec_int16Val;
	vector<int32>		vec_int32Val;
	vector<int64>		vec_int64Val;
	vector<uint8>		vec_uint8Val;
	vector<uint16>		vec_uint16Val;
	vector<uint32>		vec_uint32Val;
	vector<uint64>		vec_uint64Val;
	vector<f32>			vec_f32Val;
	vector<f64>			vec_f64Val;
	vector<gate>		vec_gateVal;
	vector<string>		vec_stringVal;
	vector<UID>			vec_uidVal;
	vector<Vector2>		vec_vector2Val;
	vector<Vector3>		vec_vector3Val;
	vector<Vector4>		vec_vector4Val;
	vector<Matrix2>		vec_matrix2Val;
	vector<Matrix3>		vec_matrix3Val;
	vector<Matrix4>		vec_matrix4Val;
	vector<Quaternion>	vec_quatVal;
	vector<Plane>		vec_planVal;
	vector<Ray2>		vec_ray2Val;
	vector<Ray3>		vec_ray3Val;
	vector<Sphere>		vec_sphereVal;
	vector<Hull>		vec_hullVal;
	vector<Box>			vec_boxVal;
	vector<Transform>	vec_tformVal;
	queue<int8>			q_int8Val;
	queue<int16>		q_int16Val;
	queue<int32>		q_int32Val;
	queue<int64>		q_int64Val;
	queue<uint8>		q_uint8Val;
	queue<uint16>		q_uint16Val;
	queue<uint32>		q_uint32Val;
	queue<uint64>		q_uint64Val;
	queue<f32>			q_f32Val;
	queue<f64>			q_f64Val;
	queue<gate>			q_gateVal;
	queue<string>		q_stringVal;
	queue<UID>			q_uidVal;
	queue<Vector2>		q_queue2Val;
	queue<Vector3>		q_queue3Val;
	queue<Vector4>		q_queue4Val;
	queue<Matrix2>		q_matrix2Val;
	queue<Matrix3>		q_matrix3Val;
	queue<Matrix4>		q_matrix4Val;
	queue<Quaternion>	q_quatVal;
	queue<Plane>		q_planVal;
	queue<Ray2>			q_ray2Val;
	queue<Ray3>			q_ray3Val;
	queue<Sphere>		q_sphereVal;
	queue<Hull>			q_hullVal;
	queue<Box>			q_boxVal;
	queue<Transform>	q_tformVal;
	
};

DECL_OBJECT_VARIANT(JSONTestObject)

START_SERIAL(JSONTestObject)
PARENT_SERIAL(Object)
WRITE(int8Val)
WRITE(int16Val)
WRITE(int32Val)
WRITE(int64Val)
WRITE(uint8Val)
WRITE(uint16Val)
WRITE(uint32Val)
WRITE(uint64Val)
WRITE(f32Val)
WRITE(f64Val)
WRITE(gateVal)
WRITE(stringVal)
WRITE(uidVal)
WRITE(vector2Val)
WRITE(vector3Val)
WRITE(vector4Val)
WRITE(matrix2Val)
WRITE(matrix3Val)
WRITE(matrix4Val)
WRITE(quatVal)
WRITE(planVal)
WRITE(ray2Val)
WRITE(ray3Val)
WRITE(sphereVal)
WRITE(hullVal)
WRITE(boxVal)
WRITE(tformVal)
WRITE(objVal)
WRITE(vec_int8Val)
WRITE(vec_int16Val)
WRITE(vec_int32Val)
WRITE(vec_int64Val)
WRITE(vec_uint8Val)
WRITE(vec_uint16Val)
WRITE(vec_uint32Val)
WRITE(vec_uint64Val)
WRITE(vec_f32Val)
WRITE(vec_f64Val)
WRITE(vec_gateVal)
WRITE(vec_stringVal)
WRITE(vec_uidVal)
WRITE(vec_vector2Val)
WRITE(vec_vector3Val)
WRITE(vec_vector4Val)
WRITE(vec_matrix2Val)
WRITE(vec_matrix3Val)
WRITE(vec_matrix4Val)
WRITE(vec_quatVal)
WRITE(vec_planVal)
WRITE(vec_ray2Val)
WRITE(vec_ray3Val)
WRITE(vec_sphereVal)
WRITE(vec_hullVal)
WRITE(vec_boxVal)
WRITE(vec_tformVal)
WRITE(q_int8Val)
WRITE(q_int16Val)
WRITE(q_int32Val)
WRITE(q_int64Val)
WRITE(q_uint8Val)
WRITE(q_uint16Val)
WRITE(q_uint32Val)
WRITE(q_uint64Val)
WRITE(q_f32Val)
WRITE(q_f64Val)
WRITE(q_gateVal)
WRITE(q_stringVal)
WRITE(q_uidVal)
WRITE(q_queue2Val)
WRITE(q_queue3Val)
WRITE(q_queue4Val)
WRITE(q_matrix2Val)
WRITE(q_matrix3Val)
WRITE(q_matrix4Val)
WRITE(q_quatVal)
WRITE(q_planVal)
WRITE(q_ray2Val)
WRITE(q_ray3Val)
WRITE(q_sphereVal)
WRITE(q_hullVal)
WRITE(q_boxVal)
WRITE(q_tformVal)
END_SERIAL

START_DESERIAL(JSONTestObject)
PARENT_DESERIAL(Object)
READ(int8Val)
READ(int16Val)
READ(int32Val)
READ(int64Val)
READ(uint8Val)
READ(uint16Val)
READ(uint32Val)
READ(uint64Val)
READ(f32Val)
READ(f64Val)
READ(gateVal)
READ(stringVal)
READ(uidVal)
READ(vector2Val)
READ(vector3Val)
READ(vector4Val)
READ(matrix2Val)
READ(matrix3Val)
READ(matrix4Val)
READ(quatVal)
READ(planVal)
READ(ray2Val)
READ(ray3Val)
READ(sphereVal)
READ(hullVal)
READ(boxVal)
READ(tformVal)
READ(objVal)
READ(vec_int8Val)
READ(vec_int16Val)
READ(vec_int32Val)
READ(vec_int64Val)
READ(vec_uint8Val)
READ(vec_uint16Val)
READ(vec_uint32Val)
READ(vec_uint64Val)
READ(vec_f32Val)
READ(vec_f64Val)
READ(vec_gateVal)
READ(vec_stringVal)
READ(vec_uidVal)
READ(vec_vector2Val)
READ(vec_vector3Val)
READ(vec_vector4Val)
READ(vec_matrix2Val)
READ(vec_matrix3Val)
READ(vec_matrix4Val)
READ(vec_quatVal)
READ(vec_planVal)
READ(vec_ray2Val)
READ(vec_ray3Val)
READ(vec_sphereVal)
READ(vec_hullVal)
READ(vec_boxVal)
READ(vec_tformVal)
READ(q_int8Val)
READ(q_int16Val)
READ(q_int32Val)
READ(q_int64Val)
READ(q_uint8Val)
READ(q_uint16Val)
READ(q_uint32Val)
READ(q_uint64Val)
READ(q_f32Val)
READ(q_f64Val)
READ(q_gateVal)
READ(q_stringVal)
READ(q_uidVal)
READ(q_queue2Val)
READ(q_queue3Val)
READ(q_queue4Val)
READ(q_matrix2Val)
READ(q_matrix3Val)
READ(q_matrix4Val)
READ(q_quatVal)
READ(q_planVal)
READ(q_ray2Val)
READ(q_ray3Val)
READ(q_sphereVal)
READ(q_hullVal)
READ(q_boxVal)
READ(q_tformVal)
END_DESERIAL

START_PROPERTIES(JSONTestObject)
PARENT(Object)
PROPERTY(int8Val)
PROPERTY(int16Val)
PROPERTY(int32Val)
PROPERTY(int64Val)
PROPERTY(uint8Val)
PROPERTY(uint16Val)
PROPERTY(uint32Val)
PROPERTY(uint64Val)
PROPERTY(f32Val)
PROPERTY(f64Val)
PROPERTY(gateVal)
PROPERTY(stringVal)
PROPERTY(uidVal)
PROPERTY(vector2Val)
PROPERTY(vector3Val)
PROPERTY(vector4Val)
PROPERTY(matrix2Val)
PROPERTY(matrix3Val)
PROPERTY(matrix4Val)
PROPERTY(quatVal)
PROPERTY(planVal)
PROPERTY(ray2Val)
PROPERTY(ray3Val)
PROPERTY(sphereVal)
PROPERTY(hullVal)
PROPERTY(boxVal)
PROPERTY(tformVal)
PROPERTY(objVal)
PROPERTY(vec_int8Val)
PROPERTY(vec_int16Val)
PROPERTY(vec_int32Val)
PROPERTY(vec_int64Val)
PROPERTY(vec_uint8Val)
PROPERTY(vec_uint16Val)
PROPERTY(vec_uint32Val)
PROPERTY(vec_uint64Val)
PROPERTY(vec_f32Val)
PROPERTY(vec_f64Val)
PROPERTY(vec_gateVal)
PROPERTY(vec_stringVal)
PROPERTY(vec_uidVal)
PROPERTY(vec_vector2Val)
PROPERTY(vec_vector3Val)
PROPERTY(vec_vector4Val)
PROPERTY(vec_matrix2Val)
PROPERTY(vec_matrix3Val)
PROPERTY(vec_matrix4Val)
PROPERTY(vec_quatVal)
PROPERTY(vec_planVal)
PROPERTY(vec_ray2Val)
PROPERTY(vec_ray3Val)
PROPERTY(vec_sphereVal)
PROPERTY(vec_hullVal)
PROPERTY(vec_boxVal)
PROPERTY(vec_tformVal)
PROPERTY(q_int8Val)
PROPERTY(q_int16Val)
PROPERTY(q_int32Val)
PROPERTY(q_int64Val)
PROPERTY(q_uint8Val)
PROPERTY(q_uint16Val)
PROPERTY(q_uint32Val)
PROPERTY(q_uint64Val)
PROPERTY(q_f32Val)
PROPERTY(q_f64Val)
PROPERTY(q_gateVal)
PROPERTY(q_stringVal)
PROPERTY(q_uidVal)
PROPERTY(q_queue2Val)
PROPERTY(q_queue3Val)
PROPERTY(q_queue4Val)
PROPERTY(q_matrix2Val)
PROPERTY(q_matrix3Val)
PROPERTY(q_matrix4Val)
PROPERTY(q_quatVal)
PROPERTY(q_planVal)
PROPERTY(q_ray2Val)
PROPERTY(q_ray3Val)
PROPERTY(q_sphereVal)
PROPERTY(q_hullVal)
PROPERTY(q_boxVal)
PROPERTY(q_tformVal)
END_PROPERTIES

TEST_CASE("JSONReflector", "[reflection]") {
	SECTION("Validate JSON") {
		REGISTER_TYPE(JSONTestObject)
		JSONReflector reflector;
		JSONTestObject obj;
		obj.Reflect(&reflector);
		string* noHeapSpaceLost = new string("{\"$type\":\"JSONTestObject\",\"$parents\":[\"Object\"],\"instanceId\":\"" + obj.GetInstanceId().ToString() + "\",\"int8Val\":\"\",\"int16Val\":2,\"int32Val\":3,\"int64Val\":4,\"uint8Val\":\"\",\"uint16Val\":6,\"uint32Val\":7,\"uint64Val\":8,\"f32Val\":1.1,\"f64Val\":2.2,\"gateVal\":false,\"stringVal\":\"one ton bricks\",\"uidVal\":\"0-0\",\"vector2Val\":{\"X\":1.000000,\"Y\":2.000000},\"vector3Val\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},\"vector4Val\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000,\"W\":4.000000},\"matrix2Val\":{\"M00\":1.000000,\"M01\":2.000000,\"M10\":3.000000,\"M11\":4.000000},\"matrix3Val\":{\"M00\":1.000000,\"M01\":2.000000,\"M02\":3.000000,\"M10\":4.000000,\"M11\":5.000000,\"M12\":6.000000,\"M20\":7.000000,\"M21\":8.000000,\"M22\":9.000000},\"matrix4Val\":{\"M00\":1.000000,\"M01\":2.000000,\"M02\":3.000000,\"M03\":4.000000,\"M10\":5.000000,\"M11\":6.000000,\"M12\":7.000000,\"M13\":8.000000,\"M20\":9.000000,\"M21\":10.000000,\"M22\":11.000000,\"M23\":12.000000,\"M30\":13.000000,\"M31\":14.000000,\"M32\":15.000000,\"M33\":16.000000},\"quatVal\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000,\"W\":4.000000},\"planVal\":{\"Normal\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},\"Offset\":10.000000},\"ray2Val\":{\"Direction\":{\"X\":1.000000,\"Y\":0.500000},\"Origin\":{\"X\":1.000000,\"Y\":2.000000}},\"ray3Val\":{\"Direction\":{\"X\":1.000000,\"Y\":0.500000,\"Z\":0.250000},\"Origin\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000}},\"sphereVal\":{\"Center\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},\"Radius\":32.000000},\"hullVal\":{\"Points\":[{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000}]},\"boxVal\":{\"Center\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000},\"Halfsize\":{\"X\":1.000000,\"Y\":2.000000,\"Z\":3.000000}},\"tformVal\":{\"Position\":{\"X\":0.000000,\"Y\":0.000000,\"Z\":0.000000},\"Rotation\":{\"X\":0.000000,\"Y\":0.000000,\"Z\":0.000000},\"Scale\":{\"X\":0.000000,\"Y\":0.000000,\"Z\":0.000000}},\"objVal\":{\"$type\":\"Object\",\"$parents\":[],\"instanceId\":\"" + obj.objVal.GetInstanceId().ToString() + "\"}}");
		REQUIRE(reflector.ToString() == *noHeapSpaceLost);
		delete noHeapSpaceLost;
	}
}