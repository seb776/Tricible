#pragma once

// z0rg: TODO  MSVC only ?
#define TRICIBLE_INLINE __inline
#define TRICIBLE_FORCEINLINE __forceinline 

#ifdef IN_EXE
#define TRICIBLE_DLL_EXPORT __declspec(dllimport)
#else
#define TRICIBLE_DLL_EXPORT __declspec(dllexport)
#endif