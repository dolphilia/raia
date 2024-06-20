//
// Created by dolphilia on 2023/09/29.
//

#ifndef RAIA_C_DLFCN_EXPORT_API_H
#define RAIA_C_DLFCN_EXPORT_API_H

#ifdef _WIN32
#define __WINDOWS__
#endif

#ifdef _WIN64
#define __WINDOWS__
#endif

#ifdef _WINDOWS
#define __WINGUI__
#endif

#ifdef _CONSOLE
#define __WINCUI__
#endif

#ifdef __APPLE__
#include "TargetConditionals.h"
#ifdef TARGET_OS_MAC
#define __MACOS__
#elif TARGET_OS_IPHONE
#define __IOS__
#elif TARGET_IPHONE_SIMULATOR
#define __IOS_SIMULATOR__
#else
#endif
#endif

#ifdef __linux
#define __LINUX__
#endif

#ifdef __WINDOWS__
//#ifdef BUILD_DLL
#define RAIA_API __declspec(dllexport)
//#else
//#define RAIA_API __declspec(dllimport)
//#endif
#else
#define RAIA_API
#endif

#endif //RAIA_C_DLFCN_EXPORT_API_H
