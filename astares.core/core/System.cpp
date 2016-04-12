#include "System.h"
#include "ISubsystem.h"
#include "Config.h"
#include "File.h"
#include <SDL.h>
#include "../log/ILogger.h"
#include "../math/Matrix.h"
#include "../math/Vector.h"
#include "../math/Geometry.h"

static const char* CompanyId = "Company";
static const char* ProjectId = "Project";
static const char* NameId = "Name";

System::System(std::shared_ptr<ILogger> logger, const std::vector<std::shared_ptr<ISubsystem>>& subSystems) {
	this->logger = logger;

	for (auto sys : subSystems) {
		Subsystems.push_back(sys);
	}

	if (!SDL_Init(SDL_INIT_VIDEO ) == 0) {
		if (logger != nullptr) {
			logger->Critical("Failed to initialize SDL: %s", SDL_GetError());
		}
	}
}

System::~System() {
	Subsystems.clear();
}

void System::Configure(Config& config) {
	std::string companyName = "a";
	std::string projectName = "b";

	if (config.HasSection(ProjectId)) {
		if (config.HasSetting(CompanyId)) {
			companyName = config.AsString(CompanyId);
		}

		if (config.HasSetting(NameId)) {
			projectName = config.AsString(NameId);
		}
	}

	File::Init(companyName, projectName);

	for (auto ptr : Subsystems) {
		logger->Info("Configuring %s subsystem", ptr->GetName().c_str());
		ptr->Configure(config);
		logger->Info("%s configured", ptr->GetName().c_str());
	}
}

bool System::Initialize() {
	bool result = true;
	for (auto ptr : Subsystems) {
		bool val = ptr->Initialize(logger);
		if (!val) {
			logger->Critical("Failed to initialize %s subsystem", ptr->GetName().c_str());
		}
		else {
			logger->Info("Initialized %s subsystem", ptr->GetName().c_str());
		}
		result &= val;
	}
	return result;
}

bool System::Run() {
	bool stillRunning = true;

	if (stillRunning) {
		for (auto ptr : Subsystems) {
			stillRunning &= ptr->Run();
		}
	}

	return stillRunning;
}

void System::Shutdown() {
	for (auto ptr : Subsystems) {
		if (logger != nullptr) {
			logger->Info("Shutting down %s subsystem", ptr->GetName().c_str());
		}
		ptr->Shutdown();
		if (logger != nullptr) {
			logger->Info("%s shutdown", ptr->GetName().c_str());
		}
	}
	SDL_Quit();
}