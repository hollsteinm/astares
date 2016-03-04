#ifndef IINPUTSYSTEM_H
#define IINPUTSYSETM_H

#include "../core/ISubsystem.h"
#include "KeyState.h"

struct IInputSystem : public ISubsystem {
	virtual ~IInputSystem(){}

	virtual void AddMapping(int key, String name) = 0;
	virtual void ConsumeKey(int key, KeyState state) = 0;
};

#endif