#ifndef FRAMEWORKPROVIDER_H
#define FRAMEWORKPROVIDER_H

#include "astares.framework.h"
#include <core/System.h>

DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IAudioSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IGraphicsSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IInputSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct INetworkSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IPhysicsSystem)

class ASTARESFRAMEWORK_API FrameworkProvider : public System {
public:
	std::shared_ptr<class IAudioSystem> GetAudio() const;
	std::shared_ptr<class IGraphicsSystem> GetGraphics() const;
	std::shared_ptr<class IInputSystem> GetInput() const;
	std::shared_ptr<class INetworkSystem> GetNetwork() const;
	std::shared_ptr<class IPhysicsSystem> GetPhysics() const;

	FrameworkProvider();
	~FrameworkProvider();
};



#endif