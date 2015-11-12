#include "NetworkMessage.h"

NetworkMessage::NetworkMessage(Object* sender) :
	Message(sender)
{

}

NetworkMessage::NetworkMessage()
{
	CTOR_REGISTER(NetworkMessage)
}

NetworkMessage::~NetworkMessage()
{

}


REFLECTION_BEGIN(NetworkMessage)
	PARENT(Message)
REFLECTION_END(NetworkMessage)