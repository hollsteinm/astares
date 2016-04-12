#include "catch.hpp"
#include <audio\SDLWAVAudioSystem.h>
#include <core\Config.h>
#include <log\CommonLogger.h>
#ifdef _WIN32
#include <Windows.h>
#endif

TEST_CASE("audio", "[framework]") {
	std::shared_ptr<IAudioSystem> sys(new SDLWAVAudioSystem());
	std::shared_ptr<ILogger> logger(std::make_shared<CommonLogger>(CommonLogger()));
	Config config("");
	SECTION("Playing audio") {
		sys->Configure(config);
		bool success = false;
		if (sys->Initialize(logger))
		{
			auto id = sys->AddAsset("C:\\Users\\mhollstein\\Downloads\\testping.wav");
			REQUIRE_FALSE(id == -1);
			sys->PlayAudio(id);
#ifdef _WIN32
			Sleep(6000);
#endif
			success = true;
		}
		REQUIRE(success);
	}

	SECTION("Audio format support"){
		REQUIRE(sys->Supported(".wav"));
		REQUIRE_FALSE(sys->Supported(".mp3"));
	}
}