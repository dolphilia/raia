#include "dynamic_library_loader.hpp"

std::map<int, LibraryInfo> libraries;
std::set<int> deletedKeys;

void displayError(const char *context) {
#ifdef __WINDOWS__
    DWORD dw = GetLastError();
    LPVOID lpMsgBuf;
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                  NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0, NULL);
    std::cerr << "Error in " << context << ": " << static_cast<char*>(lpMsgBuf) << std::endl;
    LocalFree(lpMsgBuf);
#else
    std::cerr << "Error in " << context << ": " << dlerror() << std::endl;
#endif
}

extern "C" {

void freeSharedLibrary(void) {
    for (auto& lib : libraries) {
        DLCLOSE(lib.second.handle);
    }
    libraries.clear();
    deletedKeys.clear();
}

int addSharedLibrary(const char* library_name) {
    std::string fullPath = "./";
    fullPath += library_name;
    void* handle = DLOPEN(fullPath.c_str());

    if (!handle) {
        displayError("open_shared_library");
        return -1;
    }

    int key = deletedKeys.empty() ? static_cast<int>(libraries.size()) + 1 : *deletedKeys.begin();
    deletedKeys.erase(key);

    libraries[key] = {key, handle, {}};
    return key;
}

void* findSharedLibrary(int library_key) {
    auto it = libraries.find(library_key);
    if (it != libraries.end()) {
        return it->second.handle;
    }
    return nullptr;
}

void deleteSharedLibrary(int library_key) {
    auto it = libraries.find(library_key);
    if (it != libraries.end()) {
        DLCLOSE(it->second.handle);
        libraries.erase(it);
        deletedKeys.insert(library_key);
    }
}

void addFuncSharedLibrary(int library_key, const char *func_name, CallableFunc func) {
    auto libIt = libraries.find(library_key);
    if (libIt != libraries.end()) {
        libIt->second.funcMap[func_name] = {func_name, func};
    }
}

const char* callFuncSharedLibrary(int library_key, const char *func_name, const char *json) {
    auto libIt = libraries.find(library_key);
    if (libIt != libraries.end()) {
        auto& funcMap = libIt->second.funcMap;
        auto funcIt = funcMap.find(func_name);
        if (funcIt != funcMap.end()) {
            return funcIt->second.funcPtr(json);
        }
    }
    return nullptr;
}

CallableFunc findFuncSharedLibrary(int library_key, const char *func_name) {
    auto libIt = libraries.find(library_key);
    if (libIt != libraries.end()) {
        auto& funcMap = libIt->second.funcMap;
        auto funcIt = funcMap.find(func_name);
        if (funcIt != funcMap.end()) {
            return funcIt->second.funcPtr;
        }
    }
    return nullptr;
}

void deleteFuncSharedLibrary(int library_key, const char *func_name) {
    auto libIt = libraries.find(library_key);
    if (libIt != libraries.end()) {
        auto& funcMap = libIt->second.funcMap;
        auto funcIt = funcMap.find(func_name);
        if (funcIt != funcMap.end()) {
            funcMap.erase(funcIt);
        }
    }
}

}