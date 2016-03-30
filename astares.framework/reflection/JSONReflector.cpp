#include "JSONReflector.h"
#include "../object/Object.h"
#include "../object/ObjectFactory.h"
#include <functional>

#define WRITE_MAT(dim)														\
		{																	\
			Matrix##dim* mat = new Matrix##dim();							\
			((Variant&)variant).Get(*mat);									\
			content.append(1, OpenToken);									\
			for (int32 i = 0; i < dim; ++i)									\
			{																\
				for (int32 j = 0; j < dim; ++j)								\
				{															\
					content.append("\"M")									\
						.append(std::to_string(i))							\
						.append(std::to_string(j))							\
						.append(1, QuoteToken)								\
						.append(1, PropertyToken)							\
						.append(std::to_string(mat->m[i][j]))				\
						.append(1, SeperatorToken);							\
				}															\
			}																\
			content.replace(content.find_last_of(SeperatorToken), 1, "");	\
			content.append(1, CloseToken);									\
			delete mat;														\
		}

#define WRITE_VEC(dim, ...)													\
		{																	\
			Vector##dim* vec = new Vector##dim();							\
			((Variant&)variant).Get(*vec);									\
			float data[dim] = {};											\
			vec->ToBuffer(data);											\
			content.append(GetVectorContentString({ __VA_ARGS__ },			\
				vector<f32>(&data[0], &data[0] + dim)));					\
			delete vec;														\
		}

#define WRITE_RAY(dim, ...)										\
		{														\
			Ray##dim* ray = new Ray##dim();						\
			((Variant&)variant).Get(*ray);						\
			float dir[dim] = {};								\
			float org[dim] = {};								\
			ray->Direction.ToBuffer(dir);						\
			ray->Origin.ToBuffer(org);							\
			content.append(1, OpenToken)						\
				.append("\"Direction\"")						\
				.append(1, PropertyToken)						\
				.append(GetVectorContentString({ __VA_ARGS__ },	\
				vector<f32>(&dir[0], &dir[0] + dim)))			\
				.append(1, SeperatorToken)						\
				.append("\"Origin\"")							\
				.append(1, PropertyToken)						\
				.append(GetVectorContentString({ __VA_ARGS__ },	\
				vector<f32>(&org[0], &org[0] + dim)))			\
				.append(1, CloseToken);							\
			delete ray;											\
		}


static const int8 OpenToken = '{';
static const int8 CloseToken = '}';
static const int8 ArrayStartToken = '[';
static const int8 ArrayEndToken = ']';
static const int8 PropertyToken = ':';
static const int8 SeperatorToken = ',';
static const int8 QuoteToken = '"';
static const string TypeProperty = "\"$type\"";
static const string ParentProperty = "\"$parents\"";

void JSONReflector::SetType(const Variant& variant)
{
	if (highestOrderType.empty())
	{
		highestOrderType = variant.GetName();
	}
	else
	{
		parents.push_back(variant.GetName());
	}
}

string JSONReflector::ToString() const
{
	string result;
	result.append(1, OpenToken)
		.append(TypeProperty)
		.append(1, PropertyToken)
		.append(1, QuoteToken)
		.append(highestOrderType)
		.append(1, QuoteToken)
		.append(1, SeperatorToken)
		.append(ParentProperty)
		.append(1, PropertyToken)
		.append(1, ArrayStartToken);
	for (auto parent : parents)
	{
		result.append(1, QuoteToken)
			.append(parent)
			.append(1, QuoteToken)
			.append(1, SeperatorToken);
	}
	if (parents.size() > 0)
	{
		result.replace(result.find_last_of(SeperatorToken), 1, "");
	}
	result.append(1, ArrayEndToken)
		.append(1, SeperatorToken)
		.append(content)
		.append(1, CloseToken);
	result.replace(result.find_last_of(SeperatorToken), 1, "");
	return result;
}

void JSONReflector::WriteString(const Variant& variant)
{
	content.append(1, QuoteToken)
		.append(variant.Value())
		.append(1, QuoteToken);
}

