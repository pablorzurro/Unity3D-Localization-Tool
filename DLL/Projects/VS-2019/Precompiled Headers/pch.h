// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// Add headers that you want to pre-compile here
#include "targetver.h"
#include "framework.h"

#include <Declarations.hpp>
#include <Utilities.hpp>

#include <Interface.hpp>

#ifdef LOCALIZATIONTOOL_EXPORTS
#define LOCALIZATION_TOOL_API __declspec(dllexport)
#else
#define LOCALIZATION_TOOL_API __declspec(dllimport)
#endif


#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#endif // !PCH_H
