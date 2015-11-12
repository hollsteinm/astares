#include "AnchoredSpringForceGenerator.h"
#include "Particle.h"


AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(const Vector3& anchor, float springConstant, float restLength) :
	Anchor(anchor),
	SpringConstant(springConstant),
	RestLength(restLength)
{

}

void AnchoredSpringForceGenerator::Tick(float DeltaTime, Particle* particle) {
	Vector3 force;
	force = particle->GetPosition();
	force -= Anchor;
	float magnitude = force.GetLength();
	magnitude = (RestLength - magnitude) * SpringConstant;
	force.Normalize();
	force *= magnitude;
	particle->AddForce(force);
}