#include "Message.h"

Message::Message() {
	CTOR_REGISTER(Message)
}

Message::~Message()
{
}

Message::Message(Object* Sender)
{
	this->Sender.Set(Sender);
}

const ObjectPtr<Object>& Message::GetSender() const {
	return Sender;
}

REFLECTION_BEGIN(Message)
	PARENT(Object)
	PROPERTY(ObjectPtr<Object>, Sender)
REFLECTION_END(Message)