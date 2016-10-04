#ifndef COMMONLOGGER_H
#define COMMONLOGGER_H

#include "ILogger.h"
namespace astares
{
	class  ASTARESCORE_API CommonLogger : public ILogger {
	public:
		virtual ~CommonLogger() {}

		virtual void Info(cstring fmt, ...) override;
		virtual void Warn(cstring fmt, ...) override;
		virtual void Error(cstring fmt, ...) override;
		virtual void Critical(cstring fmt, ...) override;
	};
}
#endif