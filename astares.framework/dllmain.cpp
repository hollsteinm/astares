// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "log\CommonLogger.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	ILogger* logger = new CommonLogger();
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		logger->Info("Process Attached");
		break;
	case DLL_THREAD_ATTACH:
		logger->Info("Thread Attached");
		break;
	case DLL_THREAD_DETACH:
		logger->Info("Thread Detached");
		break;
	case DLL_PROCESS_DETACH:
		logger->Info("Process Detached");
		break;
	}
	delete logger;
	return TRUE;
}

