#include "MessageHub.h"
#include "../object/Object.h"

MessageHub::MessageHub()
{

}

MessageHub::~MessageHub()
{
	UnsubscribeAll();
	EmptyQueues();
}

void MessageHub::Publish(const Message& message)
{
	EventQueue.push(message);
}

void MessageHub::Subscribe(const std::function<void(const Message&)>& handler)
{
	Handlers.push_back(handler);
}

void MessageHub::Consume()
{
	while (!EventQueue.empty())
	{
		auto msg = EventQueue.front();
		Process(msg);
		EventQueue.pop();
	}
}

void MessageHub::EmptyQueues()
{
	while (!EventQueue.empty())
	{
		EventQueue.pop();
	}
}

void MessageHub::UnsubscribeAll()
{
	Handlers.clear();
}

void MessageHub::Process(const Message& message)
{
	for (auto handler : Handlers)
	{
		handler(message);
	}
}