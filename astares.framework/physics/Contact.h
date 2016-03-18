#ifndef CONTACT_H
#define CONTACT_H

#include "../math/Vector.h"
#include "IPhysicsTickable.h"


class Particle;

class Contact : public IPhysicsTickable{
public:
	Contact(Particle* first, Particle* second);

	virtual void Tick(f32 DeltaTime) override;

protected:
	f32 GetSeparatingVelocity();
	void ResolveVelocity(f32 DeltaTime);
	void ResolveInterpenetration(f32 DeltaTime);

private:
	Particle* Contacts[2];
	f32 Restitution;
	Vector3 ContactNormal;
};


#endif