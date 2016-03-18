#include "Contact.h"
#include "Particle.h"
#include "../math/Math.h"

static inline f32 ScalarMultiply(const Vector3& lhs, const Vector3& rhs) {
	return lhs[_X] * rhs[_X] +
		lhs[_Y] * rhs[_Y] +
		lhs[_Z] * rhs[_Z];
}

Contact::Contact(Particle* first, Particle* second) :
	Restitution(0.0f),
	ContactNormal(0.0f)
{
	Contacts[0] = first;
	Contacts[1] = second;
}

void Contact::Tick(f32 DeltaTime) {

}

f32 Contact::GetSeparatingVelocity() {
	if (Contacts[0] == nullptr) return 0.0f;

	Vector3 relativeVelocity = Contacts[0]->GetVelocity();

	if (Contacts[1] != nullptr) {
		relativeVelocity -= Contacts[1]->GetVelocity();
	}

	return ScalarMultiply(relativeVelocity, ContactNormal);
}

void Contact::ResolveVelocity(f32 DeltaTime) {
	f32 separatingVelocity = GetSeparatingVelocity();

	if (separatingVelocity > 0.0f || !Math::LargerThanAlmostZero(separatingVelocity)) {
		return;
	}
	else {
		f32 newSepVelocity = -separatingVelocity * Restitution;

		Vector3 accCausedVelocity = Contacts[0]->GetAcceleration();
		if (Contacts[1] != nullptr) {
			accCausedVelocity -= Contacts[1]->GetAcceleration();
		}

		f32 accCausedSepVelocity = ScalarMultiply(accCausedVelocity, ContactNormal) * DeltaTime;

		if (accCausedSepVelocity < 0)
		{
			newSepVelocity += Restitution * accCausedSepVelocity;
			if (newSepVelocity < 0) {
				newSepVelocity = 0;
			}
		}

		f32 deltaVelocity = newSepVelocity - separatingVelocity;

		f32 totalInverseMass = Contacts[0]->GetMassReciprocal();
		if (Contacts[1] != nullptr){
			totalInverseMass += Contacts[1]->GetMassReciprocal();
		}

		if (totalInverseMass <= 0) return;

		f32 impulse = deltaVelocity / totalInverseMass;

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

void Contact::ResolveInterpenetration(f32 DeltaTime) {

}