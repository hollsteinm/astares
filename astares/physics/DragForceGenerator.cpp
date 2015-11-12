#include "DragForceGenerator.h"
#include "Particle.h"

DragForceGenerator::DragForceGenerator(float velocityDrag, float velocityDragSquared) :
	Drag(velocityDrag),
	DragSquared(velocityDragSquared)
{

}

void DragForceGenerator::Tick(float DeltaTime, Particle* particle) {
	Vector3 force = particle->GetVelocity();
	float dragCoefficient = force.GetLength();
	dragCoefficient = Drag * dragCoefficient + DragSquared * dragCoefficient * dragCoefficient;
	force.Normalize();
	force *= -dragCoefficient;
	particle->AddForce(force);
}