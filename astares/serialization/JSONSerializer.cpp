#include "JSONSerializer.h"
#include "../object/Object.h"
#include "../reflection/Reflector.h"
#include <algorithm>
#include <iterator>
#include <regex> 
#include "../object/ObjectFactory.h"

static const string endline = "\r\n";

JSONSerializer::JSONSerializer(gate compact, gate includeObjectType) :
	bCompact(compact),
	bIncludeType(includeObjectType)
{

}

JSONSerializer::~JSONSerializer()
{

}


void JSONSerializer::BeginObject(std::ostream& output, int32 depth) const {
	Tab(output, depth);
	output << OpenToken;
	if (!bCompact) {
		output << endline;
	}
}

void JSONSerializer::WriteObject(const class Object* object, std::ostream& output, int32 depth) const {
	Reflector reflector;
	object->Reflect(&reflector);
	BeginObject(output, depth - 1);
	if (bIncludeType) {
		WritePair(TypeProperty, reflector.GetName(), output, depth);
	}
	for (auto prop : reflector.GetProperties()) {
		switch (prop.GetVariantType())
		{
			case VariantType::int8:
			case VariantType::int16:
			case VariantType::int32:
			case VariantType::int64:
			case VariantType::uint8:
			case VariantType::uint16:
			case VariantType::uint32:
			case VariantType::uint64:
			case VariantType::f32:
			case VariantType::f64:
			case VariantType::gate:
			case VariantType::string:
				WritePair(prop.GetPropertyName(), prop.Value(), output, depth);
				break;
			case VariantType::vector:
			case VariantType::queue:
			case VariantType::Vector2:
			case VariantType::Vector3:
			case VariantType::Vector4:
			case VariantType::Matrix2:
			case VariantType::Matrix3:
			case VariantType::Matrix4:
			case VariantType::Quaternion:
				output << prop.GetPropertyName() << PropertyToken;
				WriteArray(prop.Value(), output, depth);
				break;
			case VariantType::map:
				if (bIncludeType) {
					output << TypeProperty << PropertyToken << prop.GetName() << SeperatorToken;
				}
				WriteHash(prop.Value(), output, depth + 1);
				break;
			case VariantType::Object:
				{
					auto newObj = ObjectFactory::Get().GetDefault(prop.GetCustomType());
					newObj._Get()->Deserialize(std::stringstream(prop.Value()), 0);
					WriteObject(newObj._Get(), output, depth + 1);
					ObjectFactory::Get().Unregister(newObj._Get());
				}
				break;
			case VariantType::Plane:
			case VariantType::Ray2:
			case VariantType::Ray3:
			case VariantType::Sphere:
			case VariantType::Hull:
			case VariantType::Box:
			case VariantType::unknown:
			default:
				break;
		}
	}
	EndObject(output, depth - 1);
}

void JSONSerializer::WriteHash(const std::string& arr, std::ostream& output, int32 depth) const {
	std::vector<std::string> tokens;
	std::regex re(" ");

	//start/end points of tokens in str
	std::sregex_token_iterator
		begin(arr.begin(), arr.end(), re),
		end;

	std::copy(begin, end, std::back_inserter(tokens));

	Tab(output, depth);
	output << OpenToken;
	if (!bCompact) {
		output << endline;
	}

	string out;
	for (size_t i = 0; i < tokens.size() - 1; i += 2) {
		WritePair(tokens[i], tokens[i + 1], output, depth);
	}
	RemoveLastOf(out, SeperatorToken);
	output << CloseToken;
	if (!bCompact)
	{
		output << endline;
	}
}

void JSONSerializer::WriteArray(const std::string& arr, std::ostream& output, int32 depth) const {
	string work = StringHelper::Decode(arr);

	std::vector<std::string> tokens;
	std::regex re(" ");

	//start/end points of tokens in str
	std::sregex_token_iterator
		begin(work.begin(), work.end(), re),
		end;

	string out;
	std::copy(begin, end, std::back_inserter(tokens));
	for (auto str : tokens) {
		out.append(JSONSerializer::QuoteToken, 1)
			.append(str)
			.append(JSONSerializer::QuoteToken, 1)
			.append(JSONSerializer::SeperatorToken, 1);
	}

	RemoveLastOf(out, SeperatorToken);
	Tab(output, depth);
	output << ArrayStartToken << out << ArrayEndToken << SeperatorToken;
	if (!bCompact)
	{
		output << endline;
	}
}

void JSONSerializer::RemoveLastOf(string& value, const char val) const {
	value.replace(value.find_last_of(val), 1, " ");
}

void JSONSerializer::WritePair(const string& name, const string& value, std::ostream& output, int32 depth) const {
	Tab(output, depth);
	output << name << SeperatorToken << QuoteToken << value << QuoteToken << SeperatorToken;
	if (!bCompact)
	{
		output << endline;
	}
}

void JSONSerializer::EndObject(std::ostream& output, int32 depth) const {
	output << CloseToken;
	if (!bCompact) {
		output << endline;
	}
}

void JSONSerializer::Tab(std::ostream& output, int32 depth) const {
	if (!bCompact){
		for (int32 i = 0; i < depth; ++i) {
			output << '\t';
		}
	}
}


const int8 JSONSerializer::OpenToken = '{';
const int8 JSONSerializer::CloseToken = '}';
const int8 JSONSerializer::ArrayStartToken = '[';
const int8 JSONSerializer::ArrayEndToken = ']';
const int8 JSONSerializer::PropertyToken = ':';
const int8 JSONSerializer::SeperatorToken = ',';
const int8 JSONSerializer::QuoteToken = '\'';
const string JSONSerializer::TypeProperty = "$type";

void JSONSerializer::Serialize(const class Object* input, std::ostream& output) const {
	WriteObject(input, output, 1);
}

void JSONSerializer::Deserialize(class Object* output, std::istream& input) const {
	throw std::exception("not implemented yet!");
}