#ifndef COMMONLOGGER_H
#define COMMONLOGGER_H

#include "ILogger.h"

class CommonLogger : public ILogger {
public:
	virtual ~CommonLogger() {}

	virtual void Info(const char* fmt, ...) override;
	virtual void Warn(const char* fmt, ...) override;
	virtual void Error(const char* fmt, ...) override;
	virtual void Critical(const char* fmt, ...) override;
};
#endif