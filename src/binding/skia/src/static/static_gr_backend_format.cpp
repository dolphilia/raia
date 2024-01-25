//
// Created by dolphilia on 2024/01/12.
//

#include "static_gr_backend_format.h"

static std::map<int, GrBackendFormat> static_gr_backend_format;
static int static_gr_backend_format_index = 0;

int static_gr_backend_format_make(GrBackendFormat value) {
    static_gr_backend_format[static_gr_backend_format_index] = value;
    static_gr_backend_format_index++;
    return static_gr_backend_format_index - 1;
}

void static_gr_backend_format_delete(int key) {
    static_gr_backend_format.erase(key);
}

GrBackendFormat static_gr_backend_format_get(int key) {
    return static_gr_backend_format[key];
}

void static_gr_backend_format_set(int key, GrBackendFormat value) {
    static_gr_backend_format[key] = value;
}