void JSONReflector::WriteBoolean(const Variant& variant)
{
	gate g;
	((Variant&)variant).Get(g);
	content.append(g ? "true" : "false");
}

void JSONReflector::WriteNumeric(const Variant& variant)
{
	content.append(variant.Value());
}

#define ARRAY_STRAT(ElemType, ElemFunc) [this](const Variant& variant){ vector<ElemType> data; variant.Get(data); for(auto elem : data) { ElemFunc(Variant(elem)); content.append(1, SeperatorToken); } if (data.size() > 0) { content.replace(content.find_last_of(SeperatorToken), 1, ""); } }

#define VECTOR_STRAT(dim, ...) [this](const Variant& var) { vector<Vector##dim> data; for(auto elem : data) { Variant variant(elem); WRITE_VEC(dim, __VA_ARGS__) }}

#define MATRIX_STRAT(dim) [this](const Variant& var) { vector<Matrix##dim> data; for(auto elem : data) { Variant variant(elem); WRITE_MAT(dim) }}

#define RAY_STRAT(dim, ...) [this](const Variant& var) { vector<Ray##dim> data; for(auto elem : data) { Variant variant(elem); WRITE_RAY(dim, __VA_ARGS__) }}

void JSONReflector::WriteArrayType(const Variant& variant)
{
	static const map<int64, std::function<void(const Variant&)>> strategy =
	{
		{ VariantTypeId<vector<int8>>::GetCustomType(),	ARRAY_STRAT(int8, WriteString)},
		{ VariantTypeId<vector<int16>>::GetCustomType(), ARRAY_STRAT(int16, WriteNumeric) },
		{ VariantTypeId<vector<int32>>::GetCustomType(), ARRAY_STRAT(int32, WriteNumeric) },
		{ VariantTypeId<vector<int64>>::GetCustomType(), ARRAY_STRAT(int64, WriteNumeric) },
		{ VariantTypeId<vector<uint8>>::GetCustomType(), ARRAY_STRAT(uint8, WriteString) },
		{ VariantTypeId<vector<uint16>>::GetCustomType(), ARRAY_STRAT(uint16, WriteNumeric) },
		{ VariantTypeId<vector<uint32>>::GetCustomType(), ARRAY_STRAT(uint32, WriteNumeric) },
		{ VariantTypeId<vector<uint64>>::GetCustomType(), ARRAY_STRAT(uint64, WriteNumeric) },
		{ VariantTypeId<vector<f32>>::GetCustomType(), ARRAY_STRAT(f32, WriteNumeric) },
		{ VariantTypeId<vector<f64>>::GetCustomType(), ARRAY_STRAT(f64, WriteNumeric) },
		{ VariantTypeId<vector<gate>>::GetCustomType(), ARRAY_STRAT(gate, WriteBoolean) },
		{ VariantTypeId<vector<string>>::GetCustomType(), ARRAY_STRAT(string, WriteString) },
		{ VariantTypeId<vector<UID>>::GetCustomType(), ARRAY_STRAT(UID, WriteUID) },
		{ VariantTypeId<vector<Vector2>>::GetCustomType(), VECTOR_STRAT(2, "X", "Y") },
		{ VariantTypeId<vector<Vector3>>::GetCustomType(), VECTOR_STRAT(3, "X", "Y", "Z") },
		{ VariantTypeId<vector<Vector4>>::GetCustomType(), VECTOR_STRAT(4, "X", "Y", "Z", "W") },
		{ VariantTypeId<vector<Matrix2>>::GetCustomType(), MATRIX_STRAT(2)},
		{ VariantTypeId<vector<Matrix3>>::GetCustomType(), MATRIX_STRAT(3)},
		{ VariantTypeId<vector<Matrix4>>::GetCustomType(), MATRIX_STRAT(4)},
		{ VariantTypeId<vector<Quaternion>>::GetCustomType(), ARRAY_STRAT(Quaternion, WriteQuaternion) },
		{ VariantTypeId<vector<Plane>>::GetCustomType(), ARRAY_STRAT(Plane, WritePlane) },
		{ VariantTypeId<vector<Ray2>>::GetCustomType(), RAY_STRAT(2) },
		{ VariantTypeId<vector<Ray3>>::GetCustomType(), RAY_STRAT(3) },
		{ VariantTypeId<vector<Sphere>>::GetCustomType(), ARRAY_STRAT(Sphere, WriteSphere) },
		{ VariantTypeId<vector<Hull>>::GetCustomType(), ARRAY_STRAT(Hull, WriteHull) },
		{ VariantTypeId<vector<Box>>::GetCustomType(), ARRAY_STRAT(Box, WriteBox) },
		{ VariantTypeId<vector<Transform>>::GetCustomType(), ARRAY_STRAT(Transform, WriteTransform) },
		{ VariantTypeId<vector<Object>>::GetCustomType(), ARRAY_STRAT(Object, WriteObject) },
		{ VariantTypeId<queue<int8>>::GetCustomType(), ARRAY_STRAT(int8, WriteString) },
		{ VariantTypeId<queue<int16>>::GetCustomType(), ARRAY_STRAT(int16, WriteNumeric) },
		{ VariantTypeId<queue<int32>>::GetCustomType(), ARRAY_STRAT(int32, WriteNumeric) },
		{ VariantTypeId<queue<int64>>::GetCustomType(), ARRAY_STRAT(int64, WriteNumeric) },
		{ VariantTypeId<queue<uint8>>::GetCustomType(), ARRAY_STRAT(uint8, WriteString) },
		{ VariantTypeId<queue<uint16>>::GetCustomType(), ARRAY_STRAT(uint16, WriteNumeric) },
		{ VariantTypeId<queue<uint32>>::GetCustomType(), ARRAY_STRAT(uint32, WriteNumeric) },
		{ VariantTypeId<queue<uint64>>::GetCustomType(), ARRAY_STRAT(uint64, WriteNumeric) },
		{ VariantTypeId<queue<f32>>::GetCustomType(), ARRAY_STRAT(f32, WriteNumeric) },
		{ VariantTypeId<queue<f64>>::GetCustomType(), ARRAY_STRAT(f64, WriteNumeric) },
		{ VariantTypeId<queue<gate>>::GetCustomType(), ARRAY_STRAT(gate, WriteBoolean) },
		{ VariantTypeId<queue<string>>::GetCustomType(), ARRAY_STRAT(string, WriteString) },
		{ VariantTypeId<queue<UID>>::GetCustomType(), ARRAY_STRAT(UID, WriteUID) },
		{ VariantTypeId<queue<Vector2>>::GetCustomType(), VECTOR_STRAT(2, "X", "Y") },
		{ VariantTypeId<queue<Vector3>>::GetCustomType(), VECTOR_STRAT(3, "X", "Y", "Z") },
		{ VariantTypeId<queue<Vector4>>::GetCustomType(), VECTOR_STRAT(4, "X", "Y", "Z", "W") },
		{ VariantTypeId<queue<Matrix2>>::GetCustomType(), MATRIX_STRAT(2) },
		{ VariantTypeId<queue<Matrix3>>::GetCustomType(), MATRIX_STRAT(3) },
		{ VariantTypeId<queue<Matrix4>>::GetCustomType(), MATRIX_STRAT(4) },
		{ VariantTypeId<queue<Quaternion>>::GetCustomType(), ARRAY_STRAT(Quaternion, WriteQuaternion) },
		{ VariantTypeId<queue<Plane>>::GetCustomType(), ARRAY_STRAT(Plane, WritePlane) },
		{ VariantTypeId<queue<Ray2>>::GetCustomType(), RAY_STRAT(2) },
		{ VariantTypeId<queue<Ray3>>::GetCustomType(), RAY_STRAT(3) },
		{ VariantTypeId<queue<Sphere>>::GetCustomType(), ARRAY_STRAT(Sphere, WriteSphere) },
		{ VariantTypeId<queue<Hull>>::GetCustomType(), ARRAY_STRAT(Hull, WriteHull) },
		{ VariantTypeId<queue<Box>>::GetCustomType(), ARRAY_STRAT(Box, WriteBox) },
		{ VariantTypeId<queue<Transform>>::GetCustomType(), ARRAY_STRAT(Transform, WriteTransform) },
		{ VariantTypeId<queue<Object>>::GetCustomType(), ARRAY_STRAT(Object, WriteObject) }
	};

	content.append(1, ArrayStartToken);
	strategy.at(variant.GetCustomType())(variant);
	content.append(1, ArrayEndToken);
}

