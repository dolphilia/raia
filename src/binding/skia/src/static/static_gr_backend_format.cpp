//
// Created by dolphilia on 2024/01/12.
//

#include "static_gr_backend_format.h"

static std::map<std::string, GrBackendFormat> static_gr_backend_format;

void static_gr_backend_format_delete(const char *key) {
    static_gr_backend_format.erase(key);
}

GrBackendFormat static_gr_backend_format_get(const char *key) {
    return static_gr_backend_format[key];
}

void static_gr_backend_format_set(const char *key, GrBackendFormat value) {
    static_gr_backend_format[key] = value;
}