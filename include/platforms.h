//
//  platforms.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/08.
//

#ifndef platforms_h
#define platforms_h

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

#ifdef __APPLE__
#define __MACOS__
#endif

#ifdef __linux
#define __LINUX__
#endif

#endif /* platforms_h */
