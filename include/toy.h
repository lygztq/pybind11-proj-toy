#ifndef TOY_DLL
#ifdef _WIN32
#ifdef TOY_EXPORTS
#define TOY_DLL __declspec(dllexport)
#else
#define TOY_DLL __declspec(dllimport)
#endif
#else
#define TOY_DLL
#endif
#endif

TOY_DLL float sigmoid(float f);
