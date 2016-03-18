#ifndef DRAG_FORCE_GENERATOR_H
#define DRAG_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"

class Particle;

class DragForceGenerator : public BaseForceGenerator {
public:
	DragForceGenerator(f32 velocityDrag, f32 velocityDragSquared);
private:
protected:
	virtual void Tick(f32 DeltaTime, Particle* particle)  override;

	f32 Drag;
	f32 DragSquared;
};


#endif