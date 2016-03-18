#include "KeyEvent.h"

KeyEvent::KeyEvent() : 
	eventKey(""),
	state(KeyState::Released)
{
	
}

KeyEvent::KeyEvent(const string& keyEvent, const KeyState& st) :
	KeyEvent()
{
	eventKey = keyEvent;
	state = st;
}

KeyEvent::~KeyEvent() {

}

const string KeyEvent::GetEvent() const {
	return eventKey;
}

const KeyState KeyEvent::GetState() const {
	return state;
}

START_SERIAL(KeyEvent)
	PARENT_SERIAL(Object)
	WRITE(StringHelper::Encode(eventKey))
	WRITE(state)
END_SERIAL

START_DESERIAL(KeyEvent)
	PARENT_DESERIAL(Object)
	READ(eventKey)
	READ(state)
END_DESERIAL

void KeyEvent::PostDeserialize(std::istream& in, int32 version)
{
	StringHelper::MakeDecoded(eventKey);
}