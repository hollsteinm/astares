#ifndef ILOGGER_H
#define ILOGGER_H

struct ILogger {
	virtual ~ILogger(){};
	virtual void Info(const char* fmt, ...) = 0;
	virtual void Warn(const char* fmt, ...) = 0;
	virtual void Error(const char* fmt, ...) = 0;
	virtual void Critical(const char* fmt, ...) = 0;
};
#endif