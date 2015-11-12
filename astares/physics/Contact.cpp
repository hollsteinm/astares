#include "Contact.h"
#include "Particle.h"
#include "../math/Math.h"

static inline float ScalarMultiply(const Vector3& lhs, const Vector3& rhs) {
	return lhs[X] * rhs[X] +
		lhs[Y] * rhs[Y] +
		lhs[Z] * rhs[Z];
}

Contact::Contact(Particle* first, Particle* second) :
	Restitution(0.0f),
	ContactNormal(0.0f)
{
	Contacts[0] = first;
	Contacts[1] = second;
}

void Contact::Tick(float DeltaTime) {

}

float Contact::GetSeparatingVelocity() {
	if (Contacts[0] == nullptr) return 0.0f;

	Vector3 relativeVelocity = Contacts[0]->GetVelocity();

	if (Contacts[1] != nullptr) {
		relativeVelocity -= Contacts[1]->GetVelocity();
	}

	return ScalarMultiply(relativeVelocity, ContactNormal);
}

void Contact::ResolveVelocity(float DeltaTime) {
	float separatingVelocity = GetSeparatingVelocity();

	if (separatingVelocity > 0.0f || !Math::LargerThanAlmostZero(separatingVelocity)) {
		return;
	}
	else {
		float newSepVelocity = -separatingVelocity * Restitution;

		Vector3 accCausedVelocity = Contacts[0]->GetAcceleration();
		if (Contacts[1] != nullptr) {
			accCausedVelocity -= Contacts[1]->GetAcceleration();
		}

		float accCausedSepVelocity = ScalarMultiply(accCausedVelocity, ContactNormal) * DeltaTime;

		if (accCausedSepVelocity < 0)
		{
			newSepVelocity += Restitution * accCausedSepVelocity;
			if (newSepVelocity < 0) {
				newSepVelocity = 0;
			}
		}

		float deltaVelocity = newSepVelocity - separatingVelocity;

		float totalInverseMass = Contacts[0]->GetMassReciprocal();
		if (Contacts[1] != nullptr){
			totalInverseMass += Contacts[1]->GetMassReciprocal();
		}

		if (totalInverseMass <= 0) return;

		float impulse = deltaVelocity / totalInverseMass;

		Vector3 impulsePerIMass = ContactNormal * impulse;

		Contacts[0]->SetVelocity(Contacts[0]->GetVelocity() +
			impulsePerIMass * 
			Contacts[0]->GetMassReciprocal());

		if (Contacts[1] != nullptr)
		{
			Contacts[1]->SetVelocity(Contacts[1]->GetVelocity() +
				impulsePerIMass * 
				-Contacts[1]->GetMassReciprocal());
		}
	}
}

void Contact::ResolveInterpenetration(float DeltaTime) {

}