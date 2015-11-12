#include "CommonLogger.h"

#include <stdlib.h>
#include <cstdio>
#include <stdarg.h>

static const char* I = "[INFO]\t\t %s \r\n";
static const char* W = "[WARN]\t\t %s \r\n";
static const char* E = "[ERROR]\t\t %s \r\n";
static const char* C = "[CRITICAL]\t %s \r\n";

void CommonLogger::Info(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char buff[1024];
	vsprintf_s(buff, fmt, args);
	va_end(args);

	fprintf_s(stdout, I, buff);
}

void CommonLogger::Warn(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char buff[1024];
	vsprintf_s(buff, fmt, args);
	va_end(args);

	fprintf_s(stdout, W, buff);
}

void CommonLogger::Error(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char buff[1024];
	vsprintf_s(buff, fmt, args);
	va_end(args);

	fprintf_s(stderr, E, buff);
}

void CommonLogger::Critical(const char* fmt, ...)  {
	va_list args;
	va_start(args, fmt);
	char buff[1024];
	vsprintf_s(buff, fmt, args);
	va_end(args);

	fprintf_s(stderr, C, buff);
}