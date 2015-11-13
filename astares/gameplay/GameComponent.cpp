#include "GameComponent.h"

ComponentTickConfig::ComponentTickConfig() :
	bTicks(false),
	bRenders(false),
	bPhsyics(false),
	bAudio(false),
	bCollsion(false),
	bNetwork(false)
{}

std::ostream& operator<<(std::ostream& out, ComponentTickConfig& self) {
	out << self.Pack();
	return out;
}

std::istream& operator>>(std::istream& in, ComponentTickConfig& self) {
	int package;
	in >> package;
	self.Unpack(package);
	return in;
}

int ComponentTickConfig::Pack() const {
	int res = 0;
	res |= (int)bTicks;
	res |= (int)(bRenders << 1);
	res |= (int)(bPhsyics << 2);
	res |= (int)(bAudio << 3);
	res |= (int)(bCollsion << 4);
	res |= (int)(bNetwork << 5);
	return res;
}

void ComponentTickConfig::Unpack(int value) {
	bTicks = (value & 1) > 0;
	bRenders = (value & 2) > 0;
	bPhsyics = (value & 4) > 0;
	bAudio = (value & 8) > 0;
	bNetwork = (value & 16) > 0;
}

GameComponent::GameComponent() :
	Owner(nullptr),
	bActive(false)
{
	CTOR_REGISTER(GameComponent)
}

GameComponent::~GameComponent() {

}

GameComponent::GameComponent(Object* owner) :
	bActive(true)
{
	Owner.Set(owner);
}

void GameComponent::StartPlay() {

}

void GameComponent::Update(float DeltaTime, UpdateType updateType) {
	if (bActive) {
		switch (updateType)
		{
		case UpdateType::Tick:
			TickUpdate(DeltaTime);
			break;
		case UpdateType::Render:
			RenderUpdate(DeltaTime);
			break;
		case UpdateType::Physics:
			PhysicsUpdate(DeltaTime);
			break;
		case UpdateType::Audio:
			AudioUpdate(DeltaTime);
			break;
		case UpdateType::Collision:
			CollisionUpdate(DeltaTime);
			break;
		case UpdateType::Network:
			NetworkUpdate(DeltaTime);
			break;
		default:
			break;
		}
	}
}

void GameComponent::TickUpdate(float DeltaTime){

}
void GameComponent::RenderUpdate(float DeltaTime){

}
void GameComponent::PhysicsUpdate(float DeltaTime){

}
void GameComponent::AudioUpdate(float DeltaTime){

}
void GameComponent::CollisionUpdate(float DeltaTime){

}
void GameComponent::NetworkUpdate(float DeltaTime){

}

void GameComponent::EndPlay(){

}

void GameComponent::SetActive(bool NewActive){
	bActive = NewActive;
}

bool GameComponent::IsActive() const {
	return bActive;
}

bool GameComponent::DoesTick() const {
	return TickConfig.bTicks;
}

bool GameComponent::DoesRender() const {
	return TickConfig.bRenders;
}

bool GameComponent::DoesPhysics() const {
	return TickConfig.bPhsyics;
}

bool GameComponent::DoesAudio() const {
	return TickConfig.bAudio;
}

bool GameComponent::DoesCollision() const {
	return TickConfig.bCollsion;
}

bool GameComponent::DoesNetwork() const {
	return TickConfig.bNetwork;
}

const ObjectPtr<Object>& GameComponent::GetOwner() const {
	return Owner;
}

REFLECTION_BEGIN(GameComponent)
	PARENT(Object)
	FIELD_PARAMS(ObjectPtr<Object>, Owner, PROP_FLAG_SERIALIGNORE);
	FIELD(ComponentTickConfig, TickConfig);
	FIELD(bool, bActive);
REFLECTION_END(GameComponent)