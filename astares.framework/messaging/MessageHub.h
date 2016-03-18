#ifndef MESSAGE_HUB_H
#define MESSAGE_HUB_H

#include <queue>
#include <list>
#include "Message.h"
#include <functional>

class MessageHub
{
public:
	MessageHub();
	virtual ~MessageHub();

	virtual void Publish(const Message& message);
	virtual void Subscribe(const std::function<void(const Message&)>& handler);

	void Consume();

	void EmptyQueues();
	void UnsubscribeAll();

private:

	std::queue<Message> EventQueue;
	std::list<std::function<void(const Message&)>> Handlers;

	void Process(const Message& message);
};

#endif