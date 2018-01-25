#pragma once

// z0rg: TODO  MSVC only ?
#define TRICIBLE_INLINE __inline
#define TRICIBLE_FORCEINLINE __forceinline 

#ifdef IN_EXE
#define TRICIBLE_DLL_EXPORT __declspec(dllimport)
#else
#define TRICIBLE_DLL_EXPORT __declspec(dllexport)
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI2
#define M_PI2 6.28318530718
#endif

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

#define POW2(x) (x * x)