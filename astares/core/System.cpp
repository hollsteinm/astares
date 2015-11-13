#include "System.h"
#include "ISubsystem.h"
#include "Config.h"
#include "File.h"
#include <SDL.h>
#include "../log/ILogger.h"

#include "../reflection/Types.h"
#include "../math/Matrix.h"
#include "../math/Vector.h"
#include "../math/Geometry.h"

static const char* CompanyId = "Company";
static const char* ProjectId = "Project";
static const char* NameId = "Name";

System::System(ILogger* logger, const Array<ISubsystem*>& subSystems) {
	GREEDY_LOAD_CORE_TYPES
	GREEDY_LOAD_GEOMETRY_TYPES
	GREEDY_LOAD_MATRIX_TYPES
	GREEDY_LOAD_VECTOR_TYPES

	this->logger = logger;
	Subsystems = subSystems;	
	if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) == 0) {
		if (logger != nullptr) {
			logger->Critical("Failed to initialize SDL: %s", SDL_GetError());
		}
	}
}

System::~System() {
	for (auto* ptr : Subsystems) {
		delete ptr;
		ptr = nullptr;
	}
	Subsystems.clear();
}

void System::Configure(const Config& config) {
	String companyName = "a";
	String projectName = "b";

	if (config.HasSection(ProjectId)) {
		if (config.HasSetting(CompanyId)) {
			companyName = config.AsString(CompanyId);
		}

		if (config.HasSetting(NameId)) {
			projectName = config.AsString(NameId);
		}
	}

	File::Init(companyName, projectName);

	for (auto* ptr : Subsystems) {
		logger->Info("Configuring %s subsystem", ptr->GetName().c_str());
		ptr->Configure(config);
		logger->Info("%s configured", ptr->GetName().c_str());
	}
}

bool System::Initialize() {
	bool result = true;
	for (auto* ptr : Subsystems) {
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
	for (auto* ptr : Subsystems) {
		stillRunning &= ptr->Run();
	}
	return stillRunning;
}

void System::Shutdown() {
	for (auto* ptr : Subsystems) {
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