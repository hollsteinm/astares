#include "Session.h"
#include "ISocket.h"

using namespace astares;

Session::Session(std::shared_ptr<ISocket> sessionSocket, const SessionRole& role) 
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

std::shared_ptr<ISocket> Session::GetRemoteEndpoint() const
{
	return Endpoint;
}