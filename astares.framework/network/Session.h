#ifndef SESSION_H
#define SESSION_H

#include "../astares.framework.h"
#include <core\Types.h>
#include <core\UID.h>

namespace astares
{
	BETTER_ENUM(SessionRole, int8,
		Server = 0,
		Client,
		Both,
		Unknown = ~0)

	class ASTARESFRAMEWORK_API Session 
	{
	public:
		Session(std::shared_ptr<struct ISocket> sessionSocket, const SessionRole& role);
		~Session();

		Session(const Session& other) = delete;
		void operator=(const Session& other) = delete;

		const UID GetSessionId() const;
		const SessionRole GetRole() const;
		std::shared_ptr<struct ISocket> GetRemoteEndpoint() const;

	private:
		UID SessionId;
		SessionRole RemoteRole;
		std::shared_ptr<struct ISocket> Endpoint;
	};
}

#endif