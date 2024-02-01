//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_direct_context_direct_context_id.h"

static std::set<int> static_gr_direct_context_direct_context_id_available_keys;
static std::map<int, GrDirectContext::DirectContextID> static_gr_direct_context_direct_context_id;
static int static_gr_direct_context_direct_context_id_index = 0;

int static_gr_direct_context_direct_context_id_make(GrDirectContext::DirectContextID value) {
    int key;
    if (!static_gr_direct_context_direct_context_id_available_keys.empty()) {
        auto it = static_gr_direct_context_direct_context_id_available_keys.begin();
        key = *it;
        static_gr_direct_context_direct_context_id_available_keys.erase(it);
    } else {
        key = static_gr_direct_context_direct_context_id_index++;
    }
    static_gr_direct_context_direct_context_id[key] = value;
    return key;
}

void static_gr_direct_context_direct_context_id_delete(int key) {
    static_gr_direct_context_direct_context_id.erase(key);
    static_gr_direct_context_direct_context_id_available_keys.insert(key);
}

GrDirectContext::DirectContextID static_gr_direct_context_direct_context_id_get(int key) {
    return static_gr_direct_context_direct_context_id[key];
}

void static_gr_direct_context_direct_context_id_set(int key, GrDirectContext::DirectContextID value) {
    static_gr_direct_context_direct_context_id[key] = value;
}