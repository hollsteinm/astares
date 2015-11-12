#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>

struct ILogger;


class System {
public:
	System(ILogger* logger, const std::vector<struct ISubsystem*>& subSystems);
	virtual ~System();

	virtual void Configure(const class Config& config);
	virtual bool Initialize();
	virtual bool Run();
	virtual void Shutdown();
private:
protected:
	std::vector<struct ISubsystem*> Subsystems;
	ILogger* logger;
};


#endif