void JSONReflector::WriteMapType(const Variant& variant)
{
	throw std::exception("not implemented");
}

void JSONReflector::WriteObject(const Variant& variant)
{
	JSONReflector* objectReflector = new JSONReflector();
	auto obj = ObjectFactory::Get()->CreateNew(variant.GetCustomType());
	std::stringstream stream;
	stream << variant.Value();
	obj->Deserialize(stream, 0);
	obj->Reflect(objectReflector);
	content.append(objectReflector->ToString());
	ObjectFactory::Get()->Unregister(obj.get());
	delete objectReflector;
}

void JSONReflector::WriteHull(const Variant& variant)
{
	Hull hull;
	variant.Get(hull);
	content.append(1, OpenToken)
		.append(1, QuoteToken)
		.append("Points")
		.append(1, QuoteToken)
		.append(1, PropertyToken)
		.append(1, ArrayStartToken);
	for (auto point : hull.Points)
	{
		content.append(GetVectorContentString({ "X", "Y", "Z" },
		{ point[0], point[1], point[2] }))
		.append(1, SeperatorToken);
	}
	if (hull.Points.size() > 0)
	{
		content.replace(content.find_last_of(SeperatorToken), 1, "");
	}
	content.append(1, ArrayEndToken);
	content.append(1, CloseToken);
}

