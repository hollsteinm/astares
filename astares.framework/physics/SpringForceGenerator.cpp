#include "SpringForceGenerator.h"
#include "../math/Vector.h"
#include "Particle.h"

SpringForceGenerator::SpringForceGenerator(const Vector3& position, f32 springConstant, f32 restLength) :
	SpringConstant(springConstant),
	RestLength(restLength),
	Position(position)
{

}

void SpringForceGenerator::Tick(f32 DeltaTime, Particle* particle)  {
	Vector3 force = particle->GetPosition();
	force -= Position;
	f32 magnitude = force.GetLength();
	magnitude = fabsf(magnitude - RestLength);
	magnitude *= SpringConstant;
	force.Normalize();
	force *= -magnitude;
	particle->AddForce(force);
}

void SpringForceGenerator::SetPosition(const Vector3& newPosition) {
	Position = newPosition;
}