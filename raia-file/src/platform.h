//
// Created by dolphilia on 2022/12/10.
//

#ifndef RAIA_CORE_PLATFORM_H
#define RAIA_CORE_PLATFORM_H

#ifdef _WIN32
#define __WIN32__
#define __WINDOWS__
#endif

#ifdef _WIN64
#define __WIN64__
#define __WINDOWS__
#endif

#ifdef _WINDOWS
#define __WINGUI__
#endif

#ifdef _CONSOLE
#define __WINCUI__
#endif

//#ifdef __APPLE__
//#define __MACOS__
//#endif

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

#endif //RAIA_CORE_PLATFORM_H
