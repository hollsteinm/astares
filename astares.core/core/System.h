#ifndef SYSTEM_H
#define SYSTEM_H

#include "Types.h"

namespace astares
{
	struct ASTARESCORE_API ISystem {
		ISystem();
		virtual ~ISystem();

		virtual void Configure(struct IConfig* config) = 0;
		virtual bool Initialize() = 0;
		virtual bool Run() = 0;
		virtual void Shutdown() = 0;
		static inline ISystem* MakeSystem(struct ILogger* logger, const std::vector<struct ISubsystem*>& subSystems);
	};

}
#endif