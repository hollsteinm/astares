#ifdef _WIN32
#    define TEMPLATE_EXTERN
#ifdef ASTARESCORE_EXPORTS
#define ASTARESCORE_API __declspec(dllexport)
#else
#define ASTARESCORE_API __declspec(dllimport)
#endif
#else
#    define TEMPLATE_EXTERN extern
#    define ASTARESCORE_EXPORTS
#endif
