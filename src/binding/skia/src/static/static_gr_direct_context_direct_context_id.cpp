//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_direct_context_direct_context_id.h"

static std::map<int, GrDirectContext::DirectContextID> static_gr_direct_context_direct_context_id;
static int static_gr_direct_context_direct_context_id_index = 0;

int static_gr_direct_context_direct_context_id_make(GrDirectContext::DirectContextID value) {
    static_gr_direct_context_direct_context_id[static_gr_direct_context_direct_context_id_index] = value;
    static_gr_direct_context_direct_context_id_index++;
    return static_gr_direct_context_direct_context_id_index - 1;
}

void static_gr_direct_context_direct_context_id_delete(int key) {
    static_gr_direct_context_direct_context_id.erase(key);
}

GrDirectContext::DirectContextID static_gr_direct_context_direct_context_id_get(int key) {
    return static_gr_direct_context_direct_context_id[key];
}

void static_gr_direct_context_direct_context_id_set(int key, GrDirectContext::DirectContextID value) {
    static_gr_direct_context_direct_context_id[key] = value;
}