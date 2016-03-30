#include "AudioAsset.h"
#include "../reflection/Reflection.h"

AudioAsset::AudioAsset() :
	Loops(false),
	LoopCount(0),
	Volume(100),
	Length(0),
	Channel(-1),
	Type(SoundType::SFX)
{
	Name = ToString();
}

AudioAsset::~AudioAsset() {

}

START_PROPERTIES(AudioAsset)
PARENT(Object)
PROPERTY(Loops)
PROPERTY(LoopCount)
PROPERTY(Volume)
PROPERTY(Length)
PROPERTY(Name)
PROPERTY(Type)
PROPERTY(Channel)
END_PROPERTIES

START_SERIAL(AudioAsset)
PARENT_SERIAL(Object)
WRITE(Loops)
WRITE(LoopCount)
WRITE(Length)
WRITE(StringHelper::Encode(Name));
WRITE(Type)
WRITE(Channel)
WRITE(rawData)
END_SERIAL

START_DESERIAL(AudioAsset)
PARENT_DESERIAL(Object)
READ(Loops)
READ(LoopCount)
READ(Length)
READ(Name)
READ(Type)
READ(Channel)
READ(rawData)
StringHelper::MakeDecoded(Name);
END_DESERIAL