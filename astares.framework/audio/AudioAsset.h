#ifndef AUDIOASSET_H
#define AUDIOASSET_H

#include "../object/Object.h"
#include "SoundType.h"

DECL_API_STL(ASTARESFRAMEWORK_API, uint8)

class ASTARESFRAMEWORK_API AudioAsset : public Object 
{
public:
	AudioAsset();
	~AudioAsset();

	int32 Volume;
	int32 Length;
	gate Loops;
	int32 LoopCount;
	string Name;
	SoundType Type;
	int8 Channel;
	vector<uint8> rawData;

protected:
	REFLECTABLE
	SERIALIZEABLE(AudioAsset)
};

DECL_OBJECT_VARIANT(AudioAsset)
DECL_MAP_VARIANT(int64, AudioAsset)

#endif