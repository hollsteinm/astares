#include "KeyEventMessage.h"

REFLECTION_BEGIN(KeyEventMessage)
	PARENT(Message)
	FIELD(String, eventKey)
	FIELD(int, st)
REFLECTION_END(KeyEventMessage)

KeyEventMessage::KeyEventMessage() : 
	eventKey(""),
	state(KeyState::Released),
	st(0)
{
	CTOR_REGISTER(KeyEventMessage)
}

KeyEventMessage::KeyEventMessage(const String& keyEvent, const KeyState& st) :
	KeyEventMessage()
{
	eventKey = keyEvent;
	state = st;
	this->st = (int)state;
}

KeyEventMessage::~KeyEventMessage() {

}

const String KeyEventMessage::GetEvent() const {
	return eventKey;
}

const KeyState KeyEventMessage::GetState() const {
	return state;
}

void KeyEventMessage::mk() {
	state = (KeyState)st;
}

void KeyEventMessage::PostDeserialize(std::istream& in) {
	mk();
}