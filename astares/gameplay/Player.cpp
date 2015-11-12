#include "Player.h"

int Player::PlayerCount = 0;

Player::Player() {
	PlayerId = PlayerCount++;
	CTOR_REGISTER(Player)
}

Player::~Player() {

}

Player& Player::SetState(int newState) {
	if (newState != PlayerState) {
		PlayerState = newState;
	}
	return *this;
}

int Player::GetState() const {
	return PlayerState;
}

int Player::GetId() const {
	return PlayerId;
}

REFLECTION_BEGIN(Player)
	PARENT(Object)
	PROPERTY(int, PlayerId)
	PROPERTY(int, PlayerState)
REFLECTION_END(Player)