#include "Particle.h"
#include "../math/Math.h"

const float Particle::NoDamping = 0.999f;

Particle::Particle(const Vector3& velocity, const Vector3& acceleration, const Vector3& position, const float& mass) :
	Particle(velocity, acceleration, position)
{
	SetMass(mass);
}

Particle::Particle(const Vector3& velocity, const Vector3& acceleration, const Vector3& position) :
	Velocity(velocity),
	Acceleration(acceleration),
	Position(position)
{

}

Particle::Particle(const Vector3& velocity, const Vector3& acceleration) :
	Particle(velocity, acceleration, Vector3())
{

}

Particle::Particle(const Vector3& velocity) :
	Particle(velocity, Vector3())
{

}

Particle& Particle::AddForce(const Vector3& force) {
	AccumulatedForce += force;
	return *this;
}

Particle& Particle::SetPosition(const Vector3& newPosition) {
	Position = newPosition;
	return *this;
}

Vector3 Particle::GetPosition() const {
	return Position;
}

Vector3 Particle::GetVelocity() const {
	return Velocity;
}

Vector3 Particle::GetAcceleration() const {
	return Acceleration;
}

Particle& Particle::SetMass(const float& newMass) {
	if (!Math::LargerThanAlmostZero(newMass) || newMass <= 0.0f) {
		MassReciprocal = 0.0f;
	}
	else {
		MassReciprocal = 1.0f / newMass;
	}
	return *this;
}

float Particle::GetMass() const {
	if (IsInfiniteMass()) {
		return FLT_MAX;
	}
	else {
		return 1.0f / MassReciprocal;
	}
}

Particle& Particle::SetGravity(const Vector3& newGravity) {
	Gravity = newGravity;
	return *this;
}

Vector3 Particle::GetGravity() const {
	return Gravity;
}

void Particle::Tick(float DeltaTime) {
	if (IsInfiniteMass()) {
		return;
	}

	Position += Velocity * DeltaTime;
	Vector3 accumulatedAcceleration = Acceleration + AccumulatedForce * MassReciprocal;
	Velocity += accumulatedAcceleration * DeltaTime;
	Velocity *= powf(Damping, DeltaTime);
	AccumulatedForce = Vector3();
}

bool Particle::IsInfiniteMass() const {
	return !Math::LargerThanAlmostZero(MassReciprocal) || MassReciprocal <= 0.0f;
}

float Particle::GetMassReciprocal() const {
	return MassReciprocal;
}

Particle& Particle::SetVelocity(const Vector3& newVelocity) {
	Velocity = newVelocity;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Particle& particle) {
	return out << particle.Position << ' ' 
		<< particle.Velocity << ' ' 
		<< particle.Acceleration << ' ' 
		<< particle.Damping << ' ' 
		<< particle.Gravity << ' '
		<< particle.MassReciprocal << ' ' 
		<< particle.AccumulatedForce;
}

std::istream& operator>>(std::istream& in, Particle& particle) {
	return in >> particle.Position 
		>> particle.Velocity 
		>> particle.Acceleration
		>> particle.Damping
		>> particle.Gravity
		>> particle.MassReciprocal 
		>> particle.AccumulatedForce;
}