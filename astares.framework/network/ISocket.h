#ifndef ISOCKET_H
#define ISOCKET_H

#include "../astares.framework.h"
#include <core\Types.h>

namespace astares
{
	struct ASTARESFRAMEWORK_API ISocket 
	{
		virtual ~ISocket() {}

		virtual bool Open(const class Address& address) = 0;
		virtual bool Bind(const class Address& address) = 0;

		virtual void Close() = 0;

		virtual int32 Send(cstring data, uint64 size) = 0;
		virtual int32 Read(char*& outData, int32 size) = 0;
		virtual bool Ready() = 0;
	};

}
#endif