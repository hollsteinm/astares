#include "Player.h"

int32 Player::PlayerCount = 0;

Player::Player() {
	PlayerId = PlayerCount++;
}

Player::~Player() {

}

Player& Player::SetState(int32 newState) {
	if (newState != PlayerState) {
		PlayerState = newState;
	}
	return *this;
}

int32 Player::GetState() const {
	return PlayerState;
}

int32 Player::GetId() const {
	return PlayerId;
}