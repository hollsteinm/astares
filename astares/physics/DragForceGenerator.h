#ifndef DRAG_FORCE_GENERATOR_H
#define DRAG_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"

class Particle;

class DragForceGenerator : public BaseForceGenerator {
public:
	DragForceGenerator(float velocityDrag, float velocityDragSquared);
private:
protected:
	virtual void Tick(float DeltaTime, Particle* particle)  override;

	float Drag;
	float DragSquared;
};


#endif