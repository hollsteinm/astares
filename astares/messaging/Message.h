#ifndef MESSAGEEVENT_H
#define MESSAGEEVENT_H

#include "../reflection/Reflection.h"

DECL_CLASS_BASE(Message) {
	DECL_BODY(Message)
public:
	Message(Object* Sender);

	const ObjectPtr<Object>& GetSender() const;

private:
	ObjectPtr<Object> Sender;
};

#endif