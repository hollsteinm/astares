#ifndef SYSTEM_H
#define SYSTEM_H

#include "../core/Array.h"

struct ILogger;


class System {
public:
	System(ILogger* logger, const Array<struct ISubsystem*>& subSystems);
	virtual ~System();

	virtual void Configure(const class Config& config);
	virtual bool Initialize();
	virtual bool Run();
	virtual void Shutdown();
private:
protected:
	Array<struct ISubsystem*> Subsystems;
	ILogger* logger;
};


#endif