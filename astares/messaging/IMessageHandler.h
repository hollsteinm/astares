#ifndef IMESSAGEHANDLER_H
#define IMESSAGEHANDLER_H

class IMessageHandler {
public:
	virtual ~IMessageHandler() {};

	virtual void Handle(Message* Event) = 0;

protected:
	IMessageHandler() {};
};

#endif