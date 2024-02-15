#ifndef DYNAMIC_LIBRARY_LOADER_H
#define DYNAMIC_LIBRARY_LOADER_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <string>

#ifdef __WINDOWS__
#include <windows.h>
#define DLOPEN(file) LoadLibraryA(file)
#define DLSYM(handle, name) GetProcAddress(handle, name)
#define DLCLOSE(handle) FreeLibrary(handle)
#else
#include <dlfcn.h>
#define DLOPEN(file) dlopen(file, RTLD_LAZY)
#define DLSYM(handle, name) dlsym(handle, name)
#define DLCLOSE(handle) dlclose(handle)
#endif

using CallableFunc = const char*(*)(const char *json);

struct FuncInfo {
    std::string funcName;
    CallableFunc funcPtr;
};

struct LibraryInfo {
    int id;
    void* handle;
    std::map<std::string, FuncInfo> funcMap;
};

extern std::map<int, LibraryInfo> libraries;
extern std::set<int> deletedKeys;

extern "C" {
void freeSharedLibrary(void);
int addSharedLibrary(const char* library_name);
void* findSharedLibrary(int library_key);
void deleteSharedLibrary(int library_key);
void addFuncSharedLibrary(int library_key, const char *func_name, CallableFunc func);
const char* callFuncSharedLibrary(int library_key, const char *func_name, const char *json);
CallableFunc findFuncSharedLibrary(int library_key, const char *func_name);
void deleteFuncSharedLibrary(int library_key, const char *func_name);
}

#endif // DYNAMIC_LIBRARY_LOADER_H
