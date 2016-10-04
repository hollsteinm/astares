#include "System.h"
#include "ISubsystem.h"
#include "IConfig.h"
#include "IFile.h"
#include <SDL.h>
#include "../log/ILogger.h"
#include "../math/Matrix.h"
#include "../math/Vector.h"
#include "../math/Geometry.h"

using namespace astares;

static const char* CompanyId = "Company";
static const char* ProjectId = "Project";
static const char* NameId = "Name";

ISystem::ISystem()
{}

ISystem::~ISystem()
{}

class System : public ISystem {

private:
	std::vector<ISubsystem*> Subsystems;
	ILogger* logger;

public:
	System::System(ILogger* logger, const std::vector<ISubsystem*>& subSystems) {
		this->logger = logger;

		for (auto sys : subSystems) {
			Subsystems.push_back(sys);
		}

		if (!SDL_Init(SDL_INIT_VIDEO) == 0) {
			if (logger != nullptr) {
				logger->Critical("Failed to initialize SDL: %s", SDL_GetError());
			}
		}
	}

	System::~System() {
		Subsystems.clear();
	}

	void System::Configure(IConfig* config) {
		cstring companyName = "a";
		cstring projectName = "b";

		if (config->HasSection(ProjectId)) {
			if (config->HasSetting(CompanyId)) {
				companyName = config->AsString(CompanyId);
			}

			if (config->HasSetting(NameId)) {
				projectName = config->AsString(NameId);
			}
		}

		auto IFile = IFile::MakeFile("");
		IFile->Init(companyName, projectName);

		for (auto ptr : Subsystems) {
			logger->Info("Configuring %s subsystem", ptr->GetName());
			ptr->Configure(config);
			logger->Info("%s configured", ptr->GetName());
		}
	}

	bool System::Initialize() {
		bool result = true;
		for (auto ptr : Subsystems) {
			bool val = ptr->Initialize(logger);
			if (!val) {
				logger->Critical("Failed to initialize %s subsystem", ptr->GetName());
			}
			else {
				logger->Info("Initialized %s subsystem", ptr->GetName());
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
				logger->Info("Shutting down %s subsystem", ptr->GetName());
			}
			ptr->Shutdown();
			if (logger != nullptr) {
				logger->Info("%s shutdown", ptr->GetName());
			}
		}
		SDL_Quit();
	}
};

ISystem* ISystem::MakeSystem(ILogger* logger, const std::vector<ISubsystem*>& subSystems) { 
	return new System(logger, subSystems); 
}