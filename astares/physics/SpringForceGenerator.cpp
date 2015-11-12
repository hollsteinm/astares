#include "SpringForceGenerator.h"
#include "../math/Vector.h"
#include "Particle.h"

SpringForceGenerator::SpringForceGenerator(const Vector3& position, float springConstant, float restLength) :
	SpringConstant(springConstant),
	RestLength(restLength),
	Position(position)
{

}

void SpringForceGenerator::Tick(float DeltaTime, Particle* particle)  {
	Vector3 force = particle->GetPosition();
	force -= Position;
	float magnitude = force.GetLength();
	magnitude = fabsf(magnitude - RestLength);
	magnitude *= SpringConstant;
	force.Normalize();
	force *= -magnitude;
	particle->AddForce(force);
}

void SpringForceGenerator::SetPosition(const Vector3& newPosition) {
	Position = newPosition;
}