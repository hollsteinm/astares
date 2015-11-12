#include "AudioTests.h"
#include "../IAudioSystem.h"
#include "../SDLWAVAudioSystem.h"
#include "../AudioAsset.h"
#include "../../reflection/Types.h"
#include "../../core/Config.h"
#include "../../core/System.h"
#include "../../log/CommonLogger.h"
#include "../../core/AssetManager.h"
#include <SDL.h>

void test::audio::Console() {
	CommonLogger logger;
	AssetManager* manager = new AssetManager();
	manager->SetLogger(&logger);

	IAudioSystem* sys = new SDLWAVAudioSystem(manager);

	std::vector<ISubsystem*> subs{
		sys
	};

	Config cfg("");

	System system(&logger, subs);
	system.Configure(cfg);

	long id = -1;
	AudioAsset* assetPtr = nullptr;
	if (system.Initialize()){
		assetPtr = sys->AddAsset(TYPEOF(SFXAudioAsset), "someaudio.wav");
		if (assetPtr != nullptr) {
			id = assetPtr->GetAssetId();
			sys->PlayAudio(assetPtr->GetAssetId());
			SDL_Delay(15000);
		}
	}

	manager->WriteRegistryToDisk("tests.assets");

	system.Shutdown();
	subs.clear();
	delete manager;
	delete sys;
	delete assetPtr;
	assetPtr = nullptr;

	system = System(&logger, {});
	manager = new AssetManager();
	manager->SetLogger(&logger);
	sys = new SDLWAVAudioSystem(manager);
	sys->Initialize(&logger);

	manager->LoadRegistryFromDisk("tests.assets");

	if (id >= 0) {
		sys->PlayAudio(id);
		SDL_Delay(15000);
	}

	delete manager;
	delete sys;

}