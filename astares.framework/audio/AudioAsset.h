#ifndef AUDIO_ASSET_H
#define AUDIO_ASSET_H

#include "../object/Object.h"
#include "SoundType.h"

class AudioAsset : public Object {
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

DECL_OBJ_VARIANT(AudioAsset)
DECL_MAP_VARIANT(int64, AudioAsset)

#endif