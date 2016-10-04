#ifndef ILOGGER_H
#define ILOGGER_H

#include "../core/Types.h"

namespace astares
{
	struct ASTARESCORE_API ILogger {
		virtual ~ILogger(){};
		virtual void Info(cstring fmt, ...) = 0;
		virtual void Warn(cstring fmt, ...) = 0;
		virtual void Error(cstring fmt, ...) = 0;
		virtual void Critical(cstring fmt, ...) = 0;
	};
}
#endif