#include "AnchoredSpringForceGenerator.h"
#include "Particle.h"


AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(const Vector3& anchor, f32 springConstant, f32 restLength) :
	Anchor(anchor),
	SpringConstant(springConstant),
	RestLength(restLength)
{

}

void AnchoredSpringForceGenerator::Tick(f32 DeltaTime, Particle* particle) {
	Vector3 force;
	force = particle->GetPosition();
	force -= Anchor;
	f32 magnitude = force.GetLength();
	magnitude = (RestLength - magnitude) * SpringConstant;
	force.Normalize();
	force *= magnitude;
	particle->AddForce(force);
}