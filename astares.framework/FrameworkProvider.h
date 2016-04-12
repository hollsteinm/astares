#ifndef FRAMEWORKPROVIDER_H
#define FRAMEWORKPROVIDER_H

#include "astares.framework.h"
#include <core/System.h>

DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IAudioSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IGraphicsSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IInputSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct INetworkSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IPhysicsSystem)
DECL_API_STL_PTR(ASTARESFRAMEWORK_API, struct IObjectFactory)

class ASTARESFRAMEWORK_API FrameworkProvider : public System {
public:
	std::shared_ptr<struct IAudioSystem> GetAudio() const;
	std::shared_ptr<struct IGraphicsSystem> GetGraphics() const;
	std::shared_ptr<struct IInputSystem> GetInput() const;
	std::shared_ptr<struct INetworkSystem> GetNetwork() const;
	std::shared_ptr<struct IPhysicsSystem> GetPhysics() const;
	std::shared_ptr<struct IObjectFactory> GetObjectFactory() const;
	std::shared_ptr<struct IReflector> GetReflector() const;
	std::shared_ptr<struct IReflectionInfo> GetReflectionInfo(std::shared_ptr<class Object> obj) const;

	FrameworkProvider();
	~FrameworkProvider();

private:
	std::shared_ptr<struct IAudioSystem> AudioSystem;
	std::shared_ptr<struct IGraphicsSystem> GraphicsSystem;
	std::shared_ptr<struct IInputSystem> InputSystem;
	std::shared_ptr<struct INetworkSystem> NetworkSystem;
	std::shared_ptr<struct IPhysicsSystem> PhysicsSystem;
	std::shared_ptr<struct IObjectFactory> ObjectFactory;
};



#endif