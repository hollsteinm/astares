#include "DragForceGenerator.h"
#include "Particle.h"

DragForceGenerator::DragForceGenerator(f32 velocityDrag, f32 velocityDragSquared) :
	Drag(velocityDrag),
	DragSquared(velocityDragSquared)
{

}

void DragForceGenerator::Tick(f32 DeltaTime, Particle* particle) {
	Vector3 force = particle->GetVelocity();
	f32 dragCoefficient = force.GetLength();
	dragCoefficient = Drag * dragCoefficient + DragSquared * dragCoefficient * dragCoefficient;
	force.Normalize();
	force *= -dragCoefficient;
	particle->AddForce(force);
}