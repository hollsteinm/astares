#include "Session.h"
#include "ISocket.h"

Session::Session(std::shared_ptr<struct ISocket> sessionSocket, const SessionRole& role) 
	: Endpoint(sessionSocket),
	SessionId(UID::Make()),
	RemoteRole(role)
{
}

Session::~Session()
{
	Endpoint->Close();
}

const UID Session::GetSessionId() const 
{
	return SessionId;
}

const SessionRole Session::GetRole() const
{
	return RemoteRole;
}

std::shared_ptr<struct ISocket> Session::GetRemoteEndpoint() const
{
	return Endpoint;
}