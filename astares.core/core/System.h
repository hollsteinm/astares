#ifndef SYSTEM_H
#define SYSTEM_H

#include "Types.h"

struct ILogger;
struct ISubsystem;

DECL_CORE_STL_PTR(ISubsystem)
DECL_CORE_STL(std::shared_ptr<ISubsystem>)
DECL_CORE_STL(std::weak_ptr<ISubsystem>)

class ASTARESCORE_API System {
public:
	System(ILogger* logger, const vector<std::weak_ptr<ISubsystem>>& subSystems);
	virtual ~System();

	virtual void Configure(class Config& config);
	virtual bool Initialize();
	virtual bool Run();
	virtual void Shutdown();
private:
protected:
	vector<std::shared_ptr<ISubsystem>> Subsystems;
	ILogger* logger;
};


#endif