void JSONReflector::WriteSphere(const Variant& variant)
{
	Sphere sphere;
	variant.Get(sphere);
	content.append(1, OpenToken)
		.append("\"Center\"")
		.append(1, PropertyToken)
		.append(GetVectorContentString({ "X", "Y", "Z" },
		{ sphere.Center[0], sphere.Center[1], sphere.Center[2] }))
		.append(1, SeperatorToken)
		.append("\"Radius\"")
		.append(1, PropertyToken)
		.append(std::to_string(sphere.Radius))
		.append(1, CloseToken);
}

void JSONReflector::WriteBox(const Variant& variant)
{
	Box box;
	variant.Get(box);
	content.append(1, OpenToken)
		.append("\"Center\"")
		.append(1, PropertyToken)
		.append(GetVectorContentString({ "X", "Y", "Z" },
		{ box.Center[0], box.Center[1], box.Center[2] }))
		.append(1, SeperatorToken)
		.append("\"Halfsize\"")
		.append(1, PropertyToken)
		.append(GetVectorContentString({ "X", "Y", "Z" },
		{ box.HalfSize[0], box.HalfSize[1], box.HalfSize[2] }))
		.append(1, CloseToken);
}

void JSONReflector::WritePlane(const Variant& variant)
{
	Plane plane;
	variant.Get(plane);
	content.append(1, OpenToken)
		.append("\"Normal\"")
		.append(1, PropertyToken)
		.append(GetVectorContentString({ "X", "Y", "Z" },
		{ plane.Normal[0], plane.Normal[1], plane.Normal[2] }))
		.append(1, SeperatorToken)
		.append("\"Offset\"")
		.append(1, PropertyToken)
		.append(std::to_string(plane.Offset))
		.append(1, CloseToken);
}

