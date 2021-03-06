#ifndef ISUBSYSTEM_H
#define ISUBSYSTEM_H

#include "String.h"

struct ISubsystem {
	ISubsystem(){}
	virtual ~ISubsystem(){}

	ISubsystem(const ISubsystem& rhs) = delete;
	void operator=(const ISubsystem& rhs) = delete;

	virtual String GetName() const = 0;

	virtual void Configure(class Config& config) = 0;
	virtual bool Initialize(struct ILogger* logger) = 0;
	virtual bool Run() = 0;
	virtual void Shutdown() = 0;
};



#endif