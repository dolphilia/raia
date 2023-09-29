#include "raia_cpp_dlfcn.h"

using json_t = nlohmann::json;

const char *json_to_cstr(json_t j) {
    std::string str = j.dump();
    char* result = new char[str.length()];
    std::strncpy(result, str.c_str(), str.length());
    return result;
}

const char *string_to_cstr(const std::string& str) {
    char* result = new char[str.length()];
    std::strncpy(result, str.c_str(), str.length());
    return result;
}

extern "C" {

RAIA_API const char *raia_dlfcn_dlopen(const char *args) {
    json_t json = json_t::parse(args);
    auto path = json["path"].get<std::string>();
    raia_dl_handle_t handle = raia_dlopen(path.c_str());
    json["result"] = (uint64_t)(uintptr_t)handle;
    return string_to_cstr(json["result"].get<std::string>());
}

RAIA_API const char *raia_dlfcn_dlclose(const char *args) {
    json_t json = json_t::parse(args);
    raia_dl_handle_t handle = (raia_dl_handle_t)json["handle"].get<uintptr_t>();
    int result = raia_dlclose(handle);
    json["result"] = result;
    return string_to_cstr(json["result"].get<std::string>());
}

RAIA_API const char *raia_dlfcn_dlsym(const char *args) {
    json_t json = json_t::parse(args);
    raia_dl_handle_t handle = (raia_dl_handle_t)json["handle"].get<uintptr_t>();
    std::string symbol = json["symbol"].get<std::string>();
    void *result = raia_dlsym(handle, symbol.c_str());
    json["result"] = (uint64_t)(uintptr_t)result;
    return string_to_cstr(json["result"].get<std::string>());
}

}

//int main() {
//    return 0;
//}