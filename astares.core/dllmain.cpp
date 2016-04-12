// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "log\CommonLogger.h"
#include <memory>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	std::unique_ptr<ILogger> logger = std::make_unique<CommonLogger>(CommonLogger());
	static const char* moduleName = "Core Module";
	logger->Info("%s", moduleName);
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		logger->Info("(%s) Process Attached", moduleName);
		break;
	case DLL_THREAD_ATTACH:
		logger->Info("(%s) Thread Attached", moduleName);
		break;
	case DLL_THREAD_DETACH:
		logger->Info("(%s) Thread Detached", moduleName);
		break;
	case DLL_PROCESS_DETACH:
		logger->Info("(%s) Process Detached", moduleName);
		break;
	}
	return TRUE;
}