void JSONReflector::WriteTransform(const Variant& variant)
{
	Transform transform = Transform();
	variant.Get(transform);
	content.append(1, OpenToken)
		.append("\"Position\"")
		.append(1, PropertyToken)
		.append(GetVectorContentString({ "X", "Y", "Z" },
		{ transform.PositionVector()[0], transform.PositionVector()[1], transform.PositionVector()[2] }))
		.append(1, SeperatorToken)
		.append("\"Rotation\"")
		.append(1, PropertyToken)
		.append(GetVectorContentString({ "X", "Y", "Z" },
		{ transform.RotationVector()[0], transform.RotationVector()[1], transform.RotationVector()[2] }))
		.append(1, SeperatorToken)
		.append("\"Scale\"")
		.append(1, PropertyToken)
		.append(GetVectorContentString({ "X", "Y", "Z" },
		{ transform.ScaleVector()[0], transform.ScaleVector()[1], transform.ScaleVector()[2] }))
		.append(1, CloseToken);
}

void JSONReflector::WriteUID(const Variant& variant)
{
	UID id;
	variant.Get(id);
	content.append(1, QuoteToken)
		.append(id.ToString())
		.append(1, QuoteToken);
}

void JSONReflector::WriteQuaternion(const Variant& variant)
{
	Quaternion quat = Quaternion();
	variant.Get(quat);
	content.append(GetVectorContentString({ "X", "Y", "Z", "W" }, { quat.x, quat.y, quat.z, quat.w }));
}

void JSONReflector::WriteVariant(const Variant& variant)
{
	switch (variant.GetVariantType())
	{
	case VariantType::int16:
	case VariantType::int32:
	case VariantType::int64:
	case VariantType::uint16:
	case VariantType::uint32:
	case VariantType::uint64:
	case VariantType::f32:
	case VariantType::f64:
		WriteNumeric(variant);
		break;

	case VariantType::gate:
		WriteBoolean(variant);
		break;

	case VariantType::uint8:
	case VariantType::int8:
	case VariantType::string:
		WriteString(variant);
		break;

	case VariantType::vector:
	case VariantType::queue:
		WriteArrayType(variant);
		break;

	case VariantType::map:
		WriteMapType(variant);
		break;

	case VariantType::UID:
		WriteUID(variant);
		break;

	case VariantType::Vector2:
		WRITE_VEC(2, "X", "Y")
		break;

	case VariantType::Vector3:
		WRITE_VEC(3, "X", "Y", "Z")
		break;

	case VariantType::Vector4:
		WRITE_VEC(4, "X", "Y", "Z", "W")
		break;

	case VariantType::Matrix2:
		WRITE_MAT(2)
		break;

	case VariantType::Matrix3:
		WRITE_MAT(3)
		break;

	case VariantType::Matrix4:
		WRITE_MAT(4)
		break;

	case VariantType::Quaternion:
		WriteQuaternion(variant);
		break;

	case VariantType::Plane:
		WritePlane(variant);
		break;

	case VariantType::Ray2:
		WRITE_RAY(2, "X", "Y")
		break;

	case VariantType::Ray3:
		WRITE_RAY(3, "X", "Y", "Z")
		break;

	case VariantType::Sphere:
		WriteSphere(variant);
		break;
	case VariantType::Hull:
		WriteHull(variant);
		break;

	case VariantType::Box:
		WriteBox(variant);
		break;

	case VariantType::Transform:
		WriteTransform(variant);
		break;

	case VariantType::Object:
		WriteObject(variant);
		break;

	case VariantType::unknown:
	default:
		throw std::exception("unknown type");
		break;
	}
}

void JSONReflector::AddProperty(const PropertyVariant& variant)
{
	content.append(1, QuoteToken)
		.append(variant.GetPropertyName())
		.append(1, QuoteToken)
		.append(1, PropertyToken);
	WriteVariant(variant);
	content.append(1, SeperatorToken);
}

string JSONReflector::GetVectorContentString(const vector<string>& labels, const vector<f32>& data)
{
	string result(1, OpenToken);
	int32 i = 0;
	for (auto label : labels)
	{
		result.append(1, QuoteToken)
			.append(label)
			.append(1, QuoteToken)
			.append(1, PropertyToken)
			.append(std::to_string(data[i]))
			.append(1, SeperatorToken);
		++i;
	}
	result.replace(result.find_last_of(SeperatorToken), 1, "");
	return result.append(1, CloseToken);
}