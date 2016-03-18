#ifndef MESSAGEEVENT_H
#define MESSAGEEVENT_H

#include "Topic.h"
#include "../reflection/Variant.h"
#include <sstream>

class Message {
public:
	Message(const string& context);
	Message(const string& context, const Topic& topic);
	Message(const string& context, const Topic& topic, const std::stringstream& data);
	Message(const Message& other);

	template<typename T>
	Message(const T& obj)
		: context(VariantTypeId<T>::GetTypeName())
	{
		data << obj;
	}

	~Message();

	const std::stringstream& GetData() const;
	string GetContext() const;
	const Topic& GetTopic() const;

	friend std::ostream& operator << (std::ostream& out, const Message& message);
	friend std::istream& operator >> (std::istream& in, Message& message);

private:
	std::stringstream data;
	string context;
	Topic topic;
};

#endif