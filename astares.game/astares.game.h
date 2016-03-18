// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ASTARESGAME_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ASTARESGAME_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ASTARESGAME_EXPORTS
#define ASTARESGAME_API __declspec(dllexport)
#else
#define ASTARESGAME_API __declspec(dllimport)
#endif

// This class is exported from the astares.game.dll
class ASTARESGAME_API Castaresgame {
public:
	Castaresgame(void);
	// TODO: add your methods here.
};

extern ASTARESGAME_API int nastaresgame;

ASTARESGAME_API int fnastaresgame(void);
