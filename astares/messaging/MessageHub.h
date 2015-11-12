#ifndef MESSAGE_HUB_H
#define MESSAGE_HUB_H

#include <queue>
#include <map>
#include <list>
#include "Message.h"
#include "IMessageHandler.h"


enum class PublishType {
	Immediate,
	Deferred
};

class MessageHub
{
public:
	MessageHub() {};
	virtual ~MessageHub();

	template<typename T>
	void Publish(Message* message, PublishType publishType = PublishType::Immediate) {
		switch (publishType)
		{
		case PublishType::Deferred:
			EventQueue[TYPEOF(T)].push(Event);
			break;
		case PublishType::Immediate:
		default:
			Process(message);
			break;
		}
	}

	void Publish(Message* message, PublishType publishType = PublishType::Immediate);

	template<typename T>
	void Subscribe(IMessageHandler* Handler) {
		Handlers[TYPEOF(T)].push_back(Handler);
	}

	template<typename T>
	void Unsubscribe(IMessageHandler* Handler) {
		Handlers[TYPEOF(T)].remove(Handler);
	}

	void Consume();
	void Empty();
	void UnsubscribeAll();

private:
	std::map<unsigned long, std::queue<Message*>> EventQueue;
	std::map<unsigned long, std::list<IMessageHandler*>> Handlers;

	void Process(Message* message);
};

#endif