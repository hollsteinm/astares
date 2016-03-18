#include "Message.h"
#include "../serialization/StringHelper.h"

Message::Message(const string& context)
	: context(context)
{

}

Message::Message(const string& context, const Topic& topic)
	: context(context),
	topic(topic)
{
}

Message::Message(const string& context, const Topic& topic, const std::stringstream& data)
	: context(context),
	topic(topic),
	data(data.str())
{

}

Message::Message(const Message& other)
	: context(other.context),
	topic(other.topic),
	data(other.data.str())
{

}

Message::~Message()
{

}

const std::stringstream& Message::GetData() const
{
	return data;
}

string Message::GetContext() const
{
	return context;
}

const Topic& Message::GetTopic() const {
	return topic;
}

std::ostream& operator << (std::ostream& out, const Message& message)
{
	return out << StringHelper::Encode(message.context)
		<< StringHelper::Encode(message.data.str())
		<< message.topic;
}

std::istream& operator >> (std::istream& in, Message& message)
{
	string indata;
	in >> message.context
		>> indata
		>> message.topic;
	StringHelper::MakeDecoded(message.context);
	message.data = std::stringstream(StringHelper::Decode(indata));
	return in;
}