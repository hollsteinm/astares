#include <object\Object.h>

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
				objVal(),
				vec_objVal({
				Object(),
				Object(),
				Object()
			}),
			q_objVal({
					Object()
				})
	{}
					PRODUCTABLE
					REFLECTABLE
						SERIALIZEABLE(JSONTestObject)
						Object			objVal;
					vector<Object>	vec_objVal;
					queue<Object>	q_objVal;
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