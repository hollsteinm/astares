#include "MessageHub.h"


MessageHub::~MessageHub() {
	//for (auto kvp : Handlers) {
	//	for (auto handler : kvp.second) {
	//		delete handler;
	//	}
	//	kvp.second.clear();
	//}
	Handlers.clear();

	for (auto kvp : EventQueue) {
		while (!kvp.second.empty()) {
			auto p = kvp.second.front();
			kvp.second.pop();
			delete p;
		}
	}
	EventQueue.clear();
}

void MessageHub::Empty() {
	EventQueue.clear();
}

void MessageHub::UnsubscribeAll() {
	Handlers.clear();
}

void MessageHub::Consume() {
	for (auto kvp : EventQueue) {
		while (!kvp.second.empty()) {
			for (auto handler : Handlers[kvp.first]) {
				auto evt = kvp.second.front();
				if (evt != nullptr)
				{
					handler->Handle(kvp.second.front());
				}
				kvp.second.pop();
			}
		}
	}
}

void MessageHub::Process(Message* message) {
	for (auto handler : Handlers[message->GetTypeId()]) {
		handler->Handle(message);
	}
	delete message;
}

void MessageHub::Publish(Message* message, PublishType publishType) {
	switch (publishType)
	{
	case PublishType::Deferred:
		EventQueue[message->GetTypeId()].push(message);
		break;
	case PublishType::Immediate:
	default:
		Process(message);
		break;
	}
}