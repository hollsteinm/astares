#ifndef IINPUTSYSTEM_H
#define IINPUTSYSETM_H

#include "../core/ISubsystem.h"
#include "KeyState.h"

struct IInputSystem : public ISubsystem {
	virtual ~IInputSystem(){}

	virtual void AddMapping(int32 key, std::string name) = 0;
	virtual void ConsumeKey(int32 key, KeyState state) = 0;
};

#endif