#ifndef SDL_RENDER_SYSTEM_H
#define SDL_RENDER_SYSTEM_H

#include "IRenderSystem.h"

class SDLRenderSystem : public IRenderSystem {
public:
	virtual void Register(struct IRenderable* renderable) override;
	virtual void Unregister(struct IRenderable* renderable) override;

	virtual void Render() override;

	virtual std::string GetName() const override;

	virtual void Configure(class Config& config) override;
	virtual bool Initialize(struct ILogger* logger) override;

	virtual bool Run() override;
	virtual void Shutdown() override;

private:
protected:
};


#endif