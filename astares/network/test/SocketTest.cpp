#include "SocketTest.h"

#include "../ISocket.h"
#include "../UDPSocket.h"
#include "../UDPListener.h"
#include "../Packet.h"
#include "../NetworkMessage.h"
#include "../../gameplay/GameObject.h"
#include "../../messaging/AHandler.h"
#include "../../gameplay/TransformComponent.h"
#include "../UDPSender.h"

#include <iostream>
#include <thread>
#include <sstream>

class TestNetHandler : public AHandler < NetworkMessage > {
public:
	TestNetHandler(MessageHub& hub) :
		AHandler(hub)
	{}

protected:

	virtual void InternalHandle(NetworkMessage* Message) override {
		std::cout << *Message->GetSender().Get() << std::endl;
	}
};

DECL_CLASS(TestGameObject) : public GameObject {
	DECL_BODY(TestGameObject)
};

TestGameObject::TestGameObject() {
	CTOR_REGISTER(TestGameObject)
}

TestGameObject::~TestGameObject() {

}

REFLECTION_BEGIN(TestGameObject)
	PARENT(GameObject)
REFLECTION_END(TestGameObject)

void test::network::Console() {
#ifdef _WIN32
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

	ISocket* ListenSocket = new UDPSocket();
	ISocket* RemoteSocket = new UDPSocket();

	int err = 0;
	if (ListenSocket->Open(Address("", "12345", Family::IPv6))) {
		if (ListenSocket->Bind(Address("", "12345", Family::IPv6))) {
			if (RemoteSocket->Open(Address("localhost", "12345", Family::IPv6))) {
				std::string write = "Test Message";

				std::thread t([](ISocket* listener) {
					int e = 0;

					std::string read;

					int r = listener->Read(read, 128);
					if (r != 0) {
						std::cout << read << std::endl;
					}
					else
						e = WSAGetLastError();
					return;
				}, ListenSocket);

				if (RemoteSocket->Send(write) != 0) {
					t.join();
				}
			}
		}
	}

	delete ListenSocket;
	delete RemoteSocket;

	ListenSocket = nullptr;
	RemoteSocket = nullptr;

	UDPListener listener("12345");
	UDPSender sender("localhost", "12345");
	TestNetHandler handler(listener);

	std::thread t([](UDPListener* l) {
		l->Digest();
		return;
	}, &listener);

	TestGameObject senderObject;
	NetworkMessage msg(&senderObject);

	sender.Send(&msg);
	t.join();


#ifdef _WIN32
	WSACleanup();
#endif

}