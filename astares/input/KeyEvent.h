#ifndef KEY_EVENT_MESSAGE_H
#define KEY_EVENT_MESSAGE_H

#include "../object/Object.h"
#include "KeyState.h"

class KeyEvent : public Object {
public:
	KeyEvent();
	~KeyEvent();

	KeyEvent(const string& keyEvent, const KeyState& st);

	const string GetEvent() const;
	const KeyState GetState() const;

	SERIALIZEABLE(KeyEvent)

protected:
	virtual void PostDeserialize(std::istream& in, int32 version) override;

private:
	string eventKey;
	KeyState state;
};

#endif