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
	int32 package;
	in >> package;
	self.Unpack(package);
	return in;
}

int32 ComponentTickConfig::Pack() const {
	int32 res = 0;
	res |= (int32)bTicks;
	res |= (int32)(bRenders << 1);
	res |= (int32)(bPhsyics << 2);
	res |= (int32)(bAudio << 3);
	res |= (int32)(bCollsion << 4);
	res |= (int32)(bNetwork << 5);
	return res;
}

void ComponentTickConfig::Unpack(int32 value) {
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
}

GameComponent::~GameComponent() {

}

GameComponent::GameComponent(Object* owner) :
	bActive(true),
	Owner(owner)
{
}

void GameComponent::StartPlay() {

}

void GameComponent::Update(f32 DeltaTime, UpdateType updateType) {
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

void GameComponent::TickUpdate(f32 DeltaTime){

}
void GameComponent::RenderUpdate(f32 DeltaTime){

}
void GameComponent::PhysicsUpdate(f32 DeltaTime){

}
void GameComponent::AudioUpdate(f32 DeltaTime){

}
void GameComponent::CollisionUpdate(f32 DeltaTime){

}
void GameComponent::NetworkUpdate(f32 DeltaTime){

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

const std::weak_ptr<Object> GameComponent::GetOwner() const {
	return Owner;
}