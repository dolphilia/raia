//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_direct_context_direct_context_id.h"

static std::map<std::string, GrDirectContext::DirectContextID> static_gr_direct_context_direct_context_id;

void static_gr_direct_context_direct_context_id_delete(const char *key) {
    static_gr_direct_context_direct_context_id.erase(key);
}

GrDirectContext::DirectContextID static_gr_direct_context_direct_context_id_get(const char *key) {
    return static_gr_direct_context_direct_context_id[key];
}

void static_gr_direct_context_direct_context_id_set(const char *key, GrDirectContext::DirectContextID value) {
    static_gr_direct_context_direct_context_id[key] = value;
}