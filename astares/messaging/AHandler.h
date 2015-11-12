#ifndef A_HANDLER_H
#define A_HANDLER_H

#include "MessageHub.h"

template<typename T>
class AHandler : public IMessageHandler {
public:
	virtual ~AHandler() {};

	void Handle(Message* evt) override {
		InternalHandle((T*)evt);
	}

protected:
	AHandler(MessageHub& hub) {
		hub.Subscribe<T>(this);
	}

	virtual void InternalHandle(T* Message) = 0;
};

#endif