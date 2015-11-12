#include "BungeeSpringForceGenerator.h"

#include "Particle.h"

BungeeSpringForceGenerator::BungeeSpringForceGenerator(const Vector3& position, float springConstant, float restLength) :
	SpringForceGenerator(position, springConstant, restLength)
{

}

void BungeeSpringForceGenerator::Tick(float DeltaTime, Particle* particle) {
	Vector3 force = particle->GetPosition();
	force -= Position;
	float magnitude = force.GetLength();

	if (magnitude <= RestLength) {
		return;
	}
	else {
		magnitude = SpringConstant * (magnitude - RestLength);
		force.Normalize();
		force *= -magnitude;
		particle->AddForce(force);
	}
}