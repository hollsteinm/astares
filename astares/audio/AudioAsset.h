#ifndef AUDIO_ASSET_H
#define AUDIO_ASSET_H

#include "../reflection/Reflection.h"
#include "../core/Asset.h"
#include "../core/String.h"

DECL_CLASS(AudioAsset) : public Asset{
	DECL_BODY(AudioAsset)

public:
	int Volume;
	bool Loops;
	int LoopCount;
	String Filename;

protected:
	virtual void PostDeserialize(std::istream& in) override;
};

DECL_CLASS(MusicAudioAsset) : public AudioAsset{
	DECL_BODY(MusicAudioAsset)
public:
	virtual bool ImportFromFile(String filename) override;
	struct _Mix_Music* Data;
};

DECL_CLASS(SFXAudioAsset) : public AudioAsset{
	DECL_BODY(SFXAudioAsset)
public:
	virtual bool ImportFromFile(String filename) override;
	struct Mix_Chunk* Data;
};

#endif