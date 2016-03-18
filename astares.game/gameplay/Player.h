#ifndef PLAYER_H
#define PLAYER_H

#include "../object/Object.h"

class Player : public Object {
public:
	Player();
	virtual ~Player();

	Player& SetState(int32 newState);
	int32 GetState() const;

	int32 GetId() const;

private:
	static int32 PlayerCount;

protected:
	int32 PlayerId;
	int32 PlayerState;
};


#endif