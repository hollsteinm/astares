#include "Topic.h"
#include "../serialization/ArrayHelper.h"
#include "../serialization/StringHelper.h"

Topic::Topic()
{

}

Topic::Topic(const string& name) :
	name(name)
{

}

Topic::Topic(const string& name, const std::vector<Topic>& children) :
	name(name),
	children(children)
{

}

Topic::Topic(const Topic& rhs) :
	name(rhs.name),
	children(rhs.children)
{

}

void Topic::operator = (const Topic& rhs)
{
	name = rhs.name;
	children = rhs.children;
}

Topic::~Topic()
{
	children.clear();
}

string Topic::GetName() const
{
	return name;
}

const std::vector<Topic>& Topic::GetChildren() const
{
	return children;
}

std::ostream& operator << (std::ostream& out, const Topic& message)
{
	out << StringHelper::Encode(message.name);
	ArrayHelper::Serialize(message.children, out);
	return out;
}

std::istream& operator >> (std::istream& in, Topic& message)
{
	in >> message.name;
	StringHelper::MakeDecoded(message.name);
	ArrayHelper::Deserialize(message.children, in);
	return in;
}
