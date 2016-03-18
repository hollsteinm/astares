#ifdef ASTARES_EXPORTS
#define ASTARES_API __declspec(dllexport)
#else
#define ASTARES_API __declspec(dllimport)
#endif