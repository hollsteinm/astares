#ifndef UDPSENDER_H
#define UDPSENDER_H

#include "../astares.framework.h"
#include <core/Types.h>

namespace astares
{
	class ASTARESFRAMEWORK_API UDPSender 
	{
	public:
		UDPSender(cstring host, cstring port);
		~UDPSender();

		void Send(cstring data, uint64 size);

	private:
		std::unique_ptr<struct ISocket> Sock;
	};


}
#endif