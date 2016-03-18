#ifndef IRENDERER_H
#define IRENDERER_H

#include "../core/ISubsystem.h"

struct IRenderSystem : public ISubsystem {
	virtual ~IRenderSystem(){}

	virtual void Register(struct IRenderable* renderable) = 0;
	virtual void Unregister(struct IRenderable* renderable) = 0;

	virtual void Render() = 0;
};

#endif