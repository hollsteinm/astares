#ifndef PLAYER_H
#define PLAYER_H

#include "../reflection/Reflection.h"

DECL_CLASS_BASE(Player) {
	DECL_BODY(Player)
public:

	Player& SetState(int newState);
	int GetState() const;

	int GetId() const;

private:
	static int PlayerCount;

protected:
	int PlayerId;
	int PlayerState;
};


#endif