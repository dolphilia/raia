//
// Created by dolphilia on 2023/09/29.
//

#ifndef RAIA_C_DLFCN_EXPORT_API_H
#define RAIA_C_DLFCN_EXPORT_API_H

#ifdef __WINDOWS__
#define RAIA_API __declspec(dllexport)
#else
#define RAIA_API
#endif

#endif //RAIA_C_DLFCN_EXPORT_API_H
