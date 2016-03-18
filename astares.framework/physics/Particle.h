#ifndef PARTICLE_H
#define PARTICLE_H

#include "../math/Vector.h"
#include "IPhysicsTickable.h"



class Particle : public IPhysicsTickable{
public:
	Particle(const Vector3& velocity, const Vector3& acceleration, const Vector3& position, const f32& mass);
	Particle(const Vector3& velocity, const Vector3& acceleration, const Vector3& position);
	Particle(const Vector3& velocity, const Vector3& acceleration);
	Particle(const Vector3& velocity);

	Particle& AddForce(const Vector3& force);

	Particle& SetPosition(const Vector3& newPosition);
	Vector3 GetPosition() const;

	Particle& SetVelocity(const Vector3& newVelocity);
	Vector3 GetVelocity() const;

	Vector3 GetAcceleration() const;

	f32 Damping;

	Particle& SetMass(const f32& newMass);
	f32 GetMass() const;
	f32 GetMassReciprocal() const;

	bool IsInfiniteMass() const;

	Particle& SetGravity(const Vector3& newGravity);
	Vector3 GetGravity() const;

	virtual void Tick(f32 DeltaTime) override;

	friend std::ostream& operator<<(std::ostream& out, const Particle& particle);
	friend std::istream& operator>>(std::istream& in, Particle& particle);

protected:
	Vector3 Position;
	Vector3 Velocity;
	Vector3 Acceleration;

	f32 MassReciprocal;
	Vector3 Gravity;

	Vector3 AccumulatedForce;

	static const f32 NoDamping;
};


#endif