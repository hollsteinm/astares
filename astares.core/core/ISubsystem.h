#ifndef ISUBSYSTEM_H
#define ISUBSYSTEM_H

#include "../core/Types.h"

struct ASTARESCORE_API ISubsystem {
	ISubsystem(){}
	virtual ~ISubsystem(){}

	ISubsystem(const ISubsystem& rhs) = delete;
	void operator=(const ISubsystem& rhs) = delete;

	virtual std::string GetName() const = 0;

	virtual void Configure(class Config& config) = 0;
	virtual bool Initialize(std::shared_ptr<struct ILogger> logger) = 0;
	virtual bool Run() = 0;
	virtual void Shutdown() = 0;
};


#endif