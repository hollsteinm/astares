#include "catch.hpp"
#include <network\UDPSender.h>
#include <network\UDPListener.h>
#include <network\Packet.h>

#ifdef _WIN32
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")
#endif

TEST_CASE("UDP", "[sockets]") {
#ifdef _WIN32
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

	UDPListener listener("2048");
	UDPSender sender("localhost", "2048");

	SECTION("Initialization") {
		REQUIRE_FALSE(listener.Ready());
	}

	SECTION("Communications") {
		sender.Send("Test");
		REQUIRE(listener.Ready());
		auto result = listener.GetPacket();
		REQUIRE(result.Size.l == 4);
		REQUIRE(result.data == "Test");
	}
#ifdef _WIN32
	WSACleanup();
#endif
	
}

TEST_CASE("TCP", "[sockets]") {

}