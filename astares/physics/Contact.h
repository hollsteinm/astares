#ifndef CONTACT_H
#define CONTACT_H

#include "../math/Vector.h"
#include "IPhysicsTickable.h"


class Particle;

class Contact : public IPhysicsTickable{
public:
	Contact(Particle* first, Particle* second);

	virtual void Tick(float DeltaTime) override;

protected:
	float GetSeparatingVelocity();
	void ResolveVelocity(float DeltaTime);
	void ResolveInterpenetration(float DeltaTime);

private:
	Particle* Contacts[2];
	float Restitution;
	Vector3 ContactNormal;
};


#endif