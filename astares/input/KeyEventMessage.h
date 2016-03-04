#ifndef KEY_EVENT_MESSAGE_H
#define KEY_EVENT_MESSAGE_H

#include "../reflection/Reflection.h"
#include "../messaging/Message.h"
#include "KeyState.h"

DECL_CLASS(KeyEventMessage) : public Message {
	DECL_BODY(KeyEventMessage)

public:
	KeyEventMessage(const String& keyEvent, const KeyState& st);

	const String GetEvent() const;
	const KeyState GetState() const;

protected:
	//for now
	virtual void PostDeserialize(std::istream& in) override;

private:
	String eventKey;
	KeyState state;
	//for now
	int st;
	void mk();
};

